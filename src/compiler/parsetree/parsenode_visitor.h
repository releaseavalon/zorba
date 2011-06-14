/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#pragma once
#ifndef ZORBA_PARSENODE_VISITOR_H
#define ZORBA_PARSENODE_VISITOR_H

#include "common/shared_types.h"

// Any file that includes parsenode_visitor.h will need to access the
// actual parsendoe classes.
#include "compiler/parsetree/parsenodes.h"

namespace zorba
{

/*______________________________________________________________________
|
|  Design note: Visitor pattern.  See, for example:
|  "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|  Chapter 10.
|_______________________________________________________________________*/

class parsenode_visitor
{
public:
  virtual ~parsenode_visitor() { }

  static void *no_state;

# define DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NODE )           \
  virtual void* begin_visit( NODE const& ) = 0;                 \
  virtual void end_visit( NODE const&, void *visit_state ) = 0;

  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AbbrevForwardStep );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AnyKindTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AnnotationParsenode );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AnnotationListParsenode );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AnnotationLiteralListParsenode );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AposAttrContentList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AposAttrValueContent );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ArgList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AtomicType );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AttributeTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( BaseURIDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( BoundarySpaceDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CaseClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CaseClauseList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CommentTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ConstructionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CopyNamespacesDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DefaultCollationDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DefaultNamespaceDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirAttr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirAttributeList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirAttributeValue );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirElemContentList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DocumentTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ElementTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( EmptyOrderDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ForClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FLWORClauseList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ForwardAxis );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ForwardStep );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FunctionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( GeneralComp );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ItemType );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( LetClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( LibraryModule );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Literal );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( MainModule  );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ModuleDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ModuleImport );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NameTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NamespaceDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NodeComp );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OccurrenceIndicator );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OptionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( GroupByClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( GroupSpecList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( GroupSpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( GroupCollationSpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderByClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderCollationSpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderDirSpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderEmptySpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderModifierPN );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderSpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderSpecList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderingModeDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( PITest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Param );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ParamList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( PositionalVar );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Pragma );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( PragmaList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( PredicateList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Prolog );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QVarInDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QVarInDeclList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QuoteAttrValueContent );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QuoteAttrContentList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ReverseAxis );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ReverseStep );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SIND_DeclList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SchemaAttributeTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SchemaElementTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SchemaImport );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SchemaPrefix );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SequenceType );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SignList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SingleType );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TextTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TypeName );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( URILiteralList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ValueComp );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CtxItemDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CollectionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NodeModifier );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AST_IndexDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( IndexKeySpec );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( IndexKeyList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( IntegrityConstraintDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarGetsDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarGetsDeclList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarInDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarInDeclList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VersionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VFO_DeclList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( WhereClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CountClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Wildcard );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QName );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DecimalFormatNode );

/* expressions */
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AdditiveExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AndExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AxisStep );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CDataSection );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CastExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CastableExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CommonContent );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ComparisonExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompAttrConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompCommentConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompDocConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompElemConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompPIConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CompTextConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ContextItemExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirCommentConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirElemConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirElemContent );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DirPIConstructor );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( EnclosedExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( BlockBody );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ApplyExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( Expr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ExtensionExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FLWORExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( WindowClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( WindowVarDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FLWORWinCond );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( WindowVars );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FilterExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FunctionCall );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( IfExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( InstanceofExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( IntersectExceptExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( MultiplicativeExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NumericLiteral );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( OrderedExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ParenthesizedExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( PathExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QuantifiedExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( QueryBody );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( RangeExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( RelativePathExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( StringLiteral );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TreatExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SwitchExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SwitchCaseClause );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SwitchCaseClauseList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( SwitchCaseOperandList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TypeswitchExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( UnaryExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( UnionExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( UnorderedExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ValidateExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarRef );

/* update-related */
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DeleteExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( InsertExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( RenameExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ReplaceExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( RevalidationDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TransformExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CopyVarList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( VarBinding );

/* try-catch-related */
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TryExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CatchListExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( CatchExpr );

/* full-text-related */
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTAnd );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTAnyallOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTBigUnit );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTCaseOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTContainsExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTContent );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTDiacriticsOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTDistance );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTExtensionOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTExtensionSelection );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTIgnoreOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTLanguageOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTMatchOptions );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTMildNot );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTOptionDecl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTOr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTOrder );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTPrimaryWithOptions );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTRange );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTScope );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTScoreVar );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTSelection );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTStemOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTStopWordOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTStopWords );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTStopWordsInclExcl );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTThesaurusID );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTThesaurusOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTTimes );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTUnaryNot );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTUnit );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWeight );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWildCardOption );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWindow );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWords );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWordsTimes );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FTWordsValue );

  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AssignExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ExitExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( WhileExpr );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( FlowCtlStatement );

  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( ParseErrorNode );

  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( LiteralFunctionItem );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( InlineFunction );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( AnyFunctionTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TypeList );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( TypedFunctionTest );
  DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( DynamicFunctionInvocation );

# undef DECL_PARSENODE_VISITOR_VISIT_MEM_FNS
# define DECL_PARSENODE_VISITOR_VISIT_MEM_FNS( NODE ) \
  void* begin_visit( NODE const& );                   \
  void end_visit( NODE const&, void *visit_state );

  /* Methods that deviate from the visitor pattern that are
   * needed in various situations.
   */
  virtual void intermediate_visit(RelativePathExpr const&, void*) { }
  virtual void intermediate_visit(WindowClause const&, void*) { }
  virtual void post_axis_visit(AxisStep const&, void *) { }
  virtual void post_predicate_visit(PredicateList const&, void*) { }
  virtual void post_primary_visit(FilterExpr const&, void *) { }
  virtual void pre_predicate_visit(PredicateList const&, void*) { }

  /**
   * Methods are used in the translator to check if a DirElemContent is
   * boundary whitespace.
   */
  virtual void begin_check_boundary_whitespace() {}
  virtual void check_boundary_whitespace(const DirElemContent&) {}
  virtual void end_check_boundary_whitespace() {}

  virtual bool is_root_rpe(const RelativePathExpr*) { return true; }

};

} /* namespace zorba */
#endif /* ZORBA_PARSENODE_VISITOR_H */
/* vim:set et sw=2 ts=2: */
