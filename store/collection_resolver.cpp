/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: collection_resolver.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "collection_resolver.h"

#include <string>

#include "../context/context.h"
#include "../runtime/item_iterator.h"
#include "../util/xqp_exception.h"

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE item_iterator()

item_iterator collection_resolver::resolve(
	string const& base,
	string const& href,
	context& context)
throw (xqp_exception)
{
	return EMPTY_SEQUENCE;
}


} /* namespace xqp */

