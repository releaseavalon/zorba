/*
 * Copyright 2006-2016 zorba.io
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include <cstring>

#include <zorba/diagnostic_list.h>

#include "diagnostics/xquery_exception.h"
#include "runtime/datetime/datetime.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/ascii_util.h"
#include "util/time_parse.h"
#include "util/time_util.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

enum parse_type {
  parse_date,
  parse_time,
  parse_dateTime
};

///////////////////////////////////////////////////////////////////////////////

static void parse( parse_type parse_what, zstring const &buf,
                   zstring const &fmt, iso639_1::type lang,
                   iso3166_1::type country, time::ztm *tm,
                   QueryLoc const &loc ) {
  try {
    unsigned set_fields;
    ::memset( tm, 0, sizeof( *tm ) );
    time::parse( buf, fmt, lang, country, tm, &set_fields );

    bool       set_mday = !!(set_fields & time::set_mday);
    bool       set_mon  = !!(set_fields & time::set_mon);
    bool const set_yday = !!(set_fields & time::set_yday);
    bool const set_year = !!(set_fields & time::set_year);

    if ( set_yday && set_year && (!set_mday || !set_mon) ) {
      //
      // Given yday and year, "back fill" mday and/or mon.
      //
      time::calc_mday_mon(
        tm->tm_yday, 
        set_mday ? nullptr : reinterpret_cast<unsigned*>( &tm->tm_mday ),
        set_mon  ? nullptr : reinterpret_cast<unsigned*>( &tm->tm_mon ),
        tm->tm_year
      );
      set_mday = set_mon = true;
    }

    switch ( parse_what ) {
      case parse_date:
        if ( set_mday && set_mon && set_year )
          return;
        break;
      case parse_dateTime:
        if ( !(set_mday && set_mon && set_year) )
          break;
        // no break;
      case parse_time:
        if ( !(set_fields & time::set_hour) )
          break;
        if ( !(set_fields & time::set_min) )
          tm->tm_min = 0;
        if ( !(set_fields & time::set_sec) )
          tm->tm_sec = 0;
        if ( !(set_fields & time::set_gmtoff) )
          tm->ZTM_GMTOFF = 0;
        return;
    }

    throw XQUERY_EXCEPTION(
      dt::INCOMPLETE_DATE_OR_TIME,
      ERROR_PARAMS( fmt ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::insufficient_buffer const& ) {
    throw XQUERY_EXCEPTION(
      dt::INSUFFICIENT_BUFFER,
      ERROR_PARAMS( buf, fmt ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::invalid_specification const &e ) {
    throw XQUERY_EXCEPTION(
      dt::INVALID_SPECIFICATION,
      ERROR_PARAMS( ascii::printable_char( e.get_spec() ) ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::invalid_value const &e ) {
    throw XQUERY_EXCEPTION(
      dt::INVALID_VALUE,
      ERROR_PARAMS( e.get_value(), e.get_specs() ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::literal_mismatch const &e ) {
    throw XQUERY_EXCEPTION(
      dt::LITERAL_MISMATCH,
      ERROR_PARAMS(
        ascii::printable_char( e.get_got() ),
        ascii::printable_char( e.get_expected() )
      ),
      ERROR_LOC( loc )
    );
  }
}

static void parse_locale( store::Item_t const &item, iso639_1::type *lang,
                          iso3166_1::type *country,
                          QueryLoc const &loc ) {
  zstring locale_str;
  item->getStringValue2( locale_str );
  if ( !locale::parse( locale_str, lang, country ) )
    throw XQUERY_EXCEPTION(
      dt::INVALID_LOCALE,
      ERROR_PARAMS( locale_str ),
      ERROR_LOC( loc )
    );
  if ( !*lang || !*country )
    throw XQUERY_EXCEPTION(
      dt::UNKNOWN_LOCALE,
      ERROR_PARAMS( locale_str ),
      ERROR_LOC( loc )
    );
  if ( !locale::is_supported( *lang, *country ) )
    throw XQUERY_EXCEPTION(
      dt::UNSUPPORTED_LOCALE,
      ERROR_PARAMS( locale_str ),
      ERROR_LOC( loc )
    );
}

///////////////////////////////////////////////////////////////////////////////

bool CurrentDate::nextImpl( store::Item_t& result,
                            PlanState &plan_state ) const {
  time::ztm tm;
  time::get_gmtime( &tm );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createDate(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool CurrentDateTime::nextImpl( store::Item_t& result,
                                PlanState &plan_state ) const {
  time::sec_type sec;
  time::usec_type usec;
  time::get_epoch( &sec, &usec );
  time::ztm tm;
  time::get_gmtime( &tm, sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createDateTimeStamp(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + usec / 1000000.0,
    static_cast<int>( tm.ZTM_GMTOFF )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool CurrentTime::nextImpl( store::Item_t& result,
                            PlanState &plan_state ) const {
  time::sec_type sec;
  time::usec_type usec;
  time::get_epoch( &sec, &usec );
  time::ztm tm;
  time::get_gmtime( &tm, sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createTime(
    result,
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + usec / 1000000.0,
    static_cast<int>( tm.ZTM_GMTOFF )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool MillisToDateTime::nextImpl( store::Item_t& result,
                                 PlanState &plan_state ) const {
  store::Item_t item;
  xs_long millis;
  time::ztm tm;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  millis = item->getLongValue();

  time::get_gmtime( &tm, static_cast<time::sec_type>( millis / 1000 ) );
  GENV_ITEMFACTORY->createDateTime(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + (millis % 1000) / 1000.0,
    static_cast<int>( tm.ZTM_GMTOFF )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseDate::nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  store::Item_t item;
  zstring buf, fmt;
  iso639_1::type lang;
  iso3166_1::type country;
  time::ztm tm;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChildren[1], plan_state );
  item->getStringValue2( fmt );
  if ( theChildren.size() > 2 ) {
    consumeNext( item, theChildren[2], plan_state );
    parse_locale( item, &lang, &country, loc );
  } else {
    lang = iso639_1::unknown;
    country = iso3166_1::unknown;
  }

  parse( parse_date, buf, fmt, lang, country, &tm, loc );
  GENV_ITEMFACTORY->createDate(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseDateTime::nextImpl( store::Item_t& result,
                              PlanState &plan_state ) const {
  store::Item_t item;
  zstring buf, fmt;
  iso639_1::type lang;
  iso3166_1::type country;
  time::ztm tm;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChildren[1], plan_state );
  item->getStringValue2( fmt );
  if ( theChildren.size() > 2 ) {
    consumeNext( item, theChildren[2], plan_state );
    parse_locale( item, &lang, &country, loc );
  } else {
    lang = iso639_1::unknown;
    country = iso3166_1::unknown;
  }

  parse( parse_dateTime, buf, fmt, lang, country, &tm, loc );
  GENV_ITEMFACTORY->createDateTime(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec,
    static_cast<int>( tm.ZTM_GMTOFF )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseTime::nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  store::Item_t item;
  zstring buf, fmt;
  iso639_1::type lang;
  iso3166_1::type country;
  time::ztm tm;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChildren[1], plan_state );
  item->getStringValue2( fmt );
  if ( theChildren.size() > 2 ) {
    consumeNext( item, theChildren[2], plan_state );
    parse_locale( item, &lang, &country, loc );
  } else {
    lang = iso639_1::unknown;
    country = iso3166_1::unknown;
  }

  parse( parse_time, buf, fmt, lang, country, &tm, loc );
  GENV_ITEMFACTORY->createTime(
    result,
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec,
    static_cast<int>( tm.ZTM_GMTOFF )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool Timestamp::nextImpl( store::Item_t& result,
                          PlanState &plan_state ) const {
  time::sec_type sec;
  time::get_epoch( &sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createLong( result, sec );
  STACK_PUSH( true, state );
  STACK_END( state );
}

bool UTCOffset::nextImpl( store::Item_t& result,
                          PlanState &plan_state ) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createLong( result, time::get_gmt_offset() );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
