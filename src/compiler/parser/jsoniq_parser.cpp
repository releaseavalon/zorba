/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#include "stdafx.h"
// Take the name prefix into account.
#define yylex   zorbalex

/* First part of user declarations.  */

/* Line 293 of lalr1.cc  */
#line 88 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/jsoniq_driver.h"
#include "compiler/parser/parser_helpers.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 293 of lalr1.cc  */
#line 69 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {

/* Line 382 of lalr1.cc  */
#line 185 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  jsoniq_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  jsoniq_parser::jsoniq_parser (jsoniq_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  jsoniq_parser::~jsoniq_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  jsoniq_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  jsoniq_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  jsoniq_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 112: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;

	default:
	  break;
      }
  }

  void
  jsoniq_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  jsoniq_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  jsoniq_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  jsoniq_parser::debug_level_type
  jsoniq_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  jsoniq_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  jsoniq_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  jsoniq_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  jsoniq_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2871 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 3:

/* Line 690 of lalr1.cc  */
#line 1070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1074 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1105 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1125 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1145 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1189 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1229 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1236 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1243 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1265 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1279 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1327 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1420 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1425 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1470 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1490 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1497 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1506 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1519 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1544 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1551 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1587 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1661 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1668 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1676 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1683 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1688 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1696 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1704 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);  // not external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,   // no init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1732 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),     // init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1749 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1754 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1762 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1781 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1786 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1795 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1800 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1807 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1822 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1827 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1855 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1868 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1894 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1906 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2050 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2097 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2109 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2119 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2129 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2140 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2156 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query body should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }

      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2200 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2208 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2213 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2232 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2242 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 2275 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {        
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else if (block == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2305 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2313 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2321 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2335 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2394 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2410 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2425 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2438 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2452 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }

      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2469 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2494 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2509 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2520 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2529 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2541 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2554 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      // Heuristics to improve the error message: if the $1 Expr is a QName (which in turn gets
      // promoted to a PathExpr), chances are that it's not a missing comma, so don't modify
      // the error message.
      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2601 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2628 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2641 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2646 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2654 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2675 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2685 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2698 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2722 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2739 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2745 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2754 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2764 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2772 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2779 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2787 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2799 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2819 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2839 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2859 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2995 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3007 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3042 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3059 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3077 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3084 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3090 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3100 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3108 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3116 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3124 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3144 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3158 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3174 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3188 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3204 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3216 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3225 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3234 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3243 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3260 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3292 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3321 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3337 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3371 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3408 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3417 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3433 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3444 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3451 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3481 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3487 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3498 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3504 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3521 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3532 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3538 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3562 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3599 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3699 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3703 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3725 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3742 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3760 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3772 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3790 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3802 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3808 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3818 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3850 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3864 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 4005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 4016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 4022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 4032 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 4038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4119 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4368 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4372 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4458 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4462 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4466 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4503 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4539 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4555 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4567 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4575 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* argList = dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node));

      if (argList->has_placeholder())
      {
        LiteralFunctionItem* lfi = 
        new LiteralFunctionItem(LOC((yyloc)),
                                dynamic_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                                new Integer(argList->size()));

        (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), lfi, argList, true);
      }
      else
      {
        (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), argList);
      }
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4669 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4681 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4691 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4703 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4711 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4723 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4739 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4751 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4759 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
      {
        error((yylocation_stack_[(8) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                                  NULL,
                                  NULL);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                                  NULL);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4803 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  NULL,
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4822 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
      {
        error((yylocation_stack_[(10) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4850 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4861 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4898 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4918 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4948 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 5013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 5017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 5021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 5043 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5081 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5089 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5094 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5099 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5109 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5125 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5137 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5154 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5174 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5325 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5401 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5432 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5440 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5448 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5452 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5456 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5464 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5474 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5484 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5494 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5502 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5506 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5530 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5536 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5542 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5552 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5569 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 6037 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 6041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 6048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 6060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 6071 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6075 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6095 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6101 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6122 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6137 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6148 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6152 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6160 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6164 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6168 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6172 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6176 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6192 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6216 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6220 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6232 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6238 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6252 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6260 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6264 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6272 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6284 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6288 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6292 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6304 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6330 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6334 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(2) - (2)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(2) - (2)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6352 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(5) - (4)].thesaurus_id_list);
            if ( (yysemantic_stack_[(5) - (3)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(5) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(5) - (3)].node) );
            delete til;
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6363 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6397 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6438 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6558 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6582 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6648 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6659 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6664 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6672 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6677 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6686 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6694 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6701 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6707 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6714 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6725 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6731 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6741 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6746 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6752 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(4) - (2)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6762 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6769 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(2) - (2)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(4) - (2)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(6) - (4)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(6) - (6)].expr));
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 7090 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 7094 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 7095 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 7096 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 7097 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 7099 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 7100 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 7101 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 7102 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 7103 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 7104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 7105 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 7106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 7107 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 7108 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 7109 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 7110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 7111 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 7112 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 7113 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 7114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 7115 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 7116 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 7117 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 7118 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 7119 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 7120 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 7121 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 7122 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 7123 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 7124 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 7125 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 7126 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 7127 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 7128 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 7129 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 7130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 7131 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 7132 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 7133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 7134 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 7135 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 7136 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7137 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7138 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7139 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7140 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7142 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7143 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7144 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7145 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7146 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7147 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7148 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7149 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7150 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7151 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7152 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7153 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7155 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7156 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7158 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7159 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7160 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7161 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7162 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7164 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7167 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7168 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7170 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7171 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7172 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7174 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7175 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7176 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7177 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7178 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7179 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7180 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7181 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7182 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7183 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7186 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7187 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7188 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7189 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7191 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7192 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7193 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7195 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7196 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7197 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7199 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7200 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7201 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7203 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7204 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7205 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7207 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7208 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7209 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7210 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7211 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7212 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7213 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7215 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7216 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7217 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7218 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7219 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7220 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7221 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7222 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7223 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7224 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7227 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7236 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12100 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  jsoniq_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int jsoniq_parser::yypact_ninf_ = -1484;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5031,  8358,  8358,  8358,  8358, -1484, -1484,    28,   234, -1484,
     557,    17, -1484, -1484, -1484,   325, -1484, -1484, -1484,   338,
   -1484,   427,   587,   269,   453,   690, -1484,   -26, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   593, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484,   696, -1484,   667, -1484,   706,   748, -1484,
     279, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484,   816, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   791,
   -1484, -1484, -1484, -1484, -1484, 18522, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484,   809, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,  5647, 10472, 10774, 18522, -1484, -1484,
     821, -1484, -1484, -1484, -1484,   827, -1484, -1484, -1484,  7154,
   -1484,  7452, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,   846, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484,    79,   731,   779, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, 14398, -1484,  5950,
   -1484, 14700,   165, -1484, -1484, -1484, -1484, -1484, -1484,   907,
   -1484,   807,   817,   818, -1484, -1484,   909,   913, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
     778, -1484, 14096, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, 11076, 11378, 11680, -1484,  5339,  7754,  1069, -1484,  8660,
   -1484, -1484,   770,    91, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,    95, -1484,
   -1484, -1484, -1484, -1484, -1484,   340, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,  8358, -1484, -1484, -1484, -1484,   230,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   139,
   -1484,   878, -1484, -1484, -1484,   479, -1484,   720, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   902,   978, -1484, -1484,   839,
     822,   977,    -7,     6,   296,   799, -1484,  1029,   880,   980,
     981, 13190, -1484,   889, -1484, -1484,   463, -1484, -1484, -1484,
   -1484,   766, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   939,   929, -1484, -1484, -1484,
   -1484, -1484,   903, -1484,  8358,   904,   905,   906,  8358,    89,
      89,  1058,   756,   775,   649, 18813, 18522,   516,  1045, 18522,
     940,   975,    87,  7154,   795,   844, 18522, 18522,   787,   242,
      96, -1484, -1484, -1484,  7154,  8358,  8358, 12586,    31,   943,
   12586,  1098,   111,    81, 18522,   982,   956,   992, -1484, 12586,
   18522,  8358, 12586, 12586, 18522,  8358,   948,   950, 12586, 18522,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   960, -1484,
   18522, -1484,   921,  8056,   983,    41,   985,   939,   951,   952,
     953, 18522,  5647, -1484,   957,   147, -1484,   589, -1484,    83,
    1077, 12586, 12586,    93, -1484, -1484, -1484,  1100, 12586,   899,
   -1484,  1088,  1091, 12586, 12888, 15002,   766, 12586, 12888,  6253,
     -20,   -11, 12586, 15002,   651, 12586,   886,   888, 18522,   933,
     934, 12586, 12586,  8358,   881, -1484, -1484,    65, -1484,    60,
   12586,   890,  7754, -1484, -1484, -1484, -1484, -1484,   557,   690,
      98,    99,  1124,  8962,  3470,  9264,  3789,   791, -1484, -1484,
     205,   791, -1484, 12586,  4421, -1484,  1010, -1484,   -26,   961,
     962,   963,  8358, 12586, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, 18522, -1484,   847,   849, 18522,  1013, 13492,
   13492, -1484, -1484, -1484, -1484, -1484, -1484, 13794,  1064, 13794,
   13794, 13794, 13794, 13794, 13794, 13794, 13794, 13794, 13794, 13794,
   13794,   901,  1044,  1046,  1047, -1484, -1484, -1484, 15002, 11982,
   -1484,  6554, 12586,  9868,   988, -1484,   990, 10170, -1484, -1484,
   -1484, -1484,    11, -1484,    34, -1484, -1484, -1484, -1484, -1484,
   -1484,  1036,  1037,   269,  1117, -1484, -1484, 18813,   949,    46,
   18522,   986,   987,   949,  1058,  1021,  1017, -1484, -1484, -1484,
     319,   908,  1059,   851, 18522,  1015, 12586,  1034, 18522, 18522,
   -1484,  1028,   979,   991,   233, 18522,  1068,   352, -1484,  8358,
   -1484,   116, -1484,  7154,  1070,  1120,  7154,  1058,  1071,   702,
   18522, 12586,   -26,   254,    88, -1484,    49,   994,   117,   120,
    1016, -1484,   995,  8358,  8358,   323,   717, 12586,   249, -1484,
   -1484, 12586,  6253, -1484, 12586, 12586, 12586, 12586, -1484, 12586,
   -1484, 12586, -1484, 18522,  1077, -1484,   278,   404,   408, -1484,
   -1484, -1484,   411, -1484,   331,   490, -1484, -1484,   766,   245,
     450,    -8,    21, 12586, 12586,  1078,   751, 12586,   930, 15304,
     941,   123, -1484,  1032, -1484, -1484,   996,   126,  8056,   423,
    4729,   881, -1484, -1484, -1484,   944, 12586, -1484,   770,   843,
    1148,   159, -1484, -1484,   101, -1484, -1484, -1484,   104, -1484,
     342, -1484, -1484, -1484, -1484, -1484,  4105, -1484, -1484, -1484,
   18522,  1012, 12586,  1066, -1484, -1484, -1484,  1081, -1484,    38,
   -1484, -1484,  1081, 18522,    32,   978, -1484, -1484,    58, -1484,
       6,     6,     3,   296,   296,   296,   296,   799,   799, -1484,
   -1484, 17063, 17063, 18522, 18522, -1484, -1484,   428, -1484, -1484,
   -1484, -1484,   229, -1484, -1484, -1484,   378, -1484, -1484, -1484,
     394,    89, -1484, -1484,   216,   312,   742, -1484,   269, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   949,
   -1484,  1053, 17356,  1048, 12586, -1484, -1484, -1484,  1097,  1058,
    1058,   949, -1484,   759,  1058,   736, 18522,   546,   730,  1165,
   -1484, -1484,   910,   602, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   319,   119,   966,   692, 12586,
   -1484, 18522,  1105,   891,  1058, -1484, -1484,  1049,  1097, 17063,
    1085,  1110,  1025,  1007,  1080,  1058,  1050,  1083,  1121,  1058,
   17063, 12586,   -38, -1484, -1484, -1484,  1063,  1101, 12586, 12586,
    1074, -1484,  1122,  1123,  8358, -1484,  1040,  1041,  1076, 12586,
    1089,  1042, 12586, -1484,  1106,  1109, -1484,   127,   156,   157,
    1200, -1484,   366, -1484,   630,  1082, -1484, -1484,  1208, -1484,
    1209, -1484,   -62, 12586, 12586, 12586,   803, 12586, 12586, 12586,
   12586, 12586,  1142, -1484, 12586, 12586, -1484, 12586, 12586,   259,
   15002,  1125, 12586, 12586, -1484,  9566,   112,   993, -1484, -1484,
   -1484, -1484, -1484, -1484,   493, -1484, -1484, 12586, -1484,   106,
     313,   342,  9264,  3789,  9264,  1162, -1484, -1484, 12586,   866,
    1137, -1484, 18522,  1138, -1484, 18231,  1127,  1129, 12586,   -35,
    1102,    54,   438,   997, -1484, -1484,   750,    32, 12586,    58,
     615,   749, -1484,   967,   369,   989,   999, -1484, -1484,   844,
   -1484,   998,   622,  1094,  1096,  1103,  1104,  1108,  1111,  1112,
    1114,  1115,  1116,  1118, 15891,  1119,  1126,  1128,  1130,  1131,
    1134, -1484,   675, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484,  1113, -1484, -1484, -1484,
   -1484, 12284, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484,   838, -1484,  1230, 17356,   610, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   971, -1484, -1484,  1238, -1484,
   -1484, -1484, -1484, -1484,   699,  1248, -1484,   703, -1484, -1484,
   -1484,  1094,  1096,  1103,  1108,  1111,  1112,  1114,  1115,  1116,
    1126, -1484,   675,   675, 15002,  1001,   968, -1484,  1097,   119,
    1052,  1090,  8358, -1484, -1484, -1484, 17063, -1484,  8358,  1058,
    1172, -1484, -1484, -1484,  1058,  1172, -1484, -1484, 12586,  1143,
    8358, 18522, -1484, -1484, 12586, 12586,    73, -1484,   260,   374,
   -1484, 16184,   511, -1484,   753, -1484,  1132, -1484, -1484,  8358,
   -1484, 12586, -1484, -1484, 12586, 12586,  1095,  1122,  1194, -1484,
    1164, -1484,   729, -1484, -1484,  1292, -1484, -1484,  8358, 18522,
   -1484,   755, -1484, -1484, -1484,  8358,  1133,  1135,  1061,  1065,
   -1484, -1484, -1484,  1073,  1075, -1484, -1484, -1484,  1204, -1484,
    1000, -1484, -1484, -1484,  1060, 12586,   532, 18522,  1136, -1484,
    1147,  1149,  1150,  1155, -1484,   878,   655,  4729,   993, -1484,
    9566,  4729, -1484, -1484,  1148,   583, -1484, -1484, -1484,  1137,
   -1484,  1058, -1484,   920, -1484,    48,  1205, -1484, 12586,   723,
    1066, 18522, -1484,    68, 18522, -1484, 12586,  1166, 12586,  1187,
   12586,   194,  1168, 12586,  1170, -1484,  1201,  1203, 12586, 18522,
     836,  1241, -1484, -1484, -1484,   448,  1139, -1484,    58,  1079,
   -1484, -1484,   291, -1484,   737,   173,  1084,    58,   737, 13794,
   -1484,   310, -1484, -1484, -1484, -1484, -1484, -1484,    58,  1177,
    1043,   908,   173, -1484, -1484,  1038,  1249, -1484, -1484, -1484,
    1144,    44, 17649, 15598,  1145,  6854, 18522, 18522,  1156, 17940,
    1157, -1484,  1158,  1159,  1160,  1161,  1163,  1169,  1171, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,  1302,   474,  1306,   474,  1062,  1228, -1484, -1484,
    1179, 18522,  1092, -1484, -1484, 15002, -1484,  1152, -1484,  1216,
    1225,  1256,  1058,  1172, -1484, 12586,  1173, -1484, -1484, -1484,
    1174, -1484,   272, 12586,  8358,  1175,   302, -1484, 18522,   760,
   -1484, 16477,   294, -1484, 16770,  1176, -1484, -1484,  1180, -1484,
   -1484, -1484, 12586,   876,  1200, 18522,   790, -1484,  1181,  1200,
   18522, -1484,  1182, -1484, -1484, 12586, 12586, 12586, 12586,  1035,
   12586, 12586, -1484, 12586, -1484, 12586, 12586, 12586, 12586,  9566,
     502, -1484, -1484, -1484, -1484, -1484,  1205, -1484, -1484, -1484,
    1058, 12586, -1484,  1217, -1484, -1484, 12586,  1220, -1484, -1484,
   12586, -1484,   683, -1484, 12586,  1221, 12586, -1484, 12586, 18522,
   18522, -1484,   848, -1484, 12586, -1484, -1484, -1484,  1185, 13794,
   -1484, -1484, -1484, -1484, -1484,    76, 13794, 13794,   403, -1484,
     989, -1484,   486, -1484,   999,    58,  1210, -1484, -1484,  1086,
   -1484, -1484, -1484, -1484, -1484, -1484,  1184,  1186, -1484,   484,
     492,  1278,  1188, -1484,   508, -1484,  1189, -1484,  1191,  1192,
    1193, -1484, -1484,   510,   535, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,   412,   412, -1484,   474, -1484, -1484,
     585, -1484,  1346,    14,  1281,  1195, 15002,   -27,  1093,  1211,
   -1484,  9566, 12586,  1058, -1484, -1484, -1484, 12586, 12586, -1484,
   -1484, -1484,  9566,  9566,  1289,  8358, 17063, 18522,   767, 18522,
   12586, 18522,   768,  9566, -1484,   327,    37,  1200, 18522, -1484,
    1196,  1200, -1484, -1484, -1484, -1484, -1484, 12586, -1484, -1484,
   -1484, -1484,   160,   198,   213, 12586, -1484, -1484, -1484,  1279,
   12586, -1484, 12586, -1484, 12586,  1239, -1484, 12586, -1484, -1484,
   -1484,  1334, -1484, -1484, -1484,   296, 13794, 13794,     3,   752,
   -1484, -1484, -1484, -1484, -1484, -1484, 12586, -1484, -1484, -1484,
   18522, -1484, 18522, -1484, 17063, -1484, 17063,  1294, -1484, -1484,
   -1484, -1484, 18522, -1484, 18522, -1484, -1484, -1484, -1484,  1361,
   -1484, -1484, -1484,  1140,  1283, -1484, -1484,  1284, -1484,   478,
   18522,  1276,  1167, 18522, 15002, -1484, -1484,  1172, -1484, -1484,
   17063, -1484, -1484, -1484,  1301, 12586,  1212, -1484,  1305,  9566,
   -1484, 18522,   657,   758, -1484,  1206,  1200, -1484,  1207, -1484,
    1202,  1122,  1123,   464, -1484,  1279, -1484, -1484, 12586, -1484,
    1290,     3,     3, 13794,   470,  1214,  1215,  1263,  1223,  1224,
   -1484, -1484, 17063,  1226,  1227, -1484, -1484,  1281, 15002, -1484,
    1205,  1107, 18522,  1297,  1183,  1284,   774, 17063,  8358, 17063,
    1231, -1484, -1484,  1325,   724, -1484, -1484, -1484, -1484,  1236,
     833, -1484, -1484, -1484,  1229, -1484,  9566,   879, -1484, -1484,
   -1484, 18522,     3, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, 12586,  1141, 18522,  1304,  8358,
     777, -1484, -1484,   780, 12586, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,  1307, -1484, -1484,  1146,  1151, 18522, -1484, -1484,
   12586,  9566, 18522,  1153, 12586,  1154,  1234, 15002, -1484, 15002,
    9566, -1484,  1233,  1178, 18522,  1198,  1310, 18522,  1197, 15002,
   -1484
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   810,  1005,   122,   124,   608,
     902,   911,   851,   815,   813,   795,   903,   906,   858,   819,
     796,   798,   260,   912,   799,   909,   880,   860,   835,   797,
     855,   856,   907,   904,   854,   801,   910,   802,   803,   947,
     959,   946,   852,   871,   865,   804,   853,   806,   805,   948,
     889,   890,   857,   832,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   993,  1000,   879,   875,   866,
     846,   794,   874,   882,   891,   994,   870,   463,   847,   848,
     905,   995,  1001,   867,   884,     0,   471,   465,   877,   812,
     868,   869,   898,   872,   888,   897,   999,  1002,   818,   859,
     900,   464,   887,   893,   170,     0,     0,     0,   400,   885,
     896,   901,   899,   878,   864,   949,   862,   863,   996,     0,
     399,     0,   997,  1003,   894,   849,   873,   998,   213,   895,
     876,   883,   892,   886,   950,   840,   845,   844,   843,   842,
     841,   807,   861,     0,   811,     0,   908,   833,   462,   466,
     467,   940,   939,   941,   817,   816,   836,     0,   800,     0,
     943,     0,     0,   839,   881,   938,   945,   944,   937,   837,
     942,   954,   955,   952,   953,   951,   808,   956,   957,   958,
     928,   927,   914,   831,   824,   921,   917,   834,   830,   929,
     261,   820,   821,   814,   823,   926,   925,   922,   918,   935,
     936,   934,   924,   920,   913,   822,   933,   932,   826,   828,
     827,   919,   923,   915,   829,   916,   825,   931,   980,   981,
     982,   983,   984,   985,   961,   962,   960,   966,   967,   968,
     963,   964,   965,   838,   986,   987,   988,   989,   990,   991,
     992,     0,     0,     0,  1004,   167,   167,     0,     2,   167,
       9,    11,    25,     0,    30,    33,    38,    39,    40,    41,
      42,    43,    44,    34,    60,    61,    35,    36,     0,    78,
      81,    82,    37,    83,    84,     0,   120,    85,    86,    87,
      88,    20,   164,   165,   166,   173,   176,   454,   177,     0,
     178,   179,   180,   181,   182,   183,   184,   187,   188,     0,
     214,   222,   217,   249,   255,     0,   247,     0,   248,   224,
     218,   186,   219,   185,   220,   223,   357,   359,   361,   363,
     365,   367,   371,   373,   376,   381,   384,   387,   389,   391,
     393,     0,   397,   404,   403,   405,     0,   420,   406,   425,
     426,   427,   434,   445,   459,   461,   446,   447,   448,   451,
     452,   449,   453,   480,   481,   450,   484,   486,   487,   488,
     485,   533,   534,   535,   536,   537,   538,   539,   460,    45,
     225,   226,   228,   227,   229,   221,   456,   457,   458,   455,
     231,   234,   230,   232,   233,     0,   793,   809,   902,   911,
     909,   811,     0,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   795,   819,   798,   850,   912,   799,   860,   801,   871,
     804,   806,   805,   889,   794,   848,   872,   896,   949,   950,
     837,   954,   955,   952,   808,   956,   930,   821,   468,   793,
       0,   791,     0,     0,   214,     0,     0,   792,   799,   806,
     805,     0,   170,   756,   956,     0,   222,     0,   469,     0,
     500,     0,     0,     0,   792,   423,   424,     0,     0,     0,
     529,     0,     0,   800,   943,     0,   776,   800,   943,     0,
       0,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   758,     0,   760,     0,
       0,     0,   167,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   167,     0,   167,     0,     0,   121,   174,
       0,     0,   192,     0,     0,   201,     0,   260,     0,     0,
       0,     0,     0,     0,   261,   206,   235,   254,   250,   256,
     251,   253,   252,     0,   259,     0,     0,     0,     0,     0,
       0,   408,   413,   412,   411,   410,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   401,   398,     0,     0,
     421,     0,     0,     0,   435,   442,     0,     0,   541,   543,
     547,   549,     0,   126,     0,   790,    49,    46,    47,    50,
      51,     0,     0,     0,     0,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   615,   616,   617,
       0,   105,   144,     0,     0,   114,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,   136,     0,   140,   170,
     483,     0,    62,     0,    71,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,   328,     0,     0,     0,     0,
       0,   606,     0,     0,     0,     0,   196,     0,     0,   190,
     189,     0,     0,   762,     0,     0,     0,     0,   468,     0,
     757,     0,   470,   501,   500,   497,     0,     0,     0,   531,
     530,   422,     0,   528,     0,     0,   628,   629,   775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   634,     0,   204,   205,     0,     0,     0,     0,
       0,   209,   210,   759,   761,     0,     0,     5,    26,     0,
      27,     0,     7,    31,     0,    17,     8,    32,     0,    21,
     902,    79,    18,    80,    22,   195,     0,   193,   215,   216,
       0,     0,     0,     0,   207,   236,   297,   258,   262,     0,
     237,   238,   257,     0,     0,   358,   360,   364,     0,   368,
     375,   374,   372,   378,   379,   380,   377,   382,   383,   386,
     385,     0,     0,     0,     0,   407,   418,     0,   440,   439,
     441,   438,     0,   476,   436,   478,     0,   443,   482,   474,
       0,     0,   123,   125,     0,     0,     0,   104,     0,    94,
      96,    97,    98,    99,   101,   102,   103,    95,   100,    90,
      91,     0,     0,   110,     0,   106,   108,   109,   116,     0,
       0,    89,    48,     0,     0,     0,     0,     0,     0,     0,
     706,   711,     0,     0,   707,   741,   694,   696,   697,   698,
     700,   702,   701,   699,   703,     0,     0,     0,     0,     0,
     113,     0,   146,     0,     0,   546,   540,     0,   142,     0,
       0,   137,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,   278,   284,   281,     0,     0,     0,     0,
       0,   545,     0,     0,     0,   414,     0,     0,     0,     0,
     197,     0,     0,   764,     0,     0,   763,     0,     0,     0,
     500,   498,     0,   489,     0,     0,   472,   473,     0,    13,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   770,   771,     0,     0,   778,     0,   800,     0,
       0,     0,     0,     0,   202,     0,     0,     0,   431,   432,
     433,   430,   642,   429,     0,   428,   211,     0,   774,     0,
       0,     0,   167,     0,   167,     0,   175,   246,     0,   312,
     308,   310,     0,   298,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,     0,   245,     0,     0,
       0,     0,   672,   369,   645,   649,   651,   653,   655,   658,
     665,   666,   674,   795,   796,   798,   912,   797,   801,   802,
     803,   804,   794,   562,     0,   807,   800,   787,   789,   785,
     564,   388,   552,   559,   560,   581,   572,   580,   579,   578,
     577,   574,   576,   573,   575,   565,   609,   610,   566,   567,
     781,   782,   783,   570,   390,   392,   395,   571,   394,   419,
     444,     0,   437,   475,   127,    58,    59,    56,    57,   133,
     132,     0,    92,     0,     0,     0,   111,   112,   117,    76,
      77,    54,    55,    75,   712,     0,   715,   742,     0,   705,
     704,   709,   708,   740,     0,     0,   717,     0,   713,   716,
     695,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   148,   150,     0,     0,     0,   115,   118,     0,
       0,     0,   170,   143,   138,   141,     0,   191,     0,     0,
      73,    67,    70,    69,     0,    65,   551,   282,     0,     0,
     170,     0,   326,   330,     0,     0,     0,   333,     0,     0,
     339,     0,     0,   346,     0,   350,     0,   416,   415,   170,
     198,     0,   200,   327,     0,     0,     0,     0,     0,   501,
       0,   491,     0,   524,   521,     0,   525,   526,     0,     0,
     520,     0,   495,   523,   522,     0,     0,     0,     0,     0,
     621,   622,   618,     0,     0,   626,   627,   623,   767,   768,
       0,   632,   777,   630,     0,     0,     0,     0,     0,   636,
     799,   806,   805,   956,   203,     0,     0,     0,   637,   638,
       0,     0,   212,   773,    28,     0,    19,    23,    24,   309,
     321,     0,   322,     0,   313,   314,   315,   316,     0,   301,
       0,     0,   264,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,     0,
     291,     0,   288,   293,   244,     0,     0,   656,   669,     0,
     366,   370,     0,   688,     0,     0,     0,     0,     0,     0,
     644,   646,   647,   683,   684,   685,   687,   686,     0,     0,
     660,   659,     0,   663,   667,   681,   679,   678,   671,   675,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,   556,
     558,   557,   553,   396,   477,   479,   135,   134,    93,   107,
     729,   710,     0,   734,     0,   734,   723,   718,   149,   151,
       0,     0,     0,   119,   147,     0,    29,     0,   139,     0,
       0,    72,     0,    66,   283,     0,     0,   329,   331,   336,
       0,   334,     0,     0,     0,     0,     0,   340,     0,     0,
     354,     0,     0,   347,     0,     0,   351,   417,     0,   199,
     765,   766,     0,     0,   500,     0,     0,   532,     0,   500,
       0,   496,     0,    14,    16,     0,     0,     0,     0,     0,
       0,     0,   780,     0,   635,     0,     0,     0,     0,     0,
       0,   639,   643,   325,   323,   324,   317,   318,   319,   311,
       0,     0,   306,     0,   300,   263,     0,     0,   277,   269,
       0,   273,     0,   267,     0,     0,     0,   286,     0,     0,
       0,   243,   289,   292,     0,   673,   664,   670,     0,     0,
     743,   744,   754,   753,   752,     0,     0,     0,     0,   745,
     650,   751,     0,   648,   652,     0,     0,   657,   661,     0,
     682,   677,   680,   676,   588,   583,     0,     0,   598,     0,
       0,     0,     0,   568,     0,   586,     0,   589,     0,     0,
       0,   587,   592,     0,     0,   561,   614,   554,   582,   786,
     788,   784,   563,   730,     0,     0,   728,   735,   736,   732,
       0,   727,     0,   725,     0,     0,     0,     0,     0,     0,
     542,     0,     0,     0,    68,   285,   548,     0,     0,   337,
     341,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   544,     0,     0,   500,     0,   527,
       0,   500,   550,   619,   620,   624,   625,     0,   772,   631,
     779,   633,     0,     0,     0,     0,   640,   320,   307,   302,
       0,   266,     0,   275,     0,     0,   271,     0,   274,   287,
     295,   296,   290,   242,   668,   755,     0,     0,   747,     0,
     693,   692,   691,   690,   689,   654,     0,   746,   584,   585,
       0,   602,     0,   599,     0,   611,     0,     0,   591,   590,
     597,   605,     0,   595,     0,   593,   739,   738,   737,     0,
     731,   724,   722,     0,   719,   720,   714,   152,   154,   156,
       0,     0,     0,     0,     0,   208,   356,    74,   332,   338,
       0,   352,   348,   355,     0,     0,     0,   342,     0,     0,
     344,     0,   510,   504,   499,     0,   500,   490,     0,   769,
       0,     0,     0,     0,   305,   303,   270,   268,     0,   276,
       0,   749,   748,     0,     0,     0,     0,   606,     0,     0,
     612,   569,     0,     0,     0,   733,   726,     0,     0,   158,
     157,     0,     0,     0,     0,   153,     0,     0,     0,     0,
       0,   518,   512,     0,   511,   513,   519,   516,   506,     0,
     505,   507,   517,   492,     0,   493,     0,     0,   641,   304,
     272,     0,   750,   662,   603,   604,   607,   600,   601,   613,
     596,   594,   721,   155,   159,     0,     0,     0,     0,     0,
       0,   345,   343,     0,     0,   503,   514,   515,   502,   508,
     509,   494,     0,   294,   160,     0,     0,     0,   353,   349,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
     163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1484, -1484,  -230,  -177, -1484,  1199,  1218, -1484,  1232,  -467,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
    -870, -1484, -1484, -1484, -1484,  -193,  -508, -1484,   772,   -48,
   -1484, -1484, -1484, -1484, -1484,   321,   568, -1484, -1484,    16,
    -178,  1051, -1484,  1018, -1484, -1484,  -566, -1484,   522, -1484,
     286, -1484,  -228,  -281, -1484,  -474, -1484,    39,    27,    33,
    -272,  -164, -1484,  -772, -1484, -1484,   439, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484,   679, -1484,   -95,
    1712,     0, -1484, -1484, -1484, -1484,   414, -1484, -1484,  -289,
   -1484,     5, -1484, -1484,   855,  -943,  -782,  -760, -1484, -1484,
     754, -1484, -1484,   -29,   163, -1484, -1484, -1484,   177, -1483,
   -1484,   441,   182, -1484, -1484,   189, -1208, -1484,   984,   284,
   -1484, -1484,   281,  -912, -1484, -1484,   280, -1484, -1484, -1143,
   -1155, -1484,   274, -1334, -1484, -1484,   871,  -127, -1484,   872,
     864, -1484, -1484,  -587,   452,  -560,   449,   451, -1484, -1484,
   -1484,   644, -1484, -1484,  1213, -1484, -1484, -1484, -1484,  -755,
    -303,  -599, -1484, -1484,   219, -1484,  -139, -1484,   852, -1484,
    -375, -1484, -1484,   854,   856, -1484, -1484, -1484, -1484,   845,
   -1484, -1484, -1484, -1484,  -898, -1484,   271, -1484,   757,  -703,
   -1484, -1484, -1484, -1484, -1484,  -262,  -255, -1128,  -932, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
    -644,  -771,   -84,  -777, -1484, -1484, -1484,  -823, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484,   149,   151,  -616,  -149,
    -567, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,   248, -1484, -1484,   238, -1484,   240,  -958, -1484,
   -1484, -1484,   181,   172,    -4,   462, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   183,
   -1484, -1484, -1484,     1,   456,   601, -1484, -1484, -1484, -1484,
   -1484,   371, -1484, -1484, -1449, -1484, -1484, -1484,  -472, -1484,
     136, -1484,   -33, -1484, -1484, -1484, -1484, -1246, -1484,   197,
   -1484, -1484, -1484, -1484, -1484,   -99, -1484, -1484, -1484, -1484,
   -1484,  -818, -1484, -1484, -1484,  -369,  -105,   252,  1190, -1484
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   247,   564,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1160,   687,   265,   266,   267,   268,   269,   270,   859,   860,
     861,   271,   272,   273,   865,   866,   867,   274,   419,   275,
     276,   632,   277,   421,   422,   423,   429,   677,   678,   278,
    1141,   279,  1657,  1658,   280,   281,   282,   482,   283,   284,
     285,   286,   287,   680,   288,   289,   450,   290,   291,   292,
     293,   294,   295,   575,   296,   297,   761,   762,   298,   299,
     300,   496,   302,   576,   588,  1026,  1027,   303,   577,   304,
     579,   497,   306,   307,   797,   798,  1290,   436,   308,   437,
     438,   804,  1291,  1292,  1293,   580,   581,  1013,  1014,  1452,
     582,  1010,  1011,  1264,  1265,  1266,  1267,   309,   694,   695,
     310,  1176,  1177,  1392,   311,  1179,  1180,   312,   313,  1182,
    1183,  1184,  1185,  1399,   314,   315,   316,   317,   318,   319,
     320,  1300,   321,   322,   323,   324,   325,   326,   327,   328,
     329,  1085,   330,   331,   332,   333,   597,   334,   335,   336,
     337,   338,   339,   340,   992,   993,   341,   624,   625,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   836,
     352,   353,   354,   355,   356,   357,  1211,   724,   725,   726,
    1684,  1739,  1740,  1733,  1734,  1741,  1735,  1212,  1213,   358,
     359,  1214,   360,   361,   362,   363,   364,   365,   366,   367,
     922,  1400,  1352,  1062,  1514,  1063,  1086,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,   700,  1706,
     368,  1075,  1076,  1077,  1078,   369,   370,   371,   372,   373,
     374,   751,   752,   375,  1248,  1249,  1596,   994,  1033,  1310,
    1311,  1034,  1035,  1036,  1037,  1038,  1320,  1497,  1498,  1039,
    1323,  1040,  1478,  1041,  1042,  1328,  1329,  1503,  1501,  1312,
    1313,  1314,  1315,  1623,   661,   886,   887,   888,   889,   890,
     891,  1128,  1545,  1654,  1129,  1543,  1652,   892,  1365,  1540,
    1536,  1537,  1538,   893,   894,  1316,  1324,  1488,  1317,  1484,
    1301,   376,   377,   378,   379,   485,   380,   381,   382,   383,
     384,  1079,  1080,  1081,  1082,  1161,   486,   385,   386,   387
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -931;
  const short int
  jsoniq_parser::yytable_[] =
  {
       301,   301,   301,   301,   301,   305,   305,   305,   305,   305,
     495,   499,   559,   534,   503,   812,   578,  1019,   516,   825,
    1178,   952,   524,   554,   633,   633,   420,  1403,   393,   393,
     393,   397,   636,   620,   394,   394,   394,   398,   556,  1020,
     392,   395,   396,   813,   814,   815,   816,   781,   783,  1165,
    1061,  1084,   930,  1031,   830,  1413,  1210,  1447,  1448,   551,
     521,   552,   940,   684,   688,   535,   552,  1568,   543,   544,
    1572,  1296,  1272,  1142,  1100,  1016,  1499,   846,  1143,   775,
     779,   782,   784,  1421,   552,  1105,   773,   777,     9,  1023,
    1133,  1279,   552,  1660,   434,  1655,   552,   558,   712,   552,
     552,   729,   552,   711,   301,   552,  1168,   552,  1137,   305,
     509,   635,  1485,   552,  1276,   711,  1694,   552,   552,     9,
     841,   552,   559,     7,     8,   603,   559,   552,   552,  1616,
     712,   393,  1682,   651,   920,   652,  1017,   483,  1154,  -171,
     552,   635,   862,   841,   405,   920,   537,   539,   552,  1166,
     712,   675,  1017,   600,   604,  1021,  1261,   552,   552,  1131,
     776,   552,  1169,   600,  1132,  1133,  1017,   605,   653,   563,
      77,   601,   408,  1134,   563,  1175,  1218,  1263,  1219,   424,
    1135,   601,  1136,  1137,    87,   863,   399,  1018,  1390,   560,
     864,  1138,   563,  1001,   602,   654,   685,   927,   929,   552,
     842,    77,   606,  1280,  1661,  -172,   552,  1617,   578,   101,
     667,   559,  1749,  1028,   552,    87,  1029,  1456,  1139,   743,
     676,   563,  1683,   843,  1108,   563,   563,   713,   744,   563,
     552,   970,   981,  1505,   552,   563,   563,   121,  1597,  1281,
     101,   435,   558,   686,   435,   301,   301,  1200,   563,   301,
     305,   305,  1024,   435,   305,   552,   563,   655,  1403,  1277,
     971,  1282,   781,   783,  1153,   563,   563,  1396,  1762,   563,
     730,  1485,   722,   683,  1031,  1031,  1486,  1342,   928,   148,
     149,   150,  1101,   553,   301,   872,  1662,   555,  1421,   305,
     768,   770,  1025,  1002,  1383,   510,  1004,  1653,  1254,   560,
     794,   773,   777,   560,  1210,   913,   932,   563,   656,   933,
     148,   149,   150,  1210,   563,   985,  1196,   435,   918,   671,
     769,   771,   563,  1030,   552,  -171,  1142,  1342,  1455,  1357,
     786,  1143,   674,   435,   720,   681,  1726,   478,   563,   561,
    1477,   962,   563,  1464,   693,  1197,  1198,   698,   699,  1690,
    1140,   401,   402,   705,   403,   404,   487,   444,   927,   500,
     774,   778,  1393,   563,   982,   767,  1095,     7,     8,     7,
       8,   504,   407,   507,  1393,   875,   738,   876,  1284,   764,
     621,   665,   763,  1096,   746,  1378,   666,  1691,   560,   668,
     405,  -172,   400,  1770,   301,  1773,   525,   669,   301,   305,
     406,   526,  1692,   305,  1393,   552,   727,   728,  1302,   552,
     953,   487,   552,   732,  1569,   622,  1090,   623,   408,   907,
     742,   877,   562,   409,   552,   301,   301,   428,  1255,   552,
     305,   305,   563,  1032,   445,  1486,  1487,   757,   759,   942,
     926,   301,  1057,  1058,  1059,   301,   305,  1681,  1394,   552,
     305,  1719,   672,   673,   557,   410,   411,  1005,   398,   398,
    1558,   910,  1097,   806,   958,   552,  1094,  1302,   697,   963,
     964,   552,   702,   435,   398,   413,  1175,   954,   398,  1098,
     425,  1303,  1570,   301,   965,   527,   559,  1091,   305,  1395,
    1563,  1457,   301,   426,   781,   783,   781,   305,  1201,   607,
    1109,  1110,  1235,  1091,  1373,  1113,   446,   447,   608,   938,
    1362,  1480,  1764,   563,  1006,  1570,   831,   563,  1210,   393,
     563,  1465,   566,   959,   827,   394,   567,   832,  1256,  1257,
    1258,   568,   563,   301,   920,  1151,  1358,   563,   305,   414,
    1303,   911,   301,  1031,  1003,  1370,   966,   305,   771,  1747,
     569,  1481,  1031,   301,   301,   301,   301,   563,   305,   305,
     305,   305,  1513,  1031,   420,  1202,   758,  1092,  1304,  1305,
    1364,  1306,   301,   563,   920,   999,   878,   305,   914,   563,
     415,   917,   427,  1093,     7,     8,  1261,  1283,  1308,   879,
     955,   880,  1403,  1630,   956,   401,   402,   957,   403,   404,
    1309,  1632,   881,   882,   883,   405,   884,   945,   885,   987,
     979,   430,  1534,  1401,  1089,   406,   407,  1636,   619,  1642,
     947,   948,   949,   960,   759,  1453,  1402,  1304,  1305,   651,
    1306,   652,   566,   408,  1475,   416,   567,  1307,   409,  1203,
    1204,   568,   121,   417,  1644,     9,   600,  1308,  1250,   570,
    1748,   418,   571,   621,  1032,  1032,  1753,  1595,   644,  1309,
     569,   648,  1731,   986,   601,   504,  1203,   572,   662,   663,
     410,   411,   412,  1631,   967,   968,   504,  1535,  1620,   301,
    1605,  1633,   961,  1667,   305,  1621,   689,   645,   622,   969,
     623,   654,   696,   573,  1649,  1622,   701,  1637,   566,  1643,
    1125,   706,   567,   301,   301,  1251,   393,   568,   305,   305,
    -850,  1576,   394,  1244,  1251,   431,  1580,  1126,   912,   413,
     646,   583,  1492,   584,  1645,   432,   569,    77,   620,  1731,
     936,   937,   696,  1203,  -850,  1205,   398,   398,  1203,  1204,
    1031,    87,   574,   718,   487,  -850,   781,   747,   439,   863,
    1736,  1742,   433,   655,   864,  1206,   786,  1207,   301,   570,
    1127,  1620,   571,   305,  1203,  1204,   101,  1203,  1621,   771,
    1028,   487,   621,  1029,  1650,  1433,  1549,   721,  1622,  1396,
     753,  1017,  1206,   414,  1207,  1208,   301,  1737,   585,   107,
    1381,   305,  1732,   586,   121,  1673,   420,  1362,   920,  1203,
    1204,  1125,  1736,   573,   548,  1286,   119,   622,  1742,   623,
    1287,  1102,  1208,   920,  1363,  1119,   440,   641,  1126,   920,
     549,  1349,   441,  1102,   415,   570,  1120,  1209,   571,  1288,
    1252,  1450,  1604,   642,  1205,   799,   148,   149,   150,   799,
     587,  1236,  1203,  1439,   776,   143,   921,   975,  1017,  1206,
     416,  1207,   574,  1350,  1206,  1404,  1207,  1364,   417,  1776,
    1205,   939,  1737,  1710,   442,  1711,   418,  1451,  1405,   573,
    1289,  1351,   621,   504,  1685,  1325,  1326,  1000,  1688,  1208,
    1206,  1099,  1207,  1206,  1208,  1207,  1379,   621,   107,  1111,
    1112,  1286,  1443,   549,  1738,  1205,  1287,   679,  1327,  1618,
    1619,  -930,   868,  1286,  1298,   119,   443,   622,  1287,   623,
    1208,   449,   600,  1208,   107,  1206,   898,  1207,   574,  1615,
     902,   903,   622,  1032,   623,  -930,  1415,   908,   121,   480,
     601,   119,  1032,  1295,   301,   504,  -930,   609,   504,   305,
     637,  1759,   923,  1032,   143,  1208,  1017,  1659,  1565,   107,
     511,   610,  1420,  1703,   638,  1675,  1679,   578,  1206,   639,
    1207,  1186,  1769,  1260,   487,  1790,   119,   398,  1791,  1779,
     143,   448,  1566,   640,  1261,   950,   501,  1356,  1401,  1566,
    1566,  1401,   502,  1744,  1262,  1245,  1566,  1578,  1208,  1566,
    1246,  1575,  1566,   679,  1782,  1263,   785,  1145,   512,  1121,
     787,   508,   301,   301,   301,   143,  1146,   305,   305,   305,
    1122,  1482,   995,  1554,  1705,  1720,  1708,   420,  1483,  1114,
    1115,  1116,   657,   658,   659,  1117,  1713,   528,  1714,  1701,
    1702,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,  1223,  1007,  1224,   591,   592,   593,   594,   595,   596,
    1444,  1445,   810,   811,   529,  1022,   817,   818,  1368,  1369,
     819,   820,  1646,  1647,   530,  1659,   531,   532,   533,   545,
     565,   589,   590,  1083,  1083,  1087,  1087,   598,   599,   534,
     611,  1598,   612,   613,   618,   614,   626,   627,   635,   628,
     629,   630,   631,   647,   649,   650,   660,   664,   679,   682,
     691,   692,   690,   703,   707,   704,   711,   709,   714,   715,
     716,   717,   719,   723,  1083,   733,  1752,   731,   734,  1659,
    1032,   735,  1560,   749,   750,   754,   755,   772,  1118,   766,
     790,   791,   760,   803,   792,   793,   808,   800,   821,   801,
     822,   838,   823,   824,   622,   844,   845,   847,   869,   870,
     873,   874,   301,  1148,   901,   896,   897,   305,   301,   899,
     895,  1083,   904,   305,   909,   905,   916,   794,   915,   919,
     301,   934,  1083,   977,   974,   305,   983,   906,   980,   393,
     931,   935,  1001,   997,  1008,   394,  1012,  1103,   984,   301,
    1015,  1377,   864,   920,   305,  1123,  1150,   393,  1801,  1144,
    1802,  1149,  1124,   394,  1152,   675,  1156,  1158,   301,  1386,
    1810,  1157,  1162,   305,  1159,   301,   393,  1163,  1170,  1164,
     305,  1171,   394,  1174,  1175,  1181,  1187,  1188,  1408,  1194,
    1518,  1189,  1195,  1191,  1192,  1418,  1199,  1215,  1216,  1217,
    1230,   398,  1422,   653,  1247,  1237,  1268,  1270,   398,  1274,
    1245,  1278,  1330,  1318,  1331,  1246,  1273,  1285,  1299,  1353,
       9,  1332,  1333,  1360,  1269,  1319,  1334,   799,  1361,  1335,
    1336,  1322,  1337,  1338,  1339,   479,  1340,  1343,  1366,  1665,
    1372,  1382,  1376,   758,  1344,  1375,  1345,  1385,  1346,  1347,
    1669,  1560,  1348,  1671,  1371,  1412,  1401,   479,  1414,  1417,
    1425,  1680,  1429,  1431,  1426,  1436,  1083,  1437,  1438,   479,
    1250,   479,  1427,  1261,  1428,  1460,  1462,  1466,  1407,  1468,
    1474,  1469,  1430,  1470,  1435,  1423,  1495,  1424,  1476,  1502,
    1500,  1496,  1533,  1504,  1515,  1479,  1539,  1544,  1550,  1542,
    1489,  1592,  1593,  1594,  1551,  1521,  1525,  1526,  1527,  1528,
    1529,  1546,  1530,  1552,  1553,  1548,  1083,  1587,  1531,  1556,
    1532,  1600,  1557,  1562,  1573,  1626,  1574,  1579,  1582,  1602,
    1607,  1614,  1627,  1628,  1634,  1629,  1651,  1635,  1638,  1125,
    1639,  1640,  1641,  1664,  1656,  1670,  1663,  1450,  1698,  1700,
    1712,  1715,  1717,  1718,   301,  1687,  1722,  1727,  1723,   305,
    1728,  1729,  1746,  1754,  1755,  1743,  1745,  1671,  1083,  1756,
    1751,  1716,  1757,  1758,  1768,  1760,  1761,  1767,  1765,  1774,
    1775,  1778,  1800,   696,  1787,   871,  1359,  1792,  1781,  1806,
    1807,  1106,  1155,  1083,  1803,  1374,  1725,  1763,   670,  1245,
     996,  1294,   802,  1612,  1246,  1793,   925,  1454,   546,  1259,
    1449,   634,  1785,  1473,  1446,  1387,  1771,  1391,  1406,  1397,
     805,  1419,  1794,   809,   708,  1797,  1799,   547,  1088,   807,
    1442,  1804,   840,  1416,  1379,   828,   837,   829,  1780,  1777,
    1506,   951,  1507,  1709,   550,  1434,  1441,  1440,  1490,   753,
    1494,  1625,  1297,  1624,  1493,  1321,  1130,  1788,  1367,   995,
    1693,  1541,     0,   995,  1648,  1491,     0,     0,     0,  1809,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1788,
       0,     0,     0,   799,     0,     0,  1458,     0,  1771,     0,
       0,  1704,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1472,     0,     0,   617,     0,     0,     0,     0,     0,
       0,  1245,     0,     0,     0,     0,  1246,     0,     0,     0,
       0,     0,  1245,  1245,     0,   301,     0,  1246,  1246,     0,
     305,     0,     0,  1245,     0,     0,     0,     0,  1246,     0,
       0,     0,     0,     0,  1510,  1083,     0,   504,  1519,  1520,
       0,  1524,     0,     0,     0,   643,   479,     0,     0,   479,
       0,     0,     0,   479,     0,     0,   479,   479,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,  1547,   479,     0,     0,     0,     0,     0,
     479,     0,     0,     0,   479,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1564,     0,     0,  1083,     0,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1577,     0,     0,
     479,     0,  1581,     0,     0,     0,     0,     0,     0,  1245,
       0,   479,     0,     0,  1246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,  1610,  1611,     0,     0,     0,     0,     0,   301,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1245,     0,     0,     0,
       0,  1246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,     0,     0,   479,   305,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1245,     0,     0,     0,     0,  1246,     0,     0,     0,
    1245,     0,     0,     0,     0,  1246,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,   484,     0,  1083,  1674,
       0,  1676,     0,  1678,     0,     0,     0,     0,     0,     0,
    1686,     0,     0,     0,     0,     0,     0,   848,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,   479,   479,
       0,     0,     0,     0,     0,   479,     0,     0,     0,     0,
       0,   520,     0,   479,     0,     0,   479,     0,     0,     0,
     479,     0,  1707,     0,  1707,     0,  1083,     0,  1083,     0,
       0,     0,     0,     0,   701,     0,   701,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1721,   479,     0,  1724,     0,     0,     0,     0,
       0,     0,  1083,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1766,     0,     0,     0,     0,  1083,
     479,  1083,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1783,     0,     0,     0,     0,     0,     0,
       0,   479,   479,   479,   479,     0,     0,     0,     0,  1786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1795,
       0,     0,     0,     0,  1796,     0,     0,     0,     0,     0,
       0,     0,   479,     0,     0,     0,  1805,     0,     0,  1808,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,     0,   484,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   736,   737,     0,     0,   739,
     740,   741,     0,     0,   745,     0,     0,   748,     0,     0,
       0,     0,     0,   756,   479,     0,     0,     0,     0,     0,
       0,     0,   765,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   788,   789,     0,     0,     0,
       0,     0,     0,     0,   795,   796,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   835,     0,     0,     0,   835,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,   900,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,   924,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   941,
       0,     0,     0,   943,   944,     0,   946,   479,     0,     0,
       0,     0,     0,   795,     0,     0,     0,   479,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   972,   973,     0,     0,   976,
       0,   479,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   998,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   789,     0,
       0,     0,     0,     0,  1009,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,   479,     0,   479,   479,   479,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,   479,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,     0,     0,     0,     0,
     479,  1147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,     0,     0,     0,     0,     0,     0,
    1172,  1173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1190,     0,     0,  1193,     0,     0,     0,     0,   479,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1220,  1221,  1222,     0,  1225,
    1226,  1227,  1228,  1229,     0,     0,  1231,  1232,     0,  1233,
    1234,     0,     0,     0,  1238,  1239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1009,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,   479,     0,   479,
       0,   479,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,   479,     0,   479,     0,   479,     0,     0,     0,
       0,     0,   479,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,   479,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1380,   479,     0,     0,     0,     0,     0,     0,     0,     0,
    1384,     0,     0,     0,     0,     0,  1388,  1389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,  1409,     0,     0,  1410,  1411,     0,     0,
       0,     0,   479,     0,     0,     0,     0,   479,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,  1432,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,     0,     0,
    1009,     0,   479,     0,     0,     0,     0,     0,  1459,     0,
    1461,     0,  1463,     0,   479,  1467,     0,   479,     0,     0,
    1471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1555,     0,     0,
       0,     0,     0,     0,     0,  1559,  1561,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1583,  1584,  1585,
    1586,     0,  1588,  1589,     0,  1590,     0,  1591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1599,     0,     0,     0,     0,  1601,     0,
       0,     0,  1603,     0,     0,     0,  1606,     0,  1608,     0,
    1609,     0,     0,     0,     0,     0,  1613,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1666,     0,     0,     0,     0,  1668,
    1561,     0,     0,     0,     0,     0,     0,  1672,     0,     0,
       0,     0,  1677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1689,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1695,     0,  1696,     0,  1697,     0,     0,  1699,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1672,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1750,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -167,   776,     0,     0,     0,     0,     0,  1784,     0,     0,
       0,  1789,     0,     0,     0,     0,  1772,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,  1789,     0,    10,   389,  1798,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,   128,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,  -167,
     776,   243,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   780,   389,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   390,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   391,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   776,   242,     0,     0,
     243,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   388,
     389,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   390,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
     104,   105,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,   128,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   391,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   776,   242,     0,     0,   243,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   388,   389,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     488,   390,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   489,   490,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   465,    80,    81,    82,    83,
      84,   491,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,   492,   105,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   391,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   471,   472,   473,   174,   175,
     474,   494,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
     988,   989,   243,   244,     0,     0,     0,     0,     0,   990,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,   388,   389,     0,    12,    13,    14,   451,
      16,    17,    18,   452,    20,   453,   454,   455,   456,   390,
      26,   457,    28,    29,    30,     0,    31,    32,    33,    34,
     458,    36,    37,    38,    39,    40,    41,    42,   459,     0,
      44,   460,    46,   461,   462,    49,   463,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   464,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   465,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   466,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     109,   467,     0,     0,     0,     0,   111,   112,   113,   114,
     468,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,     0,     0,     0,   991,     0,   129,     0,   130,
     131,   132,   133,   469,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   391,     0,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,     0,
     158,     0,   160,     0,     0,   163,   164,   165,   166,   167,
     168,   470,   170,   471,   472,   473,   174,   175,   474,   475,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   476,     0,   191,   477,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
       0,   244,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,   128,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,     0,   243,   244,     0,     0,     0,     0,   245,   246,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,     0,     0,
     243,   244,     0,   481,     0,     0,     0,   542,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   388,   389,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   390,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,   104,   105,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,   128,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   391,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,   242,   481,     0,   243,   244,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   517,   159,   518,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,   481,
     519,   243,   244,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   388,   389,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   488,   390,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   489,   490,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   465,    80,    81,
      82,    83,    84,   491,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     0,   492,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     391,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   471,   472,   473,
     174,   175,   474,   494,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     481,   242,     0,     0,   243,   244,     0,     0,     0,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,   451,    16,    17,    18,   452,    20,
     453,   454,   455,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,   458,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,   460,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   464,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,   491,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,   106,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     481,     0,     0,     0,     0,     0,   244,     0,     0,     5,
       6,     0,     0,     0,  1516,     0,     0,     0,   388,   389,
       0,    12,    13,    14,   451,    16,    17,    18,   452,    20,
     453,   454,   455,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,   458,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,   460,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   464,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,  1517,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     481,     0,     0,     0,     0,     0,   244,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   388,   389,
       0,    12,    13,    14,   451,    16,    17,    18,   452,    20,
     453,   454,   455,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,   458,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,   460,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   464,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     505,   506,     0,     0,     0,     0,   244,     5,     6,     0,
       0,     0,     0,     0,     0,     0,   388,   389,     0,    12,
      13,    14,   451,    16,    17,    18,   452,    20,   453,   454,
     455,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,   458,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,   460,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   464,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   469,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   391,
       0,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,   244,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,   128,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   710,     0,   125,     0,   126,   127,   128,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   104,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
     128,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,   128,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,    10,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,   128,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,   243,   244,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   780,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,   128,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,  1240,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
    1241,  1242,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,   128,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,  1243,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   488,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   489,   490,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,   833,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,   834,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   471,   472,   473,   174,   175,   474,   494,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,   833,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   839,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   489,   490,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,   493,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   471,   472,   473,   174,
     175,   474,   494,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,   243,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   489,   490,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,   498,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   471,   472,
     473,   174,   175,   474,   494,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   488,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     489,   490,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     471,   472,   473,   174,   175,   474,   494,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   536,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   488,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   489,   490,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   471,   472,   473,   174,   175,   474,   494,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,   538,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
     540,   243,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   489,   490,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,   826,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   471,   472,   473,   174,
     175,   474,   494,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,   243,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   489,   490,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
    1354,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   471,   472,
     473,   174,   175,   474,   494,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   488,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     489,   490,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     471,   472,   473,   174,   175,   474,   494,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   488,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   489,   490,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,     0,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   471,   472,   473,   174,   175,   474,   494,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   454,    23,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,    45,    46,   461,   462,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     615,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   616,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   158,     0,   160,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,     0,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   454,
      23,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,    45,    46,   461,   462,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,     0,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,     0,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   454,    23,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,    45,    46,
     461,   462,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,     0,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   158,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,     0,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   454,    23,   456,   390,    26,
     457,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   459,     0,    44,
      45,    46,   461,   462,    49,   463,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,   106,   107,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   513,
       0,   514,     0,     0,   163,   164,   165,   166,   167,   168,
     470,   170,   471,   472,   473,   174,   175,   474,   475,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   476,     0,   191,   477,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,   515,     0,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   454,    23,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,    45,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   522,     0,   160,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
     523,     0,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   454,
      23,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,    45,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,     0,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   978,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     5,     6,     0,   244,     0,     0,     0,
       0,     0,   388,   389,     0,    12,    13,    14,  1043,    16,
      17,    18,   452,  1044,  1045,   454,  1046,   456,   390,    26,
     457,    28,  1047,    30,     0,    31,    32,    33,    34,  1048,
      36,  1049,  1050,    39,    40,    41,    42,   459,     0,    44,
    1051,    46,   461,   462,    49,   463,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1052,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   465,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1053,     0,     0,     0,  1054,     0,     0,   109,
     467,     0,     0,     0,     0,   111,   112,   113,   114,   468,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,  1511,   126,   127,
       0,     0,     0,     0,  1512,     0,   129,     0,   130,   131,
     132,   133,   469,   135,   136,   137,   138,   139,   140,     0,
       0,  1055,   142,     0,     0,   391,     0,   146,   147,     0,
       0,     0,   151,   152,   153,   154,   155,   156,     0,  1056,
       0,   160,     0,     0,   163,   164,   165,   166,   167,   168,
     470,   170,   471,   472,   473,   174,   175,   474,   475,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   476,     0,   191,   477,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     5,     6,     0,     0,
     244,  1057,  1058,  1059,  1060,   388,   389,     0,    12,    13,
      14,  1043,    16,    17,    18,   452,  1044,  1045,   454,  1046,
     456,   390,    26,   457,    28,  1047,    30,     0,    31,    32,
      33,    34,  1048,    36,  1049,  1050,    39,    40,    41,    42,
     459,     0,    44,  1051,    46,   461,   462,    49,   463,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1052,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   465,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   466,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1053,     0,     0,     0,  1104,
       0,     0,   109,   467,     0,     0,     0,     0,   111,   112,
     113,   114,   468,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
    1341,   126,   127,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   469,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   391,     0,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,  1056,     0,   160,     0,     0,   163,   164,   165,
     166,   167,   168,   470,   170,   471,   472,   473,   174,   175,
     474,   475,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   476,     0,   191,   477,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     5,
       6,     0,     0,   244,  1057,  1058,  1059,  1060,   388,   389,
       0,    12,    13,    14,  1043,    16,    17,    18,   452,  1044,
    1045,   454,  1046,   456,   390,    26,   457,    28,  1047,    30,
       0,    31,    32,    33,    34,  1048,    36,  1049,  1050,    39,
      40,    41,    42,   459,     0,    44,  1051,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1052,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,  1398,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1053,     0,
       0,     0,  1054,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,  1055,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,  1056,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     5,     6,     0,     0,   244,  1057,  1058,  1059,
    1060,   388,   389,     0,    12,    13,    14,  1043,    16,    17,
      18,   452,  1044,  1045,   454,  1046,   456,   390,    26,   457,
      28,  1047,    30,     0,    31,    32,    33,    34,  1048,    36,
    1049,  1050,    39,    40,    41,    42,   459,     0,    44,  1051,
      46,   461,   462,    49,   463,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1052,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   465,    80,    81,    82,    83,    84,  1567,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   466,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1053,     0,     0,     0,  1054,     0,     0,   109,   467,
       0,     0,     0,     0,   111,   112,   113,   114,   468,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   469,   135,   136,   137,   138,   139,   140,     0,     0,
    1055,   142,     0,     0,   391,     0,   146,   147,     0,     0,
       0,   151,   152,   153,   154,   155,   156,     0,  1056,     0,
     160,     0,     0,   163,   164,   165,   166,   167,   168,   470,
     170,   471,   472,   473,   174,   175,   474,   475,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     476,     0,   191,   477,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     5,     6,     0,     0,   244,
    1057,  1058,  1059,  1060,   388,   389,     0,    12,    13,    14,
    1043,    16,    17,    18,   452,  1044,  1045,   454,  1046,   456,
     390,    26,   457,    28,  1047,    30,     0,    31,    32,    33,
      34,  1048,    36,  1049,  1050,    39,    40,    41,    42,   459,
       0,    44,  1051,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1052,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
    1571,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1053,     0,     0,     0,  1054,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   469,   135,   136,   137,   138,   139,
     140,     0,     0,  1055,   142,     0,     0,   391,     0,   146,
     147,     0,     0,     0,   151,   152,   153,   154,   155,   156,
       0,  1056,     0,   160,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     5,     6,
       0,     0,   244,  1057,  1058,  1059,  1060,   388,   389,     0,
      12,    13,    14,  1043,    16,    17,    18,   452,  1044,  1045,
     454,  1046,   456,   390,    26,   457,    28,  1047,    30,     0,
      31,    32,    33,    34,  1048,    36,  1049,  1050,    39,    40,
      41,    42,   459,     0,    44,  1051,    46,   461,   462,    49,
     463,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1052,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   465,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     466,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1053,     0,     0,
       0,  1054,     0,     0,   109,   467,     0,     0,     0,     0,
     111,   112,   113,   114,   468,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   469,   135,   136,
     137,   138,   139,   140,     0,     0,  1055,   142,     0,     0,
     391,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,     0,  1056,     0,   160,     0,     0,   163,
     164,   165,   166,   167,   168,   470,   170,   471,   472,   473,
     174,   175,   474,   475,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   476,     0,   191,   477,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     5,     6,     0,     0,   244,  1057,  1058,  1059,  1060,
     388,   389,     0,    12,    13,    14,  1043,    16,    17,    18,
     452,  1044,  1045,   454,  1046,   456,   390,    26,   457,    28,
    1047,    30,     0,    31,    32,    33,    34,  1048,    36,  1049,
    1050,    39,    40,    41,    42,   459,     0,    44,  1051,    46,
     461,   462,    49,   463,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1052,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     465,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1053,     0,     0,     0,  1104,     0,     0,   109,   467,     0,
       0,     0,     0,   111,   112,   113,   114,   468,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     469,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   391,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,  1056,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     5,     6,     0,     0,   244,  1057,
    1058,  1059,  1060,   388,   389,     0,    12,    13,    14,   451,
      16,    17,    18,   452,    20,   453,   454,   455,   456,   390,
      26,   457,    28,    29,    30,     0,    31,    32,    33,    34,
     458,    36,    37,    38,    39,    40,    41,    42,   459,     0,
      44,   460,    46,   461,   462,    49,   463,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   464,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   465,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   466,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     109,   467,     0,     0,     0,     0,   111,   112,   113,   114,
     468,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,     0,     0,     0,   125,  1508,   126,
     127,     0,     0,     0,     0,  1509,     0,   129,     0,   130,
     131,   132,   133,   469,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   391,     0,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,     0,
     158,     0,   160,     0,     0,   163,   164,   165,   166,   167,
     168,   470,   170,   471,   472,   473,   174,   175,   474,   475,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   476,     0,   191,   477,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     5,     6,     0,     0,     0,
       0,   244,     0,     0,   388,   389,     0,    12,    13,    14,
     451,    16,    17,    18,   452,    20,   453,   454,   455,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,   458,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,   460,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   464,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,  1522,
     126,   127,     0,     0,     0,     0,  1523,     0,   129,     0,
     130,   131,   132,   133,   469,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   391,     0,   146,
     147,     0,     0,     0,   151,   152,   153,   154,   155,   156,
       0,   158,     0,   160,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     5,     6,     0,     0,
       0,     0,   244,     0,     0,   388,   389,     0,    12,    13,
      14,   451,    16,    17,    18,   452,    20,   453,   454,   455,
     456,   390,    26,   457,    28,    29,    30,     0,    31,    32,
      33,    34,   458,    36,    37,    38,    39,    40,    41,    42,
     459,     0,    44,   460,    46,   461,   462,    49,   463,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     464,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   465,    80,    81,    82,    83,
      84,  1271,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   466,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   109,   467,     0,     0,     0,     0,   111,   112,
     113,   114,   468,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   469,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   391,     0,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   158,     0,   160,     0,     0,   163,   164,   165,
     166,   167,   168,   470,   170,   471,   472,   473,   174,   175,
     474,   475,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   476,     0,   191,   477,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     5,     6,     0,
       0,     0,     0,   244,     0,     0,   388,   389,     0,    12,
      13,    14,   451,    16,    17,    18,   452,    20,   453,   454,
     455,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,   458,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,   460,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   464,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   469,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   391,
       0,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     5,     6,
       0,     0,     0,     0,   244,     0,     0,   388,   389,     0,
      12,    13,    14,     0,    16,    17,    18,   452,     0,     0,
     454,   455,     0,   390,    26,   457,    28,     0,    30,     0,
      31,    32,    33,    34,     0,    36,     0,     0,    39,    40,
      41,    42,   459,     0,    44,     0,    46,     0,     0,    49,
     463,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,     0,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   465,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     466,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   109,   467,     0,     0,     0,     0,
     111,   112,   113,   114,   468,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   469,   135,   136,
     137,   138,   139,   140,     0,     0,     0,   142,     0,     0,
     391,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,     0,     0,     0,   160,     0,     0,   163,
     164,   165,   166,   167,   168,   470,   170,   471,   472,   473,
     174,   175,     0,   475,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   476,     0,   191,   477,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,   244
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     105,   106,   284,   177,   119,   602,   305,   799,   157,   618,
     932,   724,   161,   253,   399,   400,    10,  1182,     1,     2,
       3,     4,   401,   336,     1,     2,     3,     4,   268,   799,
       1,     2,     3,   603,   604,   605,   606,   555,   556,   919,
     821,   822,   696,   808,   621,  1198,   954,  1265,  1266,   252,
     159,     1,   706,   432,   433,   192,     1,  1401,   245,   246,
    1404,  1029,  1015,   896,   846,    37,  1322,   643,   896,   553,
     554,   555,   556,  1211,     1,   862,   553,   554,    30,    57,
      46,    37,     1,   120,   120,  1544,     1,   275,   109,     1,
       1,     8,     1,   123,   104,     1,   144,     1,    64,   104,
      31,    30,    98,     1,   149,   123,  1599,     1,     1,    30,
     109,     1,   394,    27,    28,   119,   398,     1,     1,    53,
     109,   104,    95,    46,    96,    48,    98,   104,   909,     0,
       1,    30,    96,   109,    48,    96,   241,   242,     1,   920,
     109,   120,    98,   160,   148,   799,   108,     1,     1,    40,
       1,     1,   922,   160,    45,    46,    98,   161,    81,   109,
     112,   178,    76,    54,   109,   102,   238,   129,   240,   162,
      61,   178,    63,    64,   126,   139,   158,   149,   115,   284,
     144,    72,   109,    34,   201,   108,   115,   109,   149,     1,
     189,   112,   196,   149,   231,     0,     1,   131,   497,   151,
     114,   483,  1695,   155,     1,   126,   158,   149,    99,   239,
     189,   109,   185,   189,   868,   109,   109,   186,   239,   109,
       1,   239,   109,   189,     1,   109,   109,   179,  1446,  1021,
     151,   279,   420,   162,   279,   245,   246,   950,   109,   249,
     245,   246,   220,   279,   249,     1,   109,   170,  1413,  1019,
     239,  1021,   770,   771,   908,   109,   109,  1179,  1717,   109,
     177,    98,   189,   162,  1029,  1030,   262,  1054,   190,   221,
     222,   223,   848,   192,   284,   654,   313,   192,  1416,   284,
     192,   192,   260,   192,  1164,   216,   192,  1543,   192,   394,
     572,   768,   769,   398,  1202,   189,   189,   109,   413,   189,
     221,   222,   223,  1211,   109,   189,   189,   279,   687,   424,
     550,   551,   109,   265,     1,   186,  1149,  1104,  1271,  1101,
     560,  1149,   427,   279,   187,   430,  1670,    85,   109,   109,
    1298,    96,   109,   149,   439,   189,   189,   442,   443,   189,
     231,    38,    39,   448,    41,    42,   104,    78,   109,   107,
     553,   554,   102,   109,   241,   542,   150,    27,    28,    27,
      28,   119,    59,   121,   102,    56,   515,    58,  1022,   319,
     121,   139,   317,   167,   523,  1156,   144,   189,   483,   293,
      48,   186,   158,  1727,   394,  1729,   231,   301,   398,   394,
      58,   236,   189,   398,   102,     1,   501,   502,    98,     1,
     132,   159,     1,   508,   120,   156,   187,   158,    76,   186,
     519,   102,   192,    81,     1,   425,   426,   158,   115,     1,
     425,   426,   109,   808,   155,   262,   263,   532,   533,   190,
     186,   441,   323,   324,   325,   445,   441,   120,   188,     1,
     445,  1659,   425,   426,   114,   113,   114,   115,   425,   426,
     188,   109,   150,   590,   133,     1,   841,    98,   441,   224,
     225,     1,   445,   279,   441,   162,   102,   199,   445,   167,
     155,   171,   188,   483,   239,   320,   758,   109,   483,   115,
     188,  1273,   492,   155,  1002,  1003,  1004,   492,   132,   203,
     869,   870,   243,   109,  1148,   874,   227,   228,   212,   186,
      98,   220,  1720,   109,   786,   188,   621,   109,  1416,   492,
     109,  1281,    43,   192,   619,   492,    47,   622,  1002,  1003,
    1004,    52,   109,   533,    96,   904,  1103,   109,   533,   226,
     171,   189,   542,  1298,   774,  1144,    96,   542,   778,  1692,
      71,   260,  1307,   553,   554,   555,   556,   109,   553,   554,
     555,   556,  1333,  1318,   548,   199,   533,   189,   258,   259,
     158,   261,   572,   109,    96,   768,   257,   572,   683,   109,
     267,   686,   155,   189,    27,    28,   108,   149,   278,   270,
     186,   272,  1747,   109,   186,    38,    39,   186,    41,    42,
     290,   109,   283,   284,   285,    48,   287,   712,   289,   186,
     749,   158,   138,   102,   186,    58,    59,   109,   155,   109,
     715,   716,   717,   133,   719,  1269,   115,   258,   259,    46,
     261,    48,    43,    76,   186,   293,    47,   268,    81,     9,
      10,    52,   179,   301,   109,    30,   160,   278,   155,   170,
     186,   309,   173,   121,  1029,  1030,   186,   155,   406,   290,
      71,   409,     5,   758,   178,   413,     9,   188,   416,   417,
     113,   114,   115,   189,   224,   225,   424,   203,   275,   679,
    1462,   189,   192,  1553,   679,   282,   434,   171,   156,   239,
     158,   108,   440,   214,   109,   292,   444,   189,    43,   189,
      98,   449,    47,   703,   704,   212,   679,    52,   703,   704,
     123,  1414,   679,   985,   212,    25,  1419,   115,   679,   162,
     204,     1,  1309,     3,   189,    35,    71,   112,  1031,     5,
     703,   704,   480,     9,   147,   105,   703,   704,     9,    10,
    1495,   126,   263,   491,   492,   158,  1254,    96,   155,   139,
    1682,  1683,    62,   170,   144,   125,   986,   127,   758,   170,
     158,   275,   173,   758,     9,    10,   151,     9,   282,   999,
     155,   519,   121,   158,   189,   243,  1375,   188,   292,  1691,
     528,    98,   125,   226,   127,   155,   786,    29,    68,   159,
    1159,   786,   135,    73,   179,  1566,   780,    98,    96,     9,
      10,    98,  1734,   214,    34,    55,   176,   156,  1740,   158,
      60,   859,   155,    96,   115,   269,   120,   168,   115,    96,
      50,   146,   155,   871,   267,   170,   280,   197,   173,    79,
     994,   108,   149,   184,   105,   583,   221,   222,   223,   587,
     120,   980,     9,   188,     1,   215,   144,    96,    98,   125,
     293,   127,   263,   178,   125,   102,   127,   158,   301,   135,
     105,   144,    29,  1634,   158,  1636,   309,   144,   115,   214,
     120,   196,   121,   621,  1577,   253,   254,    34,  1581,   155,
     125,   139,   127,   125,   155,   127,  1158,   121,   159,   130,
     131,    55,  1261,    50,   136,   105,    60,   155,   276,  1486,
    1487,   123,   650,    55,   155,   176,   158,   156,    60,   158,
     155,   120,   160,   155,   159,   125,   664,   127,   263,  1479,
     668,   669,   156,  1298,   158,   147,   197,   675,   179,   120,
     178,   176,  1307,  1028,   934,   683,   158,   138,   686,   934,
     184,  1712,   690,  1318,   215,   155,    98,  1546,   188,   159,
     219,   152,   197,   201,   198,   188,   188,  1246,   125,   184,
     127,   934,   188,    97,   712,   188,   176,   934,   188,   136,
     215,   155,   212,   198,   108,   723,   155,   139,   102,   212,
     212,   102,   155,  1686,   118,   985,   212,   197,   155,   212,
     985,   115,   212,   155,   115,   129,   557,   305,   219,   269,
     561,   155,  1002,  1003,  1004,   215,   314,  1002,  1003,  1004,
     280,   274,   760,  1382,  1630,  1659,  1632,  1001,   281,   283,
     284,   285,   227,   228,   229,   289,  1642,   120,  1644,  1616,
    1617,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   238,   790,   240,   205,   206,   207,   208,   209,   210,
     130,   131,   600,   601,   247,   803,   607,   608,  1142,  1143,
     609,   610,  1534,  1535,   247,  1664,   248,   158,   155,     0,
     192,   169,    94,   821,   822,   823,   824,   255,   101,  1243,
      51,  1450,   202,   103,   195,   104,   147,   158,    30,   186,
     186,   186,   186,    48,   154,   120,   252,   310,   155,     1,
     144,   109,   120,   155,   144,   155,   123,   186,   123,   158,
     158,   158,   155,    36,   862,   216,  1703,    17,    30,  1718,
    1495,    30,  1394,   237,   236,   192,   192,     3,   876,   239,
     120,   170,   251,   120,   172,   172,    72,   290,   237,   290,
      96,   151,    96,    96,   156,   109,   109,    30,   162,   162,
     129,   134,  1152,   901,   120,    96,   305,  1152,  1158,   144,
     252,   909,   134,  1158,    96,   186,    46,  1439,    98,    98,
    1170,   155,   920,   243,    96,  1170,   144,   186,   237,  1152,
     186,   186,    34,   239,   172,  1152,   120,   134,   192,  1189,
     109,  1152,   144,    96,  1189,    30,   305,  1170,  1797,   233,
    1799,    96,   292,  1170,   155,   120,    96,   200,  1208,  1170,
    1809,   186,   162,  1208,   134,  1215,  1189,   134,   155,    98,
    1215,   120,  1189,   149,   102,   102,   186,   186,  1189,   123,
    1335,   155,   123,   144,   192,  1208,    36,   155,    30,    30,
      98,  1208,  1215,    81,   251,   120,   109,   109,  1215,   120,
    1250,   149,   158,   264,   158,  1250,   129,   260,   291,   146,
      30,   158,   158,   292,  1012,   266,   158,  1015,    30,   158,
     158,   273,   158,   158,   158,    85,   158,   158,    30,  1551,
     312,   109,   192,  1250,   158,   233,   158,   144,   158,   158,
    1562,  1563,   158,  1565,   293,   200,   102,   107,   134,     7,
     239,  1573,    98,   243,   239,   158,  1054,   158,   158,   119,
     155,   121,   239,   108,   239,   149,   129,   149,   186,   149,
      79,   120,   322,   120,   188,   192,   149,   192,   189,    80,
     292,   288,    30,   189,   189,   256,    30,   109,   186,   277,
     256,  1436,  1437,  1438,   128,   189,   189,   189,   189,   189,
     189,   172,   189,   128,    98,   263,  1104,   322,   189,   186,
     189,   144,   188,   188,   188,   155,   186,   186,   186,   149,
     149,   186,   286,   189,    96,   189,    30,   189,   189,    98,
     189,   189,   189,   172,   189,    96,   293,   108,   149,    55,
      96,    30,   109,   109,  1394,   199,   120,    96,   231,  1394,
     188,    96,   200,   189,   189,   199,   199,  1679,  1156,   146,
     120,   271,   189,   189,   231,   189,   189,   120,   311,   188,
      95,   185,   188,  1171,   120,   653,  1105,   120,   199,   231,
     120,   863,   910,  1181,   201,  1149,  1664,  1718,   420,  1439,
     761,  1027,   587,  1472,  1439,   299,   692,  1270,   249,  1008,
    1268,   400,   311,  1290,  1265,  1171,  1728,  1176,  1184,  1179,
     589,  1209,   311,   599,   480,   312,   312,   249,   824,   597,
    1251,   293,   627,  1202,  1746,   621,   624,   621,  1740,  1734,
    1331,   724,  1331,  1632,   252,  1237,  1248,  1247,  1307,  1237,
    1318,  1495,  1030,  1492,  1311,  1039,   895,  1769,  1127,  1247,
    1595,  1365,    -1,  1251,  1537,  1308,    -1,    -1,    -1,   312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,
      -1,    -1,    -1,  1271,    -1,    -1,  1274,    -1,  1800,    -1,
      -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1289,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,
      -1,  1551,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,
      -1,    -1,  1562,  1563,    -1,  1565,    -1,  1562,  1563,    -1,
    1565,    -1,    -1,  1573,    -1,    -1,    -1,    -1,  1573,    -1,
      -1,    -1,    -1,    -1,  1332,  1333,    -1,  1335,  1336,  1337,
      -1,  1339,    -1,    -1,    -1,   405,   406,    -1,    -1,   409,
      -1,    -1,    -1,   413,    -1,    -1,   416,   417,    -1,    -1,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1371,   434,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1398,    -1,    -1,  1401,    -1,    -1,  1404,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,
     480,    -1,  1420,    -1,    -1,    -1,    -1,    -1,    -1,  1679,
      -1,   491,    -1,    -1,  1679,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,
      -1,  1469,  1470,    -1,    -1,    -1,    -1,    -1,  1728,    -1,
      -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,    -1,
      -1,  1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,    -1,   583,  1769,    -1,    -1,   587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1791,    -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,
    1800,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,    -1,
      -1,   621,    -1,    -1,    -1,    -1,   104,    -1,  1566,  1567,
      -1,  1569,    -1,  1571,    -1,    -1,    -1,    -1,    -1,    -1,
    1578,    -1,    -1,    -1,    -1,    -1,    -1,   647,    -1,    -1,
     650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   664,    -1,    -1,    -1,   668,   669,
      -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   683,    -1,    -1,   686,    -1,    -1,    -1,
     690,    -1,  1630,    -1,  1632,    -1,  1634,    -1,  1636,    -1,
      -1,    -1,    -1,    -1,  1642,    -1,  1644,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1660,   723,    -1,  1663,    -1,    -1,    -1,    -1,
      -1,    -1,  1670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1681,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     760,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1722,    -1,    -1,    -1,    -1,  1727,
     790,  1729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   803,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1751,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   821,   822,   823,   824,    -1,    -1,    -1,    -1,  1767,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,
      -1,    -1,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   862,    -1,    -1,    -1,  1804,    -1,    -1,  1807,
      -1,    -1,    -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1012,    -1,   492,  1015,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   513,   514,    -1,    -1,   517,
     518,   519,    -1,    -1,   522,    -1,    -1,   525,    -1,    -1,
      -1,    -1,    -1,   531,  1054,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   563,   564,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   572,   573,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,   627,
      -1,    -1,    -1,    -1,    -1,    -1,  1156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1181,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1209,
      -1,    -1,    -1,   691,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,
      -1,    -1,    -1,   711,   712,    -1,   714,  1237,    -1,    -1,
      -1,    -1,    -1,   721,    -1,    -1,    -1,  1247,    -1,    -1,
      -1,  1251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   743,   744,    -1,    -1,   747,
      -1,  1271,    -1,    -1,  1274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   766,  1289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   786,    -1,
      -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1332,  1333,    -1,  1335,  1336,  1337,    -1,  1339,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1398,    -1,
      -1,  1401,    -1,    -1,  1404,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,    -1,
    1420,   899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   921,    -1,    -1,    -1,    -1,    -1,    -1,
     928,   929,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   939,    -1,    -1,   942,    -1,    -1,    -1,    -1,  1469,
    1470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   963,   964,   965,    -1,   967,
     968,   969,   970,   971,    -1,    -1,   974,   975,    -1,   977,
     978,    -1,    -1,    -1,   982,   983,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   997,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1566,  1567,    -1,  1569,
      -1,  1571,    -1,    -1,    -1,    -1,    -1,    -1,  1578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1630,    -1,  1632,    -1,  1634,    -1,  1636,    -1,    -1,    -1,
      -1,    -1,  1642,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1660,    -1,    -1,  1663,    -1,    -1,    -1,    -1,    -1,    -1,
    1670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1158,  1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1168,    -1,    -1,    -1,    -1,    -1,  1174,  1175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1712,  1191,    -1,    -1,  1194,  1195,    -1,    -1,
      -1,    -1,  1722,    -1,    -1,    -1,    -1,  1727,    -1,  1729,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1751,    -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1767,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,    -1,    -1,
    1268,    -1,  1792,    -1,    -1,    -1,    -1,    -1,  1276,    -1,
    1278,    -1,  1280,    -1,  1804,  1283,    -1,  1807,    -1,    -1,
    1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1393,  1394,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1425,  1426,  1427,
    1428,    -1,  1430,  1431,    -1,  1433,    -1,  1435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1451,    -1,    -1,    -1,    -1,  1456,    -1,
      -1,    -1,  1460,    -1,    -1,    -1,  1464,    -1,  1466,    -1,
    1468,    -1,    -1,    -1,    -1,    -1,  1474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,    -1,  1557,
    1558,    -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,    -1,
      -1,    -1,  1570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1587,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1600,    -1,  1602,    -1,  1604,    -1,    -1,  1607,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1675,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,    -1,    -1,    -1,  1765,    -1,    -1,
      -1,  1769,    -1,    -1,    -1,    -1,  1774,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,  1790,    -1,    34,    35,  1794,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,     0,
       1,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     1,   318,    -1,    -1,
     321,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     1,   318,    -1,    -1,   321,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      11,    12,   321,   322,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,    -1,
     231,    -1,   233,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,    -1,   321,   322,    -1,    -1,    -1,    -1,   327,   328,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,   318,    -1,    -1,
     321,   322,    -1,    16,    -1,    -1,    -1,   328,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    16,    -1,   321,   322,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    16,
     320,   321,   322,    -1,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      16,   318,    -1,    -1,   321,   322,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      16,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      16,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      18,    19,    -1,    -1,    -1,    -1,   322,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,   186,    -1,   188,    -1,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,   319,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
     146,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,    -1,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,    -1,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,    -1,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,    -1,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,    -1,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,    -1,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,    -1,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    25,    26,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    25,    26,    -1,    -1,
     322,   323,   324,   325,   326,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    25,
      26,    -1,    -1,   322,   323,   324,   325,   326,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    25,    26,    -1,    -1,   322,   323,   324,   325,
     326,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,    -1,   231,    -1,
     233,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,    -1,    25,    26,    -1,    -1,   322,
     323,   324,   325,   326,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,
     220,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    25,    26,
      -1,    -1,   322,   323,   324,   325,   326,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    25,    26,    -1,    -1,   322,   323,   324,   325,   326,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    25,    26,    -1,    -1,   322,   323,
     324,   325,   326,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,    -1,
     231,    -1,   233,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    25,    26,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,
     220,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    25,    26,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    25,    26,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    25,    26,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    -1,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    53,    -1,    55,    -1,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    69,    -1,    71,    -1,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,    -1,    -1,    -1,   233,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    -1,    -1,    -1,    -1,   322
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  jsoniq_parser::yystos_[] =
  {
         0,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   104,   107,   108,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   126,   128,   129,
     130,   131,   133,   137,   138,   139,   140,   141,   148,   149,
     150,   151,   152,   153,   155,   156,   158,   159,   160,   161,
     162,   167,   168,   169,   170,   171,   172,   173,   174,   176,
     178,   179,   182,   183,   184,   188,   190,   191,   192,   198,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   213,   214,   215,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   265,   266,   267,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   318,   321,   322,   327,   328,   342,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   363,   364,   365,   366,   367,
     368,   372,   373,   374,   378,   380,   381,   383,   390,   392,
     395,   396,   397,   399,   400,   401,   402,   403,   405,   406,
     408,   409,   410,   411,   412,   413,   415,   416,   419,   420,
     421,   422,   423,   428,   430,   432,   433,   434,   439,   458,
     461,   465,   468,   469,   475,   476,   477,   478,   479,   480,
     481,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     493,   494,   495,   496,   498,   499,   500,   501,   502,   503,
     504,   507,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   521,   522,   523,   524,   525,   526,   540,   541,
     543,   544,   545,   546,   547,   548,   549,   550,   571,   576,
     577,   578,   579,   580,   581,   584,   642,   643,   644,   645,
     647,   648,   649,   650,   651,   658,   659,   660,    34,    35,
      50,   217,   398,   399,   400,   398,   398,   399,   400,   158,
     158,    38,    39,    41,    42,    48,    58,    59,    76,    81,
     113,   114,   115,   162,   226,   267,   293,   301,   309,   379,
     380,   384,   385,   386,   162,   155,   155,   155,   158,   387,
     158,    25,    35,    62,   120,   279,   438,   440,   441,   155,
     120,   155,   158,   158,    78,   155,   227,   228,   155,   120,
     407,    40,    44,    46,    47,    48,    49,    52,    61,    69,
      72,    74,    75,    77,    99,   114,   137,   162,   171,   204,
     242,   244,   245,   246,   249,   250,   263,   266,   658,   659,
     120,    16,   398,   400,   421,   646,   657,   658,    49,    74,
      75,   120,   155,   187,   250,   420,   422,   432,   189,   420,
     658,   155,   155,   657,   658,    18,    19,   658,   155,    31,
     216,   219,   219,   231,   233,   320,   507,   231,   233,   320,
     421,   646,   231,   320,   507,   231,   236,   320,   120,   247,
     247,   248,   158,   155,   402,   478,   317,   420,   319,   420,
     320,   421,   328,   344,   344,     0,   346,   347,    34,    50,
     349,   366,     1,   192,   343,   192,   343,   114,   381,   401,
     420,   109,   192,   109,   343,   192,    43,    47,    52,    71,
     170,   173,   188,   214,   263,   414,   424,   429,   430,   431,
     446,   447,   451,     1,     3,    68,    73,   120,   425,   169,
      94,   205,   206,   207,   208,   209,   210,   497,   255,   101,
     160,   178,   201,   119,   148,   161,   196,   203,   212,   138,
     152,    51,   202,   103,   104,   160,   178,   495,   195,   155,
     501,   121,   156,   158,   508,   509,   147,   158,   186,   186,
     186,   186,   382,   511,   382,    30,   656,   184,   198,   184,
     198,   168,   184,   659,   658,   171,   204,    48,   658,   154,
     120,    46,    48,    81,   108,   170,   657,   227,   228,   229,
     252,   615,   658,   658,   310,   139,   144,   114,   293,   301,
     384,   657,   399,   399,   420,   120,   189,   388,   389,   155,
     404,   420,     1,   162,   656,   115,   162,   362,   656,   658,
     120,   144,   109,   420,   459,   460,   658,   399,   420,   420,
     569,   658,   399,   155,   155,   420,   658,   144,   459,   186,
     186,   123,   109,   186,   123,   158,   158,   158,   658,   155,
     187,   188,   189,    36,   528,   529,   530,   420,   420,     8,
     177,    17,   420,   216,    30,    30,   421,   421,   507,   421,
     421,   421,   646,   239,   239,   421,   507,    96,   421,   237,
     236,   582,   583,   658,   192,   192,   421,   420,   400,   420,
     251,   417,   418,   317,   319,   421,   239,   344,   192,   343,
     192,   343,     3,   350,   366,   396,     1,   350,   366,   396,
      34,   367,   396,   367,   396,   407,   343,   407,   421,   421,
     120,   170,   172,   172,   401,   421,   421,   435,   436,   658,
     290,   290,   435,   120,   442,   477,   478,   480,    72,   481,
     485,   485,   484,   486,   486,   486,   486,   487,   487,   488,
     488,   237,    96,    96,    96,   502,   186,   420,   514,   515,
     571,   657,   420,   146,   189,   421,   520,   509,   151,   189,
     520,   109,   189,   189,   109,   109,   387,    30,   659,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   369,
     370,   371,    96,   139,   144,   375,   376,   377,   658,   162,
     162,   369,   656,   129,   134,    56,    58,   102,   257,   270,
     272,   283,   284,   285,   287,   289,   616,   617,   618,   619,
     620,   621,   628,   634,   635,   252,    96,   305,   658,   144,
     421,   120,   658,   658,   134,   186,   186,   186,   658,    96,
     109,   189,   398,   189,   657,    98,    46,   657,   656,    98,
      96,   144,   551,   658,   421,   441,   186,   109,   190,   149,
     551,   186,   189,   189,   155,   186,   399,   399,   186,   144,
     551,   421,   190,   421,   421,   657,   421,   420,   420,   420,
     658,   529,   530,   132,   199,   186,   186,   186,   133,   192,
     133,   192,    96,   224,   225,   239,    96,   224,   225,   239,
     239,   239,   421,   421,    96,    96,   421,   243,   231,   507,
     237,   109,   241,   144,   192,   189,   420,   186,    11,    12,
      20,   196,   505,   506,   588,   658,   418,   239,   421,   366,
      34,    34,   192,   343,   192,   115,   401,   658,   172,   421,
     452,   453,   120,   448,   449,   109,    37,    98,   149,   437,
     438,   551,   658,    57,   220,   260,   426,   427,   155,   158,
     265,   500,   511,   589,   592,   593,   594,   595,   596,   600,
     602,   604,   605,    40,    45,    46,    48,    54,    61,    63,
      64,    72,    99,   154,   158,   213,   231,   323,   324,   325,
     326,   552,   554,   556,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   572,   573,   574,   575,   652,
     653,   654,   655,   658,   552,   492,   557,   658,   492,   186,
     187,   109,   189,   189,   511,   150,   167,   150,   167,   139,
     404,   387,   370,   134,   158,   554,   377,   421,   551,   656,
     656,   130,   131,   656,   283,   284,   285,   289,   658,   269,
     280,   269,   280,    30,   292,    98,   115,   158,   622,   625,
     616,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     231,   391,   558,   652,   233,   305,   314,   421,   658,    96,
     305,   656,   155,   551,   552,   389,    96,   186,   200,   134,
     361,   656,   162,   134,    98,   361,   552,   421,   144,   438,
     155,   120,   421,   421,   149,   102,   462,   463,   464,   466,
     467,   102,   470,   471,   472,   473,   399,   186,   186,   155,
     421,   144,   192,   421,   123,   123,   189,   189,   189,    36,
     530,   132,   199,     9,    10,   105,   125,   127,   155,   197,
     525,   527,   538,   539,   542,   155,    30,    30,   238,   240,
     421,   421,   421,   238,   240,   421,   421,   421,   421,   421,
      98,   421,   421,   421,   421,   243,   507,   120,   421,   421,
      49,    74,    75,   250,   401,   422,   432,   251,   585,   586,
     155,   212,   402,   421,   192,   115,   396,   396,   396,   452,
      97,   108,   118,   129,   454,   455,   456,   457,   109,   658,
     109,   120,   436,   129,   120,   421,   149,   438,   149,    37,
     149,   437,   438,   149,   551,   260,    55,    60,    79,   120,
     437,   443,   444,   445,   427,   420,   589,   596,   155,   291,
     482,   641,    98,   171,   258,   259,   261,   268,   278,   290,
     590,   591,   610,   611,   612,   613,   636,   639,   264,   266,
     597,   615,   273,   601,   637,   253,   254,   276,   606,   607,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   189,   554,   158,   158,   158,   158,   158,   158,   146,
     178,   196,   553,   146,   146,   421,   139,   404,   571,   376,
     292,    30,    98,   115,   158,   629,    30,   622,   553,   553,
     502,   293,   312,   551,   391,   233,   192,   398,   552,   401,
     421,   656,   109,   361,   421,   144,   398,   460,   421,   421,
     115,   463,   464,   102,   188,   115,   464,   467,   120,   474,
     552,   102,   115,   471,   102,   115,   473,   186,   398,   421,
     421,   421,   200,   470,   134,   197,   527,     7,   399,   658,
     197,   538,   399,   192,   192,   239,   239,   239,   239,    98,
     322,   243,   421,   243,   583,   188,   158,   158,   158,   188,
     588,   586,   505,   656,   130,   131,   456,   457,   457,   453,
     108,   144,   450,   551,   449,   436,   149,   437,   658,   421,
     149,   421,   129,   421,   149,   438,   149,   421,   149,   120,
     120,   421,   658,   445,    79,   186,   189,   589,   603,   256,
     220,   260,   274,   281,   640,    98,   262,   263,   638,   256,
     593,   640,   484,   610,   594,   149,   288,   598,   599,   638,
     292,   609,    80,   608,   189,   189,   567,   568,   189,   196,
     658,   189,   196,   552,   555,   189,    30,   189,   657,   658,
     658,   189,   189,   196,   658,   189,   189,   189,   189,   189,
     189,   189,   189,    30,   138,   203,   631,   632,   633,    30,
     630,   631,   277,   626,   109,   623,   172,   658,   263,   502,
     186,   128,   128,    98,   656,   421,   186,   188,   188,   421,
     401,   421,   188,   188,   658,   188,   212,   120,   474,   120,
     188,   120,   474,   188,   186,   115,   530,   658,   197,   186,
     530,   658,   186,   421,   421,   421,   421,   322,   421,   421,
     421,   421,   420,   420,   420,   155,   587,   457,   656,   421,
     144,   421,   149,   421,   149,   437,   421,   149,   421,   421,
     658,   658,   444,   421,   186,   486,    53,   131,   484,   484,
     275,   282,   292,   614,   614,   595,   155,   286,   189,   189,
     109,   189,   109,   189,    96,   189,   109,   189,   189,   189,
     189,   189,   109,   189,   109,   189,   629,   629,   633,   109,
     189,    30,   627,   638,   624,   625,   189,   393,   394,   502,
     120,   231,   313,   293,   172,   401,   421,   361,   421,   401,
      96,   401,   421,   552,   658,   188,   658,   421,   658,   188,
     401,   120,    95,   185,   531,   530,   658,   199,   530,   421,
     189,   189,   189,   420,   450,   421,   421,   421,   149,   421,
      55,   484,   484,   201,   420,   569,   570,   658,   569,   570,
     552,   552,    96,   569,   569,    30,   271,   109,   109,   457,
     551,   658,   120,   231,   658,   393,   474,    96,   188,    96,
     658,     5,   135,   534,   535,   537,   539,    29,   136,   532,
     533,   536,   539,   199,   530,   199,   200,   470,   186,   450,
     421,   120,   484,   186,   189,   189,   146,   189,   189,   552,
     189,   189,   625,   394,   457,   311,   658,   120,   231,   188,
     474,   401,   421,   474,   188,    95,   135,   537,   185,   136,
     536,   199,   115,   658,   421,   311,   658,   120,   401,   421,
     188,   188,   120,   299,   311,   658,   658,   312,   421,   312,
     188,   502,   502,   201,   293,   658,   231,   120,   658,   312,
     502
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  jsoniq_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   341,   342,   342,   342,   342,   343,   343,   343,   344,
     344,   344,   344,   345,   345,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   346,   347,   347,   347,   347,   348,
     349,   349,   349,   350,   350,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   352,   352,   353,   354,
     355,   355,   356,   356,   357,   357,   358,   358,   358,   358,
     359,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   363,   363,   363,   364,   365,   365,   366,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     368,   369,   369,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   372,   373,   374,   375,   375,   376,
     376,   376,   377,   378,   378,   378,   379,   379,   379,   379,
     380,   380,   381,   381,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   387,   387,   387,   387,
     388,   388,   389,   389,   390,   390,   390,   390,   391,   391,
     391,   391,   392,   392,   393,   393,   394,   394,   394,   394,
     395,   395,   395,   395,   396,   397,   397,   397,   398,   398,
     398,   399,   399,   400,   400,   400,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   402,
     403,   404,   405,   406,   406,   406,   407,   407,   407,   407,
     408,   409,   410,   411,   412,   412,   413,   414,   415,   416,
     417,   417,   418,   419,   420,   420,   420,   421,   421,   421,
     421,   421,   421,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   423,   424,   425,   425,   426,
     426,   426,   427,   427,   428,   428,   429,   430,   430,   430,
     431,   431,   431,   431,   431,   432,   432,   433,   433,   433,
     434,   434,   435,   435,   435,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   437,   438,   439,
     440,   440,   441,   441,   441,   441,   442,   442,   443,   443,
     443,   444,   444,   444,   445,   445,   445,   446,   447,   448,
     448,   449,   449,   449,   449,   449,   449,   450,   451,   451,
     452,   452,   453,   453,   454,   454,   454,   454,   454,   454,
     454,   455,   455,   456,   456,   457,   458,   458,   459,   459,
     460,   460,   461,   462,   462,   463,   464,   464,   465,   466,
     466,   467,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   473,   473,   474,   474,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   480,   480,   481,   481,   482,
     482,   483,   483,   484,   484,   484,   485,   485,   485,   485,
     485,   486,   486,   486,   487,   487,   487,   488,   488,   489,
     489,   490,   490,   491,   491,   492,   492,   493,   493,   494,
     494,   494,   494,   495,   495,   495,   496,   496,   497,   497,
     497,   497,   497,   497,   498,   498,   498,   498,   499,   499,
     500,   500,   501,   501,   501,   502,   503,   504,   505,   505,
     506,   506,   506,   506,   507,   507,   507,   507,   507,   507,
     507,   507,   508,   508,   509,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   511,
     511,   511,   511,   512,   512,   512,   513,   513,   514,   515,
     515,   516,   517,   518,   519,   519,   520,   520,   520,   520,
     521,   521,   522,   523,   524,   524,   525,   525,   525,   526,
     526,   526,   526,   526,   526,   527,   527,   528,   528,   529,
     530,   530,   531,   531,   532,   532,   533,   533,   533,   533,
     534,   534,   535,   535,   535,   535,   536,   536,   537,   537,
     538,   538,   538,   538,   539,   539,   539,   539,   540,   540,
     541,   541,   542,   543,   543,   543,   543,   543,   543,   543,
     544,   545,   545,   546,   546,   547,   548,   549,   549,   550,
     550,   551,   552,   552,   552,   552,   553,   553,   553,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   555,   555,
     556,   557,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   559,   560,   560,   560,   561,   562,   563,   564,
     564,   564,   565,   565,   565,   565,   565,   566,   567,   567,
     567,   567,   567,   567,   567,   568,   569,   570,   571,   572,
     572,   573,   574,   574,   575,   576,   576,   576,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   578,   578,
     579,   579,   580,   581,   582,   582,   583,   584,   585,   585,
     586,   587,   588,   588,   589,   590,   590,   591,   591,   592,
     592,   593,   593,   594,   594,   595,   595,   596,   597,   597,
     598,   598,   599,   600,   600,   600,   601,   601,   602,   603,
     603,   604,   605,   605,   606,   606,   607,   607,   607,   608,
     608,   609,   609,   610,   610,   610,   610,   610,   611,   612,
     613,   614,   614,   614,   615,   615,   616,   616,   616,   616,
     616,   616,   616,   616,   617,   617,   617,   617,   618,   618,
     619,   620,   620,   621,   621,   621,   622,   622,   623,   623,
     624,   624,   625,   626,   626,   627,   627,   628,   628,   628,
     629,   629,   630,   630,   631,   631,   632,   632,   633,   633,
     634,   635,   635,   636,   636,   636,   637,   638,   638,   638,
     638,   639,   639,   640,   640,   641,   642,   642,   643,   643,
     644,   644,   645,   646,   646,   646,   646,   647,   647,   647,
     647,   647,   647,   648,   648,   649,   649,   650,   650,   651,
     651,   652,   652,   652,   653,   653,   654,   654,   655,   655,
     656,   657,   657,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   660
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  jsoniq_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     4,     6,     3,     3,     5,
       1,     3,     3,     5,     5,     1,     3,     3,     5,     6,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     3,
       3,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       1,     1,     3,     3,     4,     5,     6,     1,     3,     3,
       3,     3,     6,     5,     8,     5,     5,     5,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     1,     1,
       1,     2,     2,     4,     3,     5,     3,     4,     4,     5,
       1,     2,     1,     4,     1,     4,     1,     3,     2,     3,
       1,     1,     4,     4,     5,     5,     2,     3,     4,     5,
       1,     3,     2,     3,     3,     5,     4,     6,     1,     2,
       1,     2,     8,     9,     1,     3,     1,     2,     2,     3,
      11,    14,    13,    22,     1,     1,     1,     0,     1,     1,
       0,     1,     2,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     2,     3,     2,     3,     2,     3,     4,     5,
       5,     2,     4,     5,     3,     3,     2,     2,     8,     3,
       1,     2,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     1,     4,     3,     3,     5,     4,     6,     4,
       6,     5,     7,     4,     5,     5,     6,     3,     3,     2,
       1,     3,     4,     5,     3,     6,     4,     5,     1,     2,
       3,     1,     2,     1,     6,     3,     3,     2,     3,     1,
       3,     2,     4,     5,     6,     5,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,     1,
       2,     3,     8,    10,     8,    10,     1,     2,     4,     7,
       1,     2,     4,     7,     1,     3,     8,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     5,     1,     3,     0,
       1,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     3,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     4,
       8,     5,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     3,
       7,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     3,     1,     3,     2,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     3,     0,     1,
       0,     1,     4,     2,     3,     1,     0,     1,     4,     0,
       1,     2,     1,     3,     0,     1,     2,     2,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     5,     2,     1,     1,     0,     2,
       1,     3,     4,     0,     2,     0,     2,     4,     4,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     3,     2,     3,     3,
       4,     2,     2,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     3,     5,     5,     5,     5,     8,
       4,     4,     7,     5,     4,     3,     2,     5,     4,     7,
       6,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const jsoniq_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'error'\"", "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'namespace NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'for'\"", "\"'function'\"",
  "\"'if'\"", "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'namespace-node'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following'\"",
  "\"'following-sibling'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
  "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"", "\"'treat'\"",
  "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"",
  "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'jsoniq'\"", "\"'version'\"", "\"'start'\"",
  "\"'null'\"", "\"'true'\"", "\"'false'\"", "\"'after'\"", "\"'before'\"",
  "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"", "\"'skip'\"",
  "\"'delete'\"", "\"'node'\"", "\"'insert'\"", "\"'nodes'\"",
  "\"'rename'\"", "\"'replace'\"", "\"'value'\"", "\"'of'\"",
  "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"", "\"'copy'\"",
  "\"'with'\"", "\"'break'\"", "\"'continue'\"", "\"'exit'\"",
  "\"'loop'\"", "\"'returning'\"", "\"'while'\"", "\"'try'\"",
  "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"", "\"'contains'\"",
  "\"'content'\"", "\"'diacritics'\"", "\"'different'\"", "\"'distance'\"",
  "\"'end'\"", "\"'entire'\"", "\"'exactly'\"", "\"'from'\"",
  "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"", "\"'ft-option'\"",
  "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'paragraphs'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"", "\"'stemming'\"",
  "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"", "\"'without'\"",
  "\"'words'\"", "\"'collection'\"", "\"'const'\"", "\"'append-only'\"",
  "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"", "\"'unique'\"",
  "\"'non'\"", "\"'index'\"", "\"'manually'\"", "\"'automatically'\"",
  "\"'maintained'\"", "\"'on'\"", "\"'range'\"", "\"'equality'\"",
  "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"",
  "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"", "\"'keys'\"", "\"'{|'\"",
  "\"'|}'\"", "\"'{['\"", "\"']}'\"", "\"'json'\"", "\"'append'\"",
  "\"'position'\"", "\"'object'\"", "\"'array'\"", "\"'json-item'\"",
  "\"'structured-item'\"", "\"'BOM_UTF8'\"", "\"'#!/shebang\"",
  "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
  "MULTIPLICATIVE_REDUCE", "JSONLOOKUPEXPR_REDUCE", "$accept", "Module",
  "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
  "BoundarySpaceDecl", "DefaultCollationDecl", "BaseURIDecl",
  "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForClause", "ForOrFrom",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl", "WindowVars",
  "WindowVars3", "WindowVars2", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "SwitchStatement",
  "SwitchCaseStatementList", "SwitchCaseStatement", "TypeswitchExpr",
  "TypeswitchStatement", "CaseClauseList", "CaseClause",
  "CaseStatementList", "CaseStatement", "SequenceTypeList", "IfExpr",
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr",
  "RelativePathExpr", "StepExpr", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "BooleanLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList",
  "FunctionItemExpr", "LiteralFunctionItem", "InlineFunction",
  "Constructor", "DirectConstructor", "DirElemConstructor",
  "DirElemContentList", "DirAttributeList", "DirAttr", "OptionalBlank",
  "DirAttributeValue", "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "DocumentTest", "NamespaceTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionTest", "AnyFunctionTest",
  "TypedFunctionTest", "ParenthesizedItemType", "RevalidationDecl",
  "InsertExpr", "DeleteExpr", "ReplaceExpr", "RenameExpr", "TransformExpr",
  "VarNameList", "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr",
  "BracedExpr", "NameTestList", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "JSONArrayConstructor",
  "JSONSimpleObjectUnion", "JSONAccumulatorObjectUnion",
  "JSONObjectConstructor", "JSONPairList", "JSONInsertExpr",
  "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr", "JSONReplaceExpr",
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       342,     0,    -1,   344,    -1,   327,   344,    -1,   328,   344,
      -1,   327,   328,   344,    -1,     1,    -1,     1,     3,    -1,
     343,     1,    -1,   346,    -1,   345,   346,    -1,   347,    -1,
     345,   347,    -1,   217,   219,    30,   192,    -1,   217,   219,
      30,   133,    30,   192,    -1,   218,   219,    30,   192,    -1,
     218,   219,    30,   133,    30,   192,    -1,   349,   192,   396,
      -1,   366,   192,   396,    -1,   349,   192,   366,   192,   396,
      -1,   396,    -1,   349,   343,   396,    -1,   366,   343,   396,
      -1,   349,   192,   366,   343,   396,    -1,   349,   343,   366,
     192,   396,    -1,   348,    -1,   348,   349,   192,    -1,   348,
     366,   192,    -1,   348,   349,   192,   366,   192,    -1,    35,
     162,   657,   134,   656,   192,    -1,   350,    -1,   349,   192,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     576,    -1,    34,    39,   184,    -1,    34,    39,   198,    -1,
      34,   115,   108,   656,    -1,    34,    38,   656,    -1,    34,
      41,   184,    -1,    34,    41,   198,    -1,    34,    59,   171,
      -1,    34,    59,   204,    -1,    34,   115,   170,   129,   130,
      -1,    34,   115,   170,   129,   131,    -1,    34,    42,   184,
     109,   150,    -1,    34,    42,   184,   109,   167,    -1,    34,
      42,   168,   109,   150,    -1,    34,    42,   168,   109,   167,
      -1,   360,    -1,   363,    -1,    50,    25,     1,    -1,    50,
      62,   656,    -1,    50,    62,   362,   656,    -1,    50,    62,
     656,    98,   361,    -1,    50,    62,   362,   656,    98,   361,
      -1,   656,    -1,   361,   109,   656,    -1,   162,   657,   134,
      -1,   115,    46,   162,    -1,    50,    35,   656,    -1,    50,
      35,   162,   657,   134,   656,    -1,    50,    35,   656,    98,
     361,    -1,    50,    35,   162,   657,   134,   656,    98,   361,
      -1,    34,   162,   657,   134,   656,    -1,    34,   115,    46,
     162,   656,    -1,    34,   115,    48,   162,   656,    -1,   367,
      -1,   366,   192,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    34,   115,    81,   369,    -1,
      34,    81,   658,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   571,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   658,    30,    -1,    34,
     267,   615,    -1,    34,   113,   154,   375,    -1,    96,   554,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   421,    -1,    34,   379,   144,   421,    -1,    34,
     379,   139,    -1,    34,   379,   139,   144,   421,    -1,   114,
     120,   658,    -1,   114,   120,   658,   551,    -1,   380,   114,
     120,   658,    -1,   380,   114,   120,   658,   551,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   189,
      -1,    28,    -1,    28,   158,   382,   189,    -1,   511,    -1,
     382,   109,   511,    -1,    34,   384,    -1,    34,   380,   384,
      -1,   385,    -1,   386,    -1,    48,   659,   387,   404,    -1,
      48,   659,   387,   139,    -1,    76,    48,   659,   387,   404,
      -1,    76,    48,   659,   387,   139,    -1,   158,   189,    -1,
     158,   388,   189,    -1,   158,   189,    96,   552,    -1,   158,
     388,   189,    96,   552,    -1,   389,    -1,   388,   109,   389,
      -1,   120,   658,    -1,   120,   658,   551,    -1,    34,   293,
     658,    -1,    34,   293,   658,    96,   391,    -1,    34,   380,
     293,   658,    -1,    34,   380,   293,   658,    96,   391,    -1,
     558,    -1,   558,   553,    -1,   652,    -1,   652,   553,    -1,
      34,   301,   658,   305,   233,   502,   172,   393,    -1,    34,
     380,   301,   658,   305,   233,   502,   172,   393,    -1,   394,
      -1,   393,   109,   394,    -1,   502,    -1,   502,   551,    -1,
     502,   457,    -1,   502,   551,   457,    -1,    34,   309,   310,
     658,   305,   293,   658,   120,   658,   311,   421,    -1,    34,
     309,   310,   658,   305,   293,   658,   231,   120,   658,   311,
     299,   312,   502,    -1,    34,   309,   310,   658,   305,   293,
     658,   313,   231,   120,   658,   311,   421,    -1,    34,   309,
     310,   658,   314,   312,   263,   293,   658,   231,   120,   658,
     312,   502,   201,   293,   658,   231,   120,   658,   312,   502,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   155,   400,   186,    -1,   155,   398,
     186,    -1,   155,   398,   186,    -1,   406,   192,    -1,   406,
     109,   407,    -1,   114,   407,    -1,   380,   114,   407,    -1,
     120,   658,    -1,   120,   658,   551,    -1,   120,   658,   144,
     421,    -1,   120,   658,   551,   144,   421,    -1,   120,   658,
     144,   421,   192,    -1,   422,   192,    -1,   246,   248,   421,
     192,    -1,   249,   158,   420,   189,   401,    -1,   244,   247,
     192,    -1,   245,   247,   192,    -1,   432,   414,    -1,   188,
     401,    -1,    49,   158,   420,   189,   200,   401,   128,   401,
      -1,   250,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     251,   588,   402,    -1,   192,    -1,   421,    -1,   420,   109,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   584,    -1,   422,    -1,   476,    -1,
     458,    -1,   577,    -1,   578,    -1,   580,    -1,   579,    -1,
     581,    -1,   649,    -1,   647,    -1,   650,    -1,   651,    -1,
     648,    -1,   432,   424,    -1,   188,   421,    -1,    68,   290,
      -1,    73,   290,    -1,   220,    -1,   260,    -1,    57,   260,
      -1,   426,   443,    79,   421,    -1,   426,    79,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    43,   120,   658,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   120,   435,    -1,
     434,     1,   435,    -1,   434,     3,    -1,    47,    -1,   263,
      -1,   436,    -1,   435,   109,   120,   436,    -1,   435,   109,
     436,    -1,   658,   149,   421,    -1,   658,    37,   129,   149,
     421,    -1,   658,   551,   149,   421,    -1,   658,   551,    37,
     129,   149,   421,    -1,   658,   437,   149,   421,    -1,   658,
      37,   129,   437,   149,   421,    -1,   658,   551,   437,   149,
     421,    -1,   658,   551,    37,   129,   437,   149,   421,    -1,
     658,   438,   149,   421,    -1,   658,   551,   438,   149,   421,
      -1,   658,   437,   438,   149,   421,    -1,   658,   551,   437,
     438,   149,   421,    -1,    98,   120,   658,    -1,   279,   120,
     658,    -1,    52,   440,    -1,   441,    -1,   440,   109,   441,
      -1,   120,   658,   144,   421,    -1,   120,   658,   551,   144,
     421,    -1,   438,   144,   421,    -1,   120,   658,   551,   438,
     144,   421,    -1,   120,   658,   149,   421,    -1,   120,   658,
     551,   149,   421,    -1,   444,    -1,   120,   658,    -1,   120,
     658,   444,    -1,   437,    -1,   437,   445,    -1,   445,    -1,
      60,   120,   658,    55,   120,   658,    -1,    55,   120,   658,
      -1,    60,   120,   658,    -1,   214,   421,    -1,   173,   172,
     448,    -1,   449,    -1,   448,   109,   449,    -1,   120,   658,
      -1,   120,   658,   144,   421,    -1,   120,   658,   551,   144,
     421,    -1,   120,   658,   551,   144,   421,   450,    -1,   120,
     658,   144,   421,   450,    -1,   120,   658,   450,    -1,   108,
     656,    -1,   170,   172,   452,    -1,    71,   170,   172,   452,
      -1,   453,    -1,   452,   109,   453,    -1,   421,    -1,   421,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   455,   456,
      -1,   455,   457,    -1,   456,   457,    -1,   455,   456,   457,
      -1,    97,    -1,   118,    -1,   129,   130,    -1,   129,   131,
      -1,   108,   656,    -1,    69,   120,   459,   190,   421,    -1,
     137,   120,   459,   190,   421,    -1,   460,    -1,   459,   109,
     120,   460,    -1,   658,   149,   421,    -1,   658,   551,   149,
     421,    -1,    74,   158,   420,   189,   462,   115,   188,   421,
      -1,   463,    -1,   462,   463,    -1,   464,   188,   421,    -1,
     102,   421,    -1,   464,   102,   421,    -1,    74,   158,   420,
     189,   466,   115,   188,   401,    -1,   467,    -1,   466,   467,
      -1,   464,   188,   401,    -1,    75,   158,   420,   189,   470,
     115,   188,   421,    -1,    75,   158,   420,   189,   470,   115,
     120,   658,   188,   421,    -1,    75,   158,   420,   189,   472,
     115,   188,   401,    -1,    75,   158,   420,   189,   470,   115,
     120,   658,   188,   401,    -1,   471,    -1,   470,   471,    -1,
     102,   474,   188,   421,    -1,   102,   120,   658,    96,   474,
     188,   421,    -1,   473,    -1,   472,   473,    -1,   102,   474,
     188,   401,    -1,   102,   120,   658,    96,   474,   188,   401,
      -1,   552,    -1,   474,   212,   552,    -1,    49,   158,   420,
     189,   200,   421,   128,   421,    -1,   477,    -1,   476,   169,
     477,    -1,   478,    -1,   477,    94,   478,    -1,   479,    -1,
     266,   478,    -1,   480,    -1,   480,   497,   480,    -1,   481,
      -1,   481,   255,    72,   589,   482,    -1,   483,    -1,   483,
     101,   481,    -1,    -1,   641,    -1,   484,    -1,   484,   201,
     484,    -1,   485,    -1,   484,   178,   485,    -1,   484,   160,
     485,    -1,   486,    -1,   485,   196,   486,    -1,   485,   119,
     486,    -1,   485,   148,   486,    -1,   485,   161,   486,    -1,
     487,    -1,   486,   203,   487,    -1,   486,   212,   487,    -1,
     488,    -1,   487,   152,   488,    -1,   487,   138,   488,    -1,
     489,    -1,   489,    51,   237,   552,    -1,   490,    -1,   490,
     202,    96,   552,    -1,   491,    -1,   491,   103,    96,   492,
      -1,   493,    -1,   493,   104,    96,   492,    -1,   557,    -1,
     557,   146,    -1,   495,    -1,   494,   495,    -1,   178,    -1,
     160,    -1,   494,   178,    -1,   494,   160,    -1,   498,    -1,
     496,    -1,   499,    -1,   502,    -1,   496,   195,   502,    -1,
     205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,
     206,    -1,    77,   155,   399,   186,    -1,    77,   228,   155,
     399,   186,    -1,    77,   227,   155,   399,   186,    -1,    77,
      78,   569,   155,   399,   186,    -1,   500,   155,   186,    -1,
     500,   155,   420,   186,    -1,   501,    -1,   500,   501,    -1,
     179,   658,    17,    -1,   179,    18,    -1,   179,    19,    -1,
     503,    -1,   504,    -1,   507,    -1,   658,    -1,   506,    -1,
     196,    -1,    11,    -1,    12,    -1,    20,    -1,   510,    -1,
     507,   508,    -1,   507,   158,   189,    -1,   507,   158,   520,
     189,    -1,   507,   121,   657,    -1,   507,   121,   515,    -1,
     507,   121,   514,    -1,   507,   121,   571,    -1,   509,    -1,
     508,   509,    -1,   156,   420,   187,    -1,   511,    -1,   514,
      -1,   515,    -1,   516,    -1,   519,    -1,   524,    -1,   517,
      -1,   518,    -1,   521,    -1,   403,    -1,   645,    -1,   642,
      -1,   643,    -1,   644,    -1,   512,    -1,   571,    -1,   513,
      -1,   221,    -1,   112,    -1,   151,    -1,   126,    -1,   222,
      -1,   223,    -1,   120,   658,    -1,   158,   189,    -1,   158,
     420,   189,    -1,   121,    -1,   171,   155,   420,   186,    -1,
     204,   155,   420,   186,    -1,   659,   158,   189,    -1,   659,
     158,   520,   189,    -1,   146,    -1,   520,   109,   146,    -1,
     421,    -1,   520,   109,   421,    -1,   522,    -1,   523,    -1,
     658,   147,   151,    -1,    48,   387,   404,    -1,   525,    -1,
     543,    -1,   526,    -1,   540,    -1,   541,    -1,   159,   658,
     530,   132,    -1,   159,   658,   530,   199,   197,   658,   530,
     199,    -1,   159,   658,   528,   530,   132,    -1,   159,   658,
     528,   530,   199,   197,   658,   530,   199,    -1,   159,   658,
     530,   199,   527,   197,   658,   530,   199,    -1,   159,   658,
     528,   530,   199,   527,   197,   658,   530,   199,    -1,   538,
      -1,   527,   538,    -1,   529,    -1,   528,   529,    -1,    36,
     658,   530,   134,   530,   531,    -1,    -1,    36,    -1,   185,
     532,   185,    -1,    95,   534,    95,    -1,    -1,   533,    -1,
     136,    -1,   536,    -1,   533,   136,    -1,   533,   536,    -1,
      -1,   535,    -1,   135,    -1,   537,    -1,   535,   135,    -1,
     535,   537,    -1,    29,    -1,   539,    -1,     5,    -1,   539,
      -1,   525,    -1,    10,    -1,   542,    -1,   539,    -1,     9,
      -1,   125,    -1,   127,    -1,   155,   399,   186,    -1,   215,
      31,   216,    -1,   215,   216,    -1,   176,   657,   177,    -1,
     176,   657,     8,    -1,   105,     7,    -1,   544,    -1,   545,
      -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,   550,
      -1,    44,   155,   399,   186,    -1,    21,   398,   186,    -1,
      46,   155,   420,   186,   155,   398,   186,    -1,    22,   398,
     186,    -1,    99,   155,   420,   186,   155,   398,   186,    -1,
      72,   155,   399,   186,    -1,    40,   155,   399,   186,    -1,
      23,   398,   186,    -1,    61,   155,   420,   186,   155,   398,
     186,    -1,    24,   399,   186,    -1,   162,   155,   420,   186,
     155,   399,   186,    -1,    96,   552,    -1,   554,    -1,   554,
     553,    -1,   213,   158,   189,    -1,   158,   189,    -1,   146,
      -1,   196,    -1,   178,    -1,   556,    -1,   558,    -1,   154,
     158,   189,    -1,   154,    -1,   326,   158,   189,    -1,   326,
      -1,   572,    -1,   575,    -1,   652,    -1,   552,    -1,   555,
     109,   552,    -1,   658,    -1,   658,    -1,   560,    -1,   567,
      -1,   565,    -1,   568,    -1,   566,    -1,   564,    -1,   563,
      -1,   562,    -1,   561,    -1,   559,    -1,   231,   158,   189,
      -1,    45,   158,   189,    -1,    45,   158,   567,   189,    -1,
      45,   158,   568,   189,    -1,    54,   158,   189,    -1,    72,
     158,   189,    -1,    40,   158,   189,    -1,    61,   158,   189,
      -1,    61,   158,   657,   189,    -1,    61,   158,    30,   189,
      -1,    99,   158,   189,    -1,    99,   158,   658,   189,    -1,
      99,   158,   658,   109,   569,   189,    -1,    99,   158,   196,
     189,    -1,    99,   158,   196,   109,   569,   189,    -1,    63,
     158,   658,   189,    -1,    46,   158,   189,    -1,    46,   158,
     658,   189,    -1,    46,   158,   658,   109,   569,   189,    -1,
      46,   158,   658,   109,   570,   189,    -1,    46,   158,   196,
     189,    -1,    46,   158,   196,   109,   569,   189,    -1,    46,
     158,   196,   109,   570,   189,    -1,    64,   158,   658,   189,
      -1,   658,    -1,   658,   146,    -1,    30,    -1,   573,    -1,
     574,    -1,    48,   158,   196,   189,    -1,    48,   158,   189,
      96,   552,    -1,    48,   158,   555,   189,    96,   552,    -1,
     158,   554,   189,    -1,    34,   226,   227,    -1,    34,   226,
     228,    -1,    34,   226,   229,    -1,   232,   231,   421,   239,
     421,    -1,   232,   231,   421,    96,   238,   239,   421,    -1,
     232,   231,   421,    96,   240,   239,   421,    -1,   232,   231,
     421,   224,   421,    -1,   232,   231,   421,   225,   421,    -1,
     232,   233,   421,   239,   421,    -1,   232,   233,   421,    96,
     238,   239,   421,    -1,   232,   233,   421,    96,   240,   239,
     421,    -1,   232,   233,   421,   224,   421,    -1,   232,   233,
     421,   225,   421,    -1,   230,   231,   421,    -1,   230,   233,
     421,    -1,   235,   231,   421,   243,   421,    -1,   235,   236,
     237,   231,   421,   243,   421,    -1,   234,   231,   421,    96,
     421,    -1,   242,   120,   582,   241,   421,   188,   421,    -1,
     583,    -1,   582,   109,   120,   583,    -1,   658,   144,   421,
      -1,   250,   155,   420,   186,   585,    -1,   586,    -1,   585,
     586,    -1,   251,   588,   587,    -1,   155,   420,   186,    -1,
     505,    -1,   588,   212,   505,    -1,   592,   590,    -1,    -1,
     591,    -1,   610,    -1,   591,   610,    -1,   593,    -1,   592,
     268,   593,    -1,   594,    -1,   593,   264,   594,    -1,   595,
      -1,   594,   266,   149,   595,    -1,   596,    -1,   265,   596,
      -1,   600,   597,   598,    -1,    -1,   615,    -1,    -1,   599,
      -1,   288,   155,   420,   186,    -1,   604,   601,    -1,   158,
     589,   189,    -1,   602,    -1,    -1,   637,    -1,   500,   155,
     603,   186,    -1,    -1,   589,    -1,   605,   606,    -1,   511,
      -1,   155,   420,   186,    -1,    -1,   607,    -1,   254,   608,
      -1,   253,   609,    -1,   276,    -1,    -1,    80,    -1,    -1,
     292,    -1,   611,    -1,   612,    -1,   613,    -1,   639,    -1,
     636,    -1,   171,    -1,   290,   484,   614,    -1,   259,   638,
     614,    -1,   292,    -1,   282,    -1,   275,    -1,   252,   616,
      -1,   615,   252,   616,    -1,   617,    -1,   618,    -1,   619,
      -1,   634,    -1,   620,    -1,   628,    -1,   621,    -1,   635,
      -1,   102,   280,    -1,   102,   269,    -1,   272,    -1,   287,
      -1,   257,   280,    -1,   257,   269,    -1,    58,   658,    30,
      -1,   283,    -1,    56,   283,    -1,   285,   622,    -1,   285,
     158,   622,   623,   189,    -1,    56,   285,    -1,   625,    -1,
     115,    -1,    -1,   109,   624,    -1,   625,    -1,   624,   109,
     625,    -1,    98,    30,   626,   627,    -1,    -1,   277,    30,
      -1,    -1,   638,   271,    -1,   284,   292,   629,   631,    -1,
     284,   292,   115,   631,    -1,    56,   284,   292,    -1,    98,
      30,    -1,   158,   630,   189,    -1,    30,    -1,   630,   109,
      30,    -1,    -1,   632,    -1,   633,    -1,   632,   633,    -1,
     203,   629,    -1,   138,   629,    -1,   270,    30,    -1,   289,
      -1,    56,   289,    -1,    98,   220,    -1,    98,   260,    -1,
     261,   256,    -1,   273,   638,   286,    -1,   262,   484,    -1,
      98,   131,   484,    -1,    98,    53,   484,    -1,   263,   484,
     201,   484,    -1,   278,   640,    -1,   258,   640,    -1,   281,
      -1,   274,    -1,   291,   256,   486,    -1,   156,   187,    -1,
     156,   420,   187,    -1,   316,   317,    -1,   316,   420,   317,
      -1,   318,   319,    -1,   318,   420,   319,    -1,   155,   646,
     186,    -1,   657,   123,   421,    -1,   421,   123,   421,    -1,
     646,   109,   421,   123,   421,    -1,   646,   109,   657,   123,
     421,    -1,   232,   320,   421,   239,   421,    -1,   232,   320,
     646,   239,   421,    -1,   232,   320,   421,   239,   421,    98,
     322,   421,    -1,   232,   421,   239,   421,    -1,   232,   646,
     239,   421,    -1,   232,   421,   239,   421,    98,   322,   421,
      -1,   321,   320,   421,   239,   421,    -1,   321,   421,   239,
     421,    -1,   230,   320,   507,    -1,   230,   507,    -1,   234,
     320,   507,    96,   421,    -1,   234,   507,    96,   421,    -1,
     235,   320,   236,   237,   507,   243,   421,    -1,   235,   236,
     237,   507,   243,   421,    -1,   653,    -1,   654,    -1,   655,
      -1,   325,   158,   189,    -1,   325,    -1,   323,   158,   189,
      -1,   323,    -1,   324,   158,   189,    -1,   324,    -1,    30,
      -1,    16,    -1,   658,    -1,   659,    -1,    99,    -1,    40,
      -1,    45,    -1,    54,    -1,    46,    -1,    49,    -1,   231,
      -1,    61,    -1,    63,    -1,    64,    -1,    72,    -1,    75,
      -1,    74,    -1,   213,    -1,   249,    -1,   660,    -1,    25,
      -1,   217,    -1,   129,    -1,    39,    -1,   267,    -1,    38,
      -1,   228,    -1,   227,    -1,   148,    -1,    44,    -1,   265,
      -1,   266,    -1,   280,    -1,   269,    -1,   257,    -1,   291,
      -1,   283,    -1,   285,    -1,   284,    -1,   289,    -1,   261,
      -1,   256,    -1,    80,    -1,   220,    -1,   260,    -1,    53,
      -1,   229,    -1,   242,    -1,   308,    -1,   236,    -1,   205,
      -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,    98,    -1,   113,    -1,   114,    -1,   188,    -1,    47,
      -1,    37,    -1,    68,    -1,    73,    -1,    60,    -1,    55,
      -1,    57,    -1,    79,    -1,    43,    -1,   149,    -1,    52,
      -1,   214,    -1,   172,    -1,   173,    -1,   170,    -1,    71,
      -1,    97,    -1,   118,    -1,   130,    -1,   131,    -1,   108,
      -1,    69,    -1,   137,    -1,   190,    -1,   102,    -1,    96,
      -1,   200,    -1,   128,    -1,   169,    -1,    94,    -1,    51,
      -1,   237,    -1,   103,    -1,   201,    -1,   119,    -1,   161,
      -1,   203,    -1,   152,    -1,   138,    -1,    77,    -1,    78,
      -1,   104,    -1,   202,    -1,   153,    -1,   184,    -1,   198,
      -1,   162,    -1,   139,    -1,   133,    -1,   168,    -1,   150,
      -1,   167,    -1,    34,    -1,    41,    -1,    59,    -1,   115,
      -1,    42,    -1,    58,    -1,   219,    -1,    50,    -1,    62,
      -1,    35,    -1,    48,    -1,   279,    -1,   255,    -1,   288,
      -1,   290,    -1,   259,    -1,   273,    -1,   286,    -1,   278,
      -1,   258,    -1,   272,    -1,   287,    -1,   277,    -1,   271,
      -1,   270,    -1,   254,    -1,   253,    -1,   262,    -1,   263,
      -1,   292,    -1,   282,    -1,   281,    -1,   276,    -1,   274,
      -1,   275,    -1,   241,    -1,   238,    -1,   225,    -1,   224,
      -1,   226,    -1,   243,    -1,   233,    -1,   240,    -1,   239,
      -1,    67,    -1,    65,    -1,    76,    -1,   171,    -1,   204,
      -1,   248,    -1,   246,    -1,   247,    -1,   244,    -1,   245,
      -1,   250,    -1,   251,    -1,   252,    -1,    66,    -1,   301,
      -1,   299,    -1,   300,    -1,   305,    -1,   306,    -1,   307,
      -1,   302,    -1,   303,    -1,   304,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   315,    -1,    92,    -1,   107,    -1,   116,
      -1,   174,    -1,   182,    -1,   191,    -1,   140,    -1,    93,
      -1,   117,    -1,   141,    -1,   183,    -1,   322,    -1,    26,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  jsoniq_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    50,    57,    61,    65,
      71,    73,    77,    81,    87,    93,    95,    99,   103,   109,
     116,   118,   122,   126,   128,   130,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   156,   160,   165,
     169,   173,   177,   181,   185,   191,   197,   203,   209,   215,
     221,   223,   225,   229,   233,   238,   244,   251,   253,   257,
     261,   265,   269,   276,   282,   291,   297,   303,   309,   311,
     315,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     340,   345,   347,   350,   354,   356,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   379,   383,   388,   392,   394,
     396,   398,   401,   404,   409,   413,   419,   423,   428,   433,
     439,   441,   444,   446,   451,   453,   458,   460,   464,   467,
     471,   473,   475,   480,   485,   491,   497,   500,   504,   509,
     515,   517,   521,   524,   528,   532,   538,   543,   550,   552,
     555,   557,   560,   569,   579,   581,   585,   587,   590,   593,
     597,   609,   624,   638,   661,   663,   665,   667,   668,   670,
     672,   673,   675,   678,   680,   683,   688,   690,   692,   694,
     696,   698,   700,   702,   704,   706,   708,   710,   712,   714,
     718,   722,   726,   729,   733,   736,   740,   743,   747,   752,
     758,   764,   767,   772,   778,   782,   786,   789,   792,   801,
     805,   807,   810,   814,   816,   818,   822,   826,   828,   830,
     832,   834,   836,   838,   840,   842,   844,   846,   848,   850,
     852,   854,   856,   858,   860,   862,   865,   868,   871,   874,
     876,   878,   881,   886,   890,   896,   901,   905,   907,   909,
     911,   913,   915,   917,   919,   921,   923,   926,   930,   934,
     937,   939,   941,   943,   948,   952,   956,   962,   967,   974,
     979,   986,   992,  1000,  1005,  1011,  1017,  1024,  1028,  1032,
    1035,  1037,  1041,  1046,  1052,  1056,  1063,  1068,  1074,  1076,
    1079,  1083,  1085,  1088,  1090,  1097,  1101,  1105,  1108,  1112,
    1114,  1118,  1121,  1126,  1132,  1139,  1145,  1149,  1152,  1156,
    1161,  1163,  1167,  1169,  1172,  1174,  1176,  1178,  1181,  1184,
    1187,  1191,  1193,  1195,  1198,  1201,  1204,  1210,  1216,  1218,
    1223,  1227,  1232,  1241,  1243,  1246,  1250,  1253,  1257,  1266,
    1268,  1271,  1275,  1284,  1295,  1304,  1315,  1317,  1320,  1325,
    1333,  1335,  1338,  1343,  1351,  1353,  1357,  1366,  1368,  1372,
    1374,  1378,  1380,  1383,  1385,  1389,  1391,  1397,  1399,  1403,
    1404,  1406,  1408,  1412,  1414,  1418,  1422,  1424,  1428,  1432,
    1436,  1440,  1442,  1446,  1450,  1452,  1456,  1460,  1462,  1467,
    1469,  1474,  1476,  1481,  1483,  1488,  1490,  1493,  1495,  1498,
    1500,  1502,  1505,  1508,  1510,  1512,  1514,  1516,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1537,  1543,  1549,  1556,  1560,
    1565,  1567,  1570,  1574,  1577,  1580,  1582,  1584,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1603,  1607,  1612,  1616,
    1620,  1624,  1628,  1630,  1633,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1669,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1686,
    1689,  1693,  1695,  1700,  1705,  1709,  1714,  1716,  1720,  1722,
    1726,  1728,  1730,  1734,  1738,  1740,  1742,  1744,  1746,  1748,
    1753,  1762,  1768,  1778,  1788,  1799,  1801,  1804,  1806,  1809,
    1816,  1817,  1819,  1823,  1827,  1828,  1830,  1832,  1834,  1837,
    1840,  1841,  1843,  1845,  1847,  1850,  1853,  1855,  1857,  1859,
    1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1879,  1883,
    1886,  1890,  1894,  1897,  1899,  1901,  1903,  1905,  1907,  1909,
    1911,  1916,  1920,  1928,  1932,  1940,  1945,  1950,  1954,  1962,
    1966,  1974,  1977,  1979,  1982,  1986,  1989,  1991,  1993,  1995,
    1997,  1999,  2003,  2005,  2009,  2011,  2013,  2015,  2017,  2019,
    2023,  2025,  2027,  2029,  2031,  2033,  2035,  2037,  2039,  2041,
    2043,  2045,  2047,  2051,  2055,  2060,  2065,  2069,  2073,  2077,
    2081,  2086,  2091,  2095,  2100,  2107,  2112,  2119,  2124,  2128,
    2133,  2140,  2147,  2152,  2159,  2166,  2171,  2173,  2176,  2178,
    2180,  2182,  2187,  2193,  2200,  2204,  2208,  2212,  2216,  2222,
    2230,  2238,  2244,  2250,  2256,  2264,  2272,  2278,  2284,  2288,
    2292,  2298,  2306,  2312,  2320,  2322,  2327,  2331,  2337,  2339,
    2342,  2346,  2350,  2352,  2356,  2359,  2360,  2362,  2364,  2367,
    2369,  2373,  2375,  2379,  2381,  2386,  2388,  2391,  2395,  2396,
    2398,  2399,  2401,  2406,  2409,  2413,  2415,  2416,  2418,  2423,
    2424,  2426,  2429,  2431,  2435,  2436,  2438,  2441,  2444,  2446,
    2447,  2449,  2450,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2468,  2472,  2474,  2476,  2478,  2481,  2485,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2501,  2504,  2507,  2509,  2511,  2514,
    2517,  2521,  2523,  2526,  2529,  2535,  2538,  2540,  2542,  2543,
    2546,  2548,  2552,  2557,  2558,  2561,  2562,  2565,  2570,  2575,
    2579,  2582,  2586,  2588,  2592,  2593,  2595,  2597,  2600,  2603,
    2606,  2609,  2611,  2614,  2617,  2620,  2623,  2627,  2630,  2634,
    2638,  2643,  2646,  2649,  2651,  2653,  2657,  2660,  2664,  2667,
    2671,  2674,  2678,  2682,  2686,  2690,  2696,  2702,  2708,  2714,
    2723,  2728,  2733,  2741,  2747,  2752,  2756,  2759,  2765,  2770,
    2778,  2785,  2787,  2789,  2791,  2795,  2797,  2801,  2803,  2807,
    2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,
    2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,
    2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,
    2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,
    2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,
    2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,
    2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,
    2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,
    2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,
    2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,
    3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,
    3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,
    3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,
    3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,
    3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,
    3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,
    3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,
    3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,  3185,  3187,
    3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,  3205,  3207,
    3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,  3225,  3227,
    3229,  3231,  3233,  3235,  3237,  3239
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1068,  1068,  1069,  1073,  1077,  1085,  1091,  1095,  1104,
    1110,  1118,  1124,  1135,  1140,  1144,  1149,  1158,  1165,  1172,
    1181,  1188,  1196,  1204,  1212,  1223,  1228,  1235,  1242,  1254,
    1264,  1271,  1278,  1290,  1291,  1292,  1293,  1294,  1299,  1300,
    1301,  1302,  1303,  1304,  1305,  1308,  1313,  1318,  1326,  1334,
    1342,  1347,  1355,  1360,  1368,  1373,  1381,  1386,  1391,  1396,
    1404,  1406,  1409,  1419,  1424,  1432,  1440,  1451,  1458,  1469,
    1474,  1482,  1489,  1496,  1505,  1518,  1526,  1533,  1543,  1550,
    1557,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1580,
    1586,  1595,  1602,  1612,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1636,  1644,  1652,  1660,  1667,  1675,
    1682,  1687,  1695,  1703,  1717,  1731,  1748,  1753,  1761,  1769,
    1780,  1785,  1794,  1799,  1806,  1811,  1821,  1826,  1835,  1841,
    1854,  1859,  1867,  1878,  1893,  1905,  1920,  1925,  1930,  1935,
    1943,  1950,  1961,  1966,  1976,  1985,  1994,  2003,  2015,  2019,
    2025,  2029,  2039,  2049,  2062,  2068,  2077,  2082,  2089,  2096,
    2107,  2117,  2127,  2137,  2155,  2175,  2179,  2184,  2191,  2195,
    2200,  2207,  2212,  2224,  2231,  2241,  2256,  2257,  2258,  2259,
    2260,  2261,  2262,  2264,  2265,  2266,  2267,  2268,  2269,  2274,
    2282,  2304,  2312,  2320,  2327,  2334,  2345,  2354,  2363,  2372,
    2385,  2393,  2401,  2409,  2424,  2429,  2437,  2451,  2468,  2493,
    2501,  2508,  2519,  2528,  2535,  2540,  2553,  2570,  2571,  2572,
    2573,  2574,  2575,  2580,  2581,  2584,  2585,  2586,  2587,  2588,
    2591,  2592,  2593,  2594,  2595,  2600,  2614,  2622,  2627,  2635,
    2640,  2645,  2653,  2662,  2674,  2684,  2697,  2705,  2706,  2707,
    2712,  2713,  2714,  2715,  2716,  2721,  2728,  2738,  2744,  2753,
    2762,  2763,  2771,  2778,  2786,  2798,  2808,  2818,  2828,  2838,
    2848,  2858,  2868,  2879,  2888,  2898,  2908,  2924,  2933,  2942,
    2950,  2956,  2968,  2976,  2986,  2994,  3006,  3012,  3023,  3025,
    3029,  3037,  3041,  3046,  3050,  3054,  3058,  3068,  3076,  3083,
    3089,  3099,  3103,  3107,  3115,  3123,  3131,  3143,  3151,  3157,
    3167,  3173,  3183,  3187,  3197,  3203,  3209,  3215,  3224,  3233,
    3242,  3255,  3259,  3267,  3273,  3283,  3291,  3300,  3313,  3320,
    3332,  3336,  3348,  3355,  3361,  3370,  3377,  3383,  3394,  3401,
    3407,  3416,  3425,  3432,  3443,  3450,  3462,  3468,  3480,  3486,
    3497,  3503,  3514,  3520,  3531,  3537,  3548,  3557,  3561,  3570,
    3574,  3581,  3585,  3598,  3602,  3682,  3686,  3698,  3702,  3710,
    3713,  3720,  3724,  3733,  3737,  3741,  3749,  3753,  3759,  3765,
    3771,  3781,  3785,  3789,  3797,  3801,  3807,  3817,  3821,  3831,
    3835,  3845,  3849,  3859,  3863,  3873,  3877,  3886,  3890,  3898,
    3902,  3906,  3910,  3920,  3924,  3928,  3935,  3940,  3948,  3952,
    3956,  3960,  3964,  3968,  3992,  3996,  4000,  4004,  4015,  4021,
    4031,  4037,  4047,  4051,  4055,  4118,  4140,  4168,  4332,  4336,
    4346,  4350,  4354,  4358,  4367,  4371,  4375,  4379,  4383,  4388,
    4392,  4396,  4405,  4411,  4421,  4429,  4433,  4437,  4441,  4445,
    4449,  4453,  4457,  4461,  4465,  4470,  4474,  4478,  4482,  4490,
    4494,  4498,  4502,  4510,  4517,  4524,  4534,  4538,  4546,  4554,
    4558,  4566,  4574,  4582,  4636,  4640,  4662,  4668,  4674,  4680,
    4690,  4694,  4702,  4710,  4722,  4726,  4734,  4738,  4742,  4750,
    4758,  4775,  4783,  4800,  4819,  4843,  4849,  4860,  4866,  4877,
    4886,  4888,  4892,  4897,  4907,  4910,  4917,  4923,  4929,  4936,
    4948,  4951,  4958,  4964,  4970,  4977,  4988,  4992,  5000,  5004,
    5012,  5016,  5020,  5025,  5034,  5038,  5042,  5046,  5054,  5059,
    5067,  5072,  5080,  5088,  5093,  5098,  5103,  5108,  5113,  5118,
    5124,  5132,  5136,  5153,  5157,  5165,  5173,  5181,  5185,  5193,
    5197,  5205,  5213,  5217,  5221,  5226,  5261,  5267,  5273,  5283,
    5287,  5291,  5296,  5300,  5305,  5309,  5313,  5317,  5324,  5330,
    5340,  5348,  5356,  5360,  5364,  5368,  5372,  5376,  5380,  5384,
    5388,  5392,  5400,  5408,  5412,  5416,  5424,  5431,  5439,  5447,
    5451,  5455,  5463,  5467,  5473,  5479,  5483,  5493,  5501,  5505,
    5511,  5520,  5529,  5535,  5541,  5551,  5568,  5575,  5590,  5617,
    5621,  5629,  5637,  5641,  5652,  5669,  5675,  5681,  5691,  5695,
    5701,  5707,  5711,  5717,  5721,  5727,  5733,  5740,  5750,  5755,
    5763,  5769,  5779,  5801,  5810,  5816,  5829,  5843,  5850,  5856,
    5866,  5875,  5883,  5889,  5907,  5915,  5919,  5926,  5931,  5939,
    5943,  5950,  5954,  5961,  5965,  5972,  5976,  5985,  5998,  6001,
    6009,  6012,  6020,  6028,  6036,  6040,  6048,  6051,  6059,  6071,
    6074,  6082,  6094,  6100,  6110,  6113,  6121,  6125,  6129,  6137,
    6140,  6148,  6151,  6159,  6163,  6167,  6171,  6175,  6183,  6191,
    6203,  6215,  6219,  6223,  6231,  6237,  6247,  6251,  6255,  6259,
    6263,  6267,  6271,  6275,  6283,  6287,  6291,  6295,  6303,  6309,
    6319,  6329,  6333,  6341,  6351,  6362,  6369,  6373,  6381,  6384,
    6391,  6396,  6405,  6415,  6418,  6425,  6429,  6437,  6446,  6453,
    6463,  6467,  6474,  6480,  6490,  6493,  6500,  6505,  6517,  6525,
    6537,  6545,  6549,  6557,  6561,  6565,  6573,  6581,  6585,  6589,
    6593,  6601,  6609,  6621,  6625,  6633,  6647,  6651,  6658,  6663,
    6671,  6676,  6685,  6693,  6700,  6706,  6713,  6724,  6730,  6740,
    6745,  6751,  6761,  6768,  6772,  6779,  6801,  6826,  6851,  6879,
    6904,  6932,  6936,  6940,  6947,  6952,  6959,  6964,  6971,  6976,
    6988,  6992,  6993,  7006,  7007,  7008,  7009,  7010,  7011,  7013,
    7014,  7015,  7016,  7017,  7018,  7019,  7020,  7021,  7022,  7026,
    7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,  7035,  7036,
    7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,  7045,  7046,
    7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,  7055,  7056,
    7057,  7058,  7059,  7060,  7061,  7062,  7063,  7064,  7065,  7066,
    7067,  7068,  7069,  7070,  7071,  7072,  7073,  7074,  7075,  7076,
    7077,  7078,  7079,  7080,  7081,  7082,  7083,  7084,  7085,  7086,
    7087,  7088,  7089,  7090,  7091,  7092,  7093,  7094,  7095,  7096,
    7097,  7098,  7099,  7100,  7101,  7102,  7103,  7104,  7105,  7106,
    7107,  7108,  7109,  7110,  7111,  7112,  7113,  7114,  7115,  7116,
    7117,  7118,  7119,  7120,  7121,  7122,  7123,  7124,  7125,  7126,
    7127,  7128,  7129,  7130,  7131,  7132,  7133,  7134,  7135,  7136,
    7137,  7138,  7139,  7140,  7141,  7142,  7143,  7144,  7145,  7146,
    7147,  7148,  7149,  7150,  7151,  7152,  7153,  7155,  7156,  7158,
    7159,  7160,  7161,  7162,  7164,  7166,  7167,  7168,  7169,  7170,
    7171,  7172,  7173,  7174,  7175,  7176,  7177,  7178,  7179,  7180,
    7181,  7182,  7183,  7184,  7185,  7186,  7187,  7188,  7189,  7190,
    7191,  7192,  7193,  7194,  7195,  7196,  7197,  7198,  7199,  7200,
    7201,  7202,  7203,  7204,  7205,  7206,  7207,  7208,  7209,  7210,
    7211,  7212,  7213,  7214,  7215,  7216,  7217,  7218,  7219,  7220,
    7221,  7222,  7223,  7224,  7227,  7236
  };

  // Print the state stack on the debug stream.
  void
  jsoniq_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  jsoniq_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  jsoniq_parser::token_number_type
  jsoniq_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 19135;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 545;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17966 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7240 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"


namespace zorba {

/*
 *  The error member function registers the errors to the driver.
 */
void jsoniq_parser::error(zorba::jsoniq_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    ParseErrorNode* prevErr = dynamic_cast<ParseErrorNode*>(driver.get_expr());

    if (prevErr != NULL)
    {
      // Error message heuristics: if the current error message has the "(missing comma "," between expressions?)" text,
      // and the old message has a "','" text, then replace the old message with the new one. Unfortunately this 
      // makes the parser error messages harder to internationalize.
      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
        return;
    }

    // Replace the first occurrence of "unexpected "'QName'"" with "unexpected qualified name %actual_qname%"
    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());

    // remove the double quoting "''" from every token description
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

