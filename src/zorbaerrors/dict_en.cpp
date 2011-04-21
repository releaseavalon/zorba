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

#include "dict_impl.h"

namespace zorba {
namespace err {
namespace dict {

///////////////////////////////////////////////////////////////////////////////

extern entry const dict_en[] = {

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "FOAR0001", "division by zero" },
  { "FOAR0002", "numeric operation overflow/underflow${: 1}" },
  { "FOCA0001", "\"$1\": value too large for decimal" },
  { "FOCA0002", "\"$1\": invalid lexical value${: 2}" },
  { "FOCA0003", "\"$1\": value too large for integer" },
  { "FOCA0005", "NaN supplied as float/double value" },
  { "FOCA0006", "\"$1\": string to be cast to decimal has too many digits of precision" },
  { "FOCH0001", "\"$1\": invalid code-point for XML 1.0" },
  { "FOCH0002", "\"$1\": unsuported collation${: 2}" },
  { "FOCH0003", "\"$1\": unsupported normalization form" },
  { "FOCH0004", "\"$1\": collation does not support collation units" },
  { "FODC0001", "no context document for $1() function" },
  { "FODC0002", "\"$1\": error retrieving resource${: 2}" },
  { "FODC0003", "function stability not defined" },
  { "FODC0004", "\"$1\": invalid argument to fn:collection()${: 2}" },
  { "FODC0005", "\"$1\": invalid argument to fn:doc() or fn:doc-available()" },
  { "FODC0006", "invalid content passed to fn:parse(): $1" },
  { "FODC0007", "\"$1\": base URI passed to fn:parse() is not a valid absolute URI" },
  { "FODF1280", "\"$1\": invalid decimal format name for fn:format-number()" },
  { "FODF1310", "\"$1\": invalid fn:format-number() picture string" },
  { "FODT0001", "overflow/underflow in date/time operation" },
  { "FODT0002", "overflow/underflow in duration operation" },
  { "FODT0003", "\"$1\": invalid timezone value" },
  { "FOER0000", "unidentifier error" },
  { "FOFI0001", "\"$1\": not castable to xs:language" },
  { "FOFI0002", "invalid argument in format-integer: $1" },
  { "FONS0004", "\"$1\": no namespace found for prefix" },
  { "FONS0005", "base-URI not defined in the static context" },
  { "FORG0001", "${\"1\": }invalid value for cast/constructor${: 2}" },
  { "FORG0002", "\"$1\": invalid argument to fn:resolve-uri()${: 2}" },
  { "FORG0003", "fn:zero-or-one() called with a sequnce containing more than one item" },
  { "FORG0004", "fn:one-or-more() called with a sequence containing no items" },
  { "FORG0005", "fn:exactly-one() called with a sequence containing zero or more than one item" },
  { "FORG0006", "invalid argument type${: 1}" },
  { "FORG0008", "\"$1\" & \"$2\": two arguments to fn:dateTime() have inconsistent timezones" },
  { "FORG0009", "error resolving a relative URI against a base URI in fn:resolve-uri()${: 1}" },
  { "FORX0001", "'$1': invalid regular expression flag" },
  { "FORX0002", "\"$1\": invalid regular expression${: 2}" },
  { "FORX0003", "\"$1\": regular expression matches zero-length string" },
  { "FORX0004", "\"$1\": invalid replacement string${: 2}" },
  { "FOTY0012", "\"$1\": element node of type $2 does not have a typed value" },
  { "FOTY0013", "argument to fn:data() is function item" },
  { "FOTY0014", "argument to fn:string() is a function item" },
  { "FOTY0015", "argument to fn:deep-equal() contains a function item" },
  { "FOUP0001", "first operand of fn:put() is not a node of a supported kind" },
  { "FOUP0002", "second operand of fn:put() is not a valid lexical representation of the xs:anyURI type" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef ZORBA_NO_FULL_TEXT
  { "FTDY0016", "\"$1\": invalid weight: absolute value must be in [0,1000]" },
  { "FTDY0017", "mild-not contains StringExclude" },
  { "FTDY0020", "${\"1\": }invalid wildcard syntax${: 2}" },
  { "FTST0008", "\"$1\": unknown stop-word list" },
  { "FTST0009", "\"$1\": unsupported language" },
  { "FTST0018", "\"$1\": unknown thesaurus" },
  { "FTST0019", "\"$1\": match option specified more than once" },
#endif /* ZORBA_NO_FULL_TEXT */

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "SENR0001", "\"$1\": can not serialize $2" },
  { "SEPM0004", "doctype-system parameter, or standalone parameter with a value other than \"omit\", specified" },
  { "SEPM0009", "omit-xml-declaration parameter is \"yes\" and $1" },
  { "SEPM0010", "the output method is \"xml\", the value of the undeclare-prefixes parameter is \"yes\", and the value of the version parameter is \"1.0\"" },
  { "SEPM0016", "\"$1\": value for parameter \"$2\" invalid${; $3}" },
  { "SERE0003", "serializer can't satisfy the rules for either a well-formed XML document entity or a well-formed XML external general parsed entity" },
  { "SERE0005", "invalid NCName character" },
  { "SERE0006", "\"$1\": invalid character for XML version $2" },
  { "SERE0008", "\"$1\": can not encode character as character reference here" },
  { "SERE0012", "the value of the normalization-form parameter is fully-normalized and any relevant construct of the result begins with a combining character" },
  { "SERE0014", "\"#$1\": character not allowed for HTML output method" },
  { "SERE0015", "can not use '>' within processing instruction for HTML output method" },
  { "SESU0007", "\"$1\": unsupported encoding" },
  { "SESU0011", "\"$1\": unsupported normalization form" },
  { "SESU0013", "\"$1\": unsupported $2 version; supported versions are: $3" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "XPDY0002", "\"$1\": $2" },
  { "XPDY0050", "invalid treat expression type" },
  { "XPST0001", "${\"1\": }undefined value${: 2}" },
  { "XPST0003", "invalid expression${: 1}" },
  { "XPST0005", "static type must not be empty-sequence()" },
  { "XPST0008", "\"$1\": undefined $2" },
  { "XPST0010", "\"$1\": unsupported axis" },
  { "XPST0017", "\"$1\": function call does not match signature${ with 2 arguments}" },
  { "XPST0051", "\"$1\": not defined as atomic type${: 2}" },
  { "XPST0080", "\"$1\": invalid type for \"cast\" or \"castable\" exression${: 2}" },
  { "XPST0081", "\"$1\": can not expand namespace prefix to URI" },
  { "XPST0083", "\"$1\": not a string literal" },
  { "XPTY0004", "${\"1\": }invalid type${: 2}" },
  { "XPTY0018", "path expression last step must not have nodes and atomic values" },
  { "XPTY0019", "path expression non-last step must not be an atomic value" },
  { "XPTY0020", "axis step context item is not a node" },
  { "XQDY0025", "\"$1\": duplicate attribute name" },
  { "XQDY0026", "computed processing instrucion must not contain \"?>\"" },
  { "XQDY0027", "\"$1\": unexpected validity property" },
  { "XQDY0041", "\"$1\": can not cast to xs:NCName" },
  { "XQDY0044", "\"$1\": invalid attibute node-name" },
  { "XQDY0061", "invalid validate expression operand${: 1}" },
  { "XQDY0064", "\"XML\": invalid name expression" },
  { "XQDY0072", "comment must not contain \"--\" or end with \"-\"" },
  { "XQDY0074", "${\"1\": }can not convert to expanded QName${: 2}" },
  { "XQDY0084", "validated element does not have a top-level element declaration in the in-scope element declarations${: 1}" },
  { "XQDY0091", "\"xml:id\" encountered" },
  { "XQDY0092", "\"$1\": must be either \"preserve\" or \"default\"" },
  { "XQDY0096", "\"$1\": invalid node-name" },
  { "XQST0009", "schema import not supported" },
  { "XQST0012", "invalid schema definitions" },
  { "XQST0013", "invalid pragma content" },
  { "XQST0022", "namespace declaration attribute is not a URI literal" },
  { "XQST0031", "\"$1\": $2" },
  { "XQST0032", "multiple base URI declarations" },
  { "XQST0033", "\"$1\": namespace prefix already bound to \"$2\"" },
  { "XQST0034", "\"$1\": duplicate function declaration" },
  { "XQST0035", "\"$1\": name previosly imported" },
  { "XQST0036", "\"$1\": $2" },
  { "XQST0038", "multiple default collation declarations" },
  { "XQST0039", "\"$1\": duplicate parameter name" },
  { "XQST0040", "\"$1\": non-distinct expanded attribute QName" },
  { "XQST0045", "\"$1\": invalid function namespace" },
  { "XQST0046", "\"$1\": invalid URI literal${: 2}" },
  { "XQST0047", "\"$1\": duplicate target namespace" },
  { "XQST0048", "\"$1\": not in library namespace" },
  { "XQST0049", "\"$1\": duplicate variable declaration" },
  { "XQST0054", "${\"1\": }variable must not depend on itself" },
  { "XQST0055", "multiple copy-namespaces declarations" },
  { "XQST0057", "empty target namespace" },
  { "XQST0058", "\"$1\": duplicate target namespace" },
  { "XQST0059", "\"$1\": target namespace not found" },
  { "XQST0060", "\"$1\": function name has a null namespace URI" },
  { "XQST0065", "multiple ordering mode declaraions" },
  { "XQST0066", "multiple element/type/function namespace declarations" },
  { "XQST0067", "multiple construction declarations" },
  { "XQST0068", "multiple boundary-space declarations" },
  { "XQST0069", "multiple empty order declarations" },
  { "XQST0070", "\"$1\": $2" },
  { "XQST0071", "\"$1\": duplicate namespace declaration attribute" },
  { "XQST0076", "\"$1\": unknown collation" },
  { "XQST0079", "unknown pragma or empty expression" },
  { "XQST0085", "namespace URI is empty" },
  { "XQST0087", "\"$1\": invalid encoding" },
  { "XQST0088", "empty target namespace literal" },
  { "XQST0089", "\"$1\": duplicate variable name" },
  { "XQST0090", "\"$1\": invalid character reference in XML $2" },
  { "XQST0093", "\"$1\": module must not depend on itself" },
  { "XQST0098", "properties representing characters used in picture string do not have distinct values" },
  { "XQST0106", "\"$1\": multiple function annotations with this name" },
  { "XQST0111", "$1" },
  { "XQTY0024", "element constructor content sequence must not have an attribute node following a non-attribute node" },
  { "XQTY0030", "validate argument must be exactly one document or element node" },
  { "XQTY0086", "typed value of copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve" },

  ////////////////////////////////////////////////
  //                                            //
  // XQuery Scripting Errors                    //
  //                                            //
  ////////////////////////////////////////////////

  { "XSST0001", "\"$1\": function cannot be declared as both updating and sequential" },
  { "XSST0002", "\"$1\": function declared sequential but has updating body" },
  { "XSST0003", "\"$1\": function declared updating but has sequential body" },
  { "XSST0004", "\"$1\": function declared simple but has sequential body" },
  { "XSST0005", "expression cannot be both updating and sequential" },
  { "XSST0006", "sequential expression not allowed here" },
  { "XSST0007", "\"$1\": variable not assignable" },
  { "XSST0008", "\"while\" expression with non-sequential body" },

  // XSLT Errors

  { "XTDE1310", "\"$1\": picture string does not satisfy format-number() function rules" },
  { "XTDE1340", "\"$1\": invalid picture string for date/time" },
  { "XTDE1350", "component specifier not available" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  ////////////////////////////////////////////////
  //                                            //
  // XQuery Update Errors                       //
  //                                            //
  ////////////////////////////////////////////////

  { "XUDY0009", "node has no parent in \"replace\" expression (without \"value of\")" },
  { "XUDY0014", "\"modify\" can not modify node not created by \"copy\"" },
  { "XUDY0015", "node is target of multiple \"rename\" expressions in same query" },
  { "XUDY0016", "node is target of multiple \"replace\" expressions (without \"value of\") in same query" },
  { "XUDY0017", "node is target of multiple \"replace value of\" expressions in same query" },
  { "XUDY0018", "\"$1\": function declared external, non-updating returns non-empty pending update list" },
  { "XUDY0019", "\"$1\": function declated external, updating returns non-empty data model instance" },
  { "XUDY0021", "updates violate constraint" },
  { "XUDY0023", "\"$1\": namespace binding conflicts with $2=$3" },
  { "XUDY0024", "\"$1\": namespace binding conflicts with $2=$3" },
  { "XUDY0027", "target expression is empty sequence" },
  { "XUDY0029", "node has no parent in \"insert\" expression (with \"before\" or \"after\")" },
  { "XUDY0030", "insertion of attrhbute node before or after document node child" },
  { "XUDY0031", "\"$1\": same URI used in multiple calls to fn:put() in same snapshot" },
  { "XUST0001", "updating expression not allowed here" },
  { "XUST0002", "simple expression not allowed here" },
  { "XUST0003", "multiple revalidation declarations" },
  { "XUST0028", "\"$1\": function can not be updating with a return type" },
  { "XUTY0004", "attribute node follows non-attribute node" },
  { "XUTY0005", "target expression not a single element or document node" },
  { "XUTY0006", "target expression not a single element, text, comment, or processing instruction node" },
  { "XUTY0007", "target expression does not return a sequence of zero or more nodes" },
  { "XUTY0008", "target expression not a single element, attribute, text, comment, or processing instruction node" },
  { "XUTY0010", "replacement sequence does not consist of zero or more element, text, comment, or processing instruction nodes" },
  { "XUTY0011", "replacement sequence does not consist of zero or more attribute nodes" },
  { "XUTY0012", "multiple elements, attributes, or processing-instruction nodes returned" },
  { "XUTY0013", "source expression of \"copy\" clause must return a single node" },
  { "XUTY0022", "insertion of attribute node into document node" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZAPI0002", "XQuery compilation failed${: 1}" },
  { "ZAPI0003", "XQuery not compiled" },
  { "ZAPI0004", "XQuery already compiled" },
  { "ZAPI0005", "XQuery already executing" },
  { "ZAPI0006", "XQuery already closed" },
  { "ZAPI0007", "cannot serialize pul" },
  { "ZAPI0008", "can not execute a non-updating XQuery" },
  { "ZAPI0009", "XQuery not compiled in debug mode" },
  { "ZAPI0014", "\"$1\": invalid argument${: 2}" },
  { "ZAPI0015", "\"$1\": createModule() function not found${: 2}" },
  { "ZAPI0019", "\"$1\": external module already registered" },
  { "ZAPI0020", "\"$1\": document already exists in store" },
  { "ZAPI0021", "\"$1\": item to load is not a node" },
  { "ZAPI0027", "cannot update dynamic context with iterators" },
  { "ZAPI0028", "\"$1\": invalid node URI" },
  { "ZAPI0039", "XQuery has iterator already" },
  { "ZAPI0040", "iterator is not open" },
  { "ZAPI0041", "iterator is already open" },
  { "ZAPI0042", "iterator is closed" },
  { "ZAPI0051", "REST error payload" },
  { "ZAPI0070", "\"$1\": invalid serialization method for SAX" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZCSE0001", "\"$1\": nonexistent input field" },
  { "ZCSE0002", "\"$1\": incompatible input field${: type=2}${, class=3}" },
  { "ZCSE0003", "\"$1\": unrecognized class field" },
  { "ZCSE0004", "\"$1\": unresolved field reference" },
  { "ZCSE0005", "class version for \"$1\" ($2) is too new; supported version is $3" },
  { "ZCSE0006", "class version for \"$1\" ($2) is too old; minimum supported version is $3; use Zorba 0x$4 instead" },
  { "ZCSE0007", "input archive used for out serialization" },
  { "ZCSE0008", "output archive used for in serialization" },
  { "ZCSE0009", "\"$1\": class not serializable" },
  { "ZCSE0010", "\"$1\": item type not serializable; only atomic, node, function, and error items are supported" },
  { "ZCSE0011", "input archive not Zorba archive" },
  { "ZCSE0012", "\"$1\": incompatible archive version; expected \"$2\"" },
  { "ZCSE0013", "failed to load pre-compiled query${: 1}" },
  { "ZCSE0014", "cannot save execution plan: infinite circular dependencies" },
  { "ZCSE0015", "cannot load execution plan: incompatible between 32/64 bits or little/big-endian" },
  { "ZCSE0016", "cannot load execution plan saved from release mode Zorba into debug mode Zorba" },
  { "ZCSE0017", "cannot load execution plan saved from debug mode Zorba into release mode Zorba" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZDDY0001", "\"$1\": collection not declared" },
  { "ZDDY0002", "\"$1\": collection already exists" },
  { "ZDDY0003", "\"$1\": collection does not exist" },
  { "ZDDY0004", "\"$1\": can not update constant collection" },
  { "ZDDY0005", "\"$1\": illegal insert into append-only collection" },
  { "ZDDY0006", "\"$1\": illegal insert into queue collection" },
  { "ZDDY0007", "\"$1\": illegal delete from append-only collection" },
  { "ZDDY0008", "\"$1\": illegal delete from queue collection" },
  { "ZDDY0009", "\"$1\": not all nodes to delete are at the beginning of this queue collection" },
  { "ZDDY0010", "\"$1\": illegal update of read-only nodes" },
  { "ZDDY0011", "\"$1\": collection does not contain node" },
  { "ZDDY0012", "\"$1\": illegal insert into unordered collection" },
  { "ZDDY0013", "\"$1\": can not delete collection because indexes reference it" },
  { "ZDDY0014", "\"$1\": can not delete collection because integrity constraints reference it" },
  { "ZDDY0015", "\"$1\": can not delete collection because there are references to its nodes" },
  { "ZDDY0016", "\"$1\": multiple calls to create-collection() in same snapshot" },
  { "ZDDY0017", "node does not belong to any collection" },
  { "ZDDY0018", "all nodes must be in same collection" },
  { "ZDDY0020", "\"$1\": index domain expression yields nodes that are not in collection" },
  { "ZDDY0021", "\"$1\": undeclared index" },
  { "ZDDY0022", "\"$1\": index already exists" },
  { "ZDDY0023", "\"$1\": index does not exist" },
  { "ZDDY0024", "\"$1\": index uniqueness violation" },
  { "ZDDY0025", "${\"1\": }invalid number of arguments in probe" },
  { "ZDDY0026", "\"$1\": index range probe not allowed" },
  { "ZDDY0027", "\"$1\": index multiple creates" },
  { "ZDDY0028", "\"$1\": index domain has duplicate nodes" },
  { "ZDDY0029", "\"$1\": index general probe not allowed" },
  { "ZDDY0031", "\"$1\": integrity constraint is not declared" },
  { "ZDDY0032", "\"$1\": integrity constraint is not activated" },
  { "ZDDY0033", "\"$1\": integrity constraint not met for collection \"$2\"" },
  { "ZDST0001", "\"$1\": collection already declared" },
  { "ZDST0002", "\"$1\": collection already imported into module \"$2\"" },
  { "ZDST0003", "\"$1\": collection declaration not allowed in main module" },
  { "ZDST0004", "collection multiple property values" },
  { "ZDST0005", "\"$1\": collection properties conflict" },
  { "ZDST0006", "collection invalid property value" },
  { "ZDST0007", "\"$1\": collection declaration in foreign module" },
  { "ZDST0021", "\"$1\": index already declared" },
  { "ZDST0022", "\"$1\": index already imported into module \"$2\"" },
  { "ZDST0023", "\"$1\": index declaration not allowed in main module" },
  { "ZDST0024", "index multiple property values" },
  { "ZDST0026", "index invalid property value" },
  { "ZDST0027", "\"$1\": index bad key type" },
  { "ZDST0028", "\"$1\": index not deterministic" },
  { "ZDST0029", "\"$1\": index invalid data source" },
  { "ZDST0030", "\"$1\": index non-constant data source" },
  { "ZDST0031", "\"$1\": index has free vars" },
  { "ZDST0032", "\"$1\": index references context item" },
  { "ZDST0033", "\"$1\": index non-simple expression" },
  { "ZDST0034", "\"$1\": index can not do automatic maintenance" },
  { "ZDST0035", "\"$1\": index general multikey" },
  { "ZDST0036", "\"$1\": index declaration in foreign module" },
  { "ZDST0041", "\"$1\": integrity constraint already declared" },
  { "ZDST0044", "\"$1\": integrity constraint declaration not allowed in main module" },
  { "ZDST0048", "\"$1\": integrity constraint declaration in foreign module" },
  { "ZDTY0001", "\"$1\": invalid node type in collection \"$2\"" },
  { "ZDTY0010", "\"$1\": index domain expression yields a non-node item" },
  { "ZDTY0011", "result of some key expression of index $1 does not match its declared type" },
  { "ZDTY0012", "\"$1\": general range index key item has type for which no ordering relationship exists" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZOSE0001", "\"$1\": file not found${: 2}" },
  { "ZOSE0002", "\"$1\": not plain file" },
  { "ZOSE0003", "stream read failure" },
  { "ZOSE0004", "\"$1\": I/O error${: 2}" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZSTR0001", "\"$1\": index already exists" },
  { "ZSTR0002", "\"$1\": index does not exist" },
  { "ZSTR0003", "\"$1\": partial key insertion into index \"$2\"" },
  { "ZSTR0004", "\"$1\": partial key deletion from index \"$2\"" },
  { "ZSTR0005", "\"$1\": partial key probe into index \"$2\"" },
  { "ZSTR0006", "for index \"$1\": $2" },
  { "ZSTR0007", "\"$1\": unsupported probe condition for index \"$2\"" },
  { "ZSTR0008", "\"$1\": collection already exists" },
  { "ZSTR0009", "\"$1\": collection not found" },
  { "ZSTR0010", "can not insert node into colletion \"$1\" because it already belongs to collection \"$2\"" },
  { "ZSTR0011", "non-root node can not be inserted into collection \"$1\"" },
  { "ZSTR0012", "non-node item used with collection \"$1\"" },
  { "ZSTR0015", "\"$1\": integrity constraint already exists" },
  { "ZSTR0016", "\"$1\": integrity constraint does not exist" },
  { "ZSTR0020", "loader I/O error${: 1}" },
  { "ZSTR0021", "loader parsing error${: 1}" },
  { "ZSTR0030", "NodeID error${: 1}" },
  { "ZSTR0040", "type error${: 1}" },
  { "ZSTR0041", "NaN comparison" },
  { "ZSTR0045", "duplicate node found in sequence" },
  { "ZSTR0050", "\"$1\" not implemented for item type \"$2\"" },
  { "ZSTR0055", "streamable string has already been consumed" },

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  { "ZXQD0001", "\"$1\": prefix not declared when calling function \"$2\" from $3" },
  { "ZXQD0002", "\"$1\": $2" },
  { "ZXQP0000", "no error" },
  { "ZXQP0001", "dynamic runtime error${: 1}" },
  { "ZXQP0005", "\"$1\": not supported" },
  { "ZXQP0006", "\"$1\": assertion failed" },
  { "ZXQP0013", "FxCharHeap error: $1" },
  { "ZXQP0015", "not yet implemented: $1" },
  { "ZXQP0016", "\"$1\": reserved module target namespace" },
  { "ZXQP0017", "file access disabled" },
  { "ZXQP0019", "internal error${: 1}" },
  { "ZXQP0020", "\"$1\": invalid URI${: 2}" },
  { "ZXQP0021", "user error" },
  { "ZXQP0024", "XML does not match schema${: \"1\"}${ 2}" },
  { "ZXQP0025", "item creation failed" },
  { "ZXQP0027", "MS DOM engine error${: 1}" },
  { "ZXQP0028", "\"$1\": external function not bound" },
  { "ZXQP0029", "\"$1\": module import not allowed" },
  { "ZXQP0030", "deadlock" },
  { "ZXQP0031", "malformed XQueryX XML input${: 1}" },
  { "ZXQP0032", "error transforming XQueryX to XQuery${: 1}" },
  { "ZXQP0036", "BreakIterator creation failed" },

#ifndef ZORBA_NO_FULL_TEXT
  { "ZXQP8401", "\"$1\": wrong WordNet file version; should be \"$2\"" },
  { "ZXQP8402", "thesaurus data error${: 1}" },
#endif /* ZORBA_NO_FULL_TEXT */

  /////////////////////////////////////////////////////////////////////////////

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // !!!!! THIS MUST BE ASCII SORTED BY KEY !!!!!
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  // Note: parameter numbers for sub-messages start with at LEAST $2.

  { "~AllMatchesHasExcludes", "AllMatches contains StringExclude" },
  { "~AlreadySpecified", "already specified" },
  { "~AttributeName", "attribute name" },
  { "~AttributeNode", "attribute node" },
  { "~BackRef0Illegal", "\"\\0\": illegal backreference" },
  { "~BackRefIllegalInCharClass", "backreference illegal in character class" },
  { "~BadAnyURI", "invalid xs:anyURI" },
  { "~BadCharAfter", "'$3': illegal character after '$4'" },
  { "~BadCharInBraces", "'$2': illegal character within { }" },
  { "~BadDecDigit", "'$3': invalid decimal digit" },
  { "~BadFileURIAuthority", "\"$2\": invalid authority for \"file\" scheme" },
  { "~BadHexDigit", "${'3': }invalid hexedecimal digit" },
  { "~BadItem", "invalid item" },
  { "~BadIterator", "invalid iterator" },
  { "~BadLibraryModule", "invalid library module" },
  { "~BadMathTypes", "arithmetic operation not defined with type $3" },
  { "~BadPath", "invalid path" },
  { "~BadStreamState", "bad I/O stream state" },
  { "~BadTokenInBraces", "\"$3\": illegal token within { }" },
  { "~BadTraceStream", "trace stream not retrievable using SerializationCallback" },
  { "~BadURIScheme", "\"$3\": unknown URI scheme" },
  { "~BadUnicodeChar", "\"$2\": invalid character code-point" },
  { "~BadWordNetPartOfSpeech", "\"$2\": invalid part-of-speech" },
  { "~BadWordNetPtr", "\"$2\": invalid pointer type" },
  { "~BadXMLDocument", "malformed XML document${ at \"2\"}" },
  { "~BadXMLForXQDoc", "can not parse as XML for xqdoc: $3" },
  { "~BadXQueryVersion", "unsupported XQuery version" },
  { "~Base64BadChar", "invalid Base64 character" },
  { "~Base64Equals", "in Base64, '=' must be at the end and followed by one of [AEIMQUYcgkosw048]" },
  { "~Base64EqualsEquals", "in Base64, \"==\" must be at the end and followed by one of [AQgw]" },
  { "~Base64Multiple4", "Base64 data must be a multiple of 4 characters" },
  { "~BaseURI", "base URI" },
  { "~BoxCondTooManyColumns", "box condition has more columns than index" },
  { "~CastFromToFailed", "$3 to $4 cast failed" },
  { "~CharExpected", "'$3' expected" },
  { "~CloneNotImplemented", "clone() not implemented for expression" },
  { "~ClosingBraceWithoutOpen", "'}' encountered without '{' first" },
  { "~CollectionIteratorNotOpen", "collection iterator not open" },
  { "~CountClause11", "\"count\" clause only available in XQuery 1.1 or later" },
  { "~DefaultCollation", "default collation" },
  { "~DivisionNoINF", "division can not have +-INF dividend" },
  { "~DivisionNoNaN", "division can not involve NaN" },
  { "~DocNodeMultipleElements", "document node has more than one element" },
  { "~EffectiveBooleanValue", "effective boolean value" },
  { "~ElementName", "element name" },
  { "~EmptyPath", "empty path" },
  { "~Eval11", "\"eval\" only available in XQuery 1.1 or later" },
  { "~ExprNoReturnUpdateList", "expression does not return a pending update list" },
  { "~ExprReturnsTooManyUpdateLists", "expression does not return a pending update list" },
  { "~ExternFnDeterministic", "only external functions may be declared deterministic" },
  { "~ExternFnNondeterministic", "only external functions may be declared nondeterministic" },
  { "~FileNotFoundOrReadable", "file not found or readable" },
  { "~FnNilledArgNotNode", "fn:nilled() argument not a node" },
  { "~FullTextNotEnabled", "full-text was not enabled in this build" },
  { "~GoodValuesAreUTF8", "valid values are: UTF-8, UTF-16" },
  { "~GoodValuesAreXMLEtc", "valid values are: xml, html, xhtml, text, binary" },
  { "~GoodValuesAreYesNo", "valid values are: yes, no" },
  { "~GoodValuesAreYesNoOmit", "valid values are: yes, no, omit" },
  { "~HexBinaryMustBeEven", "HexBinary value must contain an even number of characters" },
  { "~IncompleteKeyInIndexBuild", "incomplete key during index build" },
  { "~IncompleteKeyInIndexRefresh", "incomplete key during index refresh" },
  { "~LibModVersionMismatch", "XQuery library version can not be imported by a $3 version module" },
  { "~ModuleDeclNotInMain", "module declaration must not be in main module" },
  { "~ModuleNotFound", "module not found" },
  { "~MustBeAbsoluteURI", "must be absolute" },
  { "~MustBeNCName", "must be an xs:NCName" },
  { "~NoBindURI", "namespace URI can not be bound to prefix" },
  { "~NoCastTo", "can not cast to $3${: 4}" },
  { "~NoCollectionURIResolver", "no collection URI resolver could be retrieved using SerializationCallback" },
  { "~NoCompWithType", "can not compare for equality to type \"$3\"" },
  { "~NoCompareTypes", "can not compare item of type $2 with item of type $3" },
  { "~NoDocumentURIResolver", "no document URI resolver could be retrieved using SerializationCallback" },
  { "~NoDriveSpecification", "missing drive specification" },
  { "~NoEmptyLocalname", "local-name can not be empty" },
  { "~NoEmptySeqAsBaseURI", "can't treat empty sequence as base URI" },
  { "~NoHashItemOfType", "can not hash item of type $2" },
  { "~NoModuleURIResolver", "no module URI resolver could be retrieved using SerializationCallback" },
  { "~NoRebindPrefix", "can not rebind predefined prefix" },
  { "~NoRegisteredSerializationCallback", "external module \"$2\" not available using registered SerializationCallback" },
  { "~NoResolveRelativeURI", "could not resolve relative URI" },
  { "~NoSerializationCallbackForDocColMod", "document, collection, or module resolver required but no SerializationCallback given" },
  { "~NoSerializationCallbackForModule", "no SerializationCallback for required external module \"$2\"" },
  { "~NoSerializationCallbackForTraceStream", "no SerializationCallback for required trace stream" },
  { "~NoSourceURI", "no URI" },
  { "~NoTreatAs", "can not treat as \"$3\"" },
  { "~NoTypeInCtx", "undefined type in current context" },
  { "~NoTypeInMainModule", "type of variable \"$3\" is not among the in-scope types of the main module" },
  { "~NoTypeInodule", "type of variable \"$3\" is not among the in-scope types module \"$4\"" },
  { "~NoURIAuthority", "no authority" },
  { "~NoURIInStore", "URI for document not found in store" },
  { "~NoURIScheme", "no URI scheme" },
  { "~NodeIDNeedsBytes", "nodeid requires more than $2 bytes" },
  { "~NodeIDTooBig", "nodeid component too big for encoding" },
  { "~NonClosedBackRef", "'$$3': non-closed backreference" },
  { "~NonFileThesaurusURI", "non-file thesaurus URI" },
  { "~NonLocalhostAuthority", "non-localhost authority" },
  { "~NonexistentBackRef", "'$$3': non-existent backreference" },
  { "~NotAllowedForTypeName", "not allowed for typeName (use xsd:untyped instead)" },
  { "~NotAmongInScopeSchemaTypes", "not among in-scope schema types" },
  { "~NotDefInDynamicCtx", "not defined in dynamic context" },
  { "~NotDocOrElementNode", "not a document or element node" },
  { "~NotInStaticCtx", "not found in static context" },
  { "~NotPlainFile", "not plain file" },
  { "~NotSpecified", "not specified" },
  { "~OSFailedError", "error $1: $2" },
  { "~OSWhatFailedError", "$1 failed (error $2): $3" },
  { "~OperationNotDef", "$2 not defined for \"$3\"" },
  { "~OuterForClause11", "\"outer-for\" clause only available in XQuery 1.1 or later" },
  { "~ParserInitFailed", "parser initialization failed" },
  { "~ParserNoCreateTree", "XML tree creation failed" },
  { "~SEPM0009_Not10", "the version parameter has a value other than \"1.0\" and the doctype-system parameter is specified" },
  { "~SEPM0009_NotOmit", "the standalone attribute has a value other than \"omit\"" },
  { "~SchemaAttributeName", "schema-attribute name" },
  { "~SchemaElementName", "schema-element name" },
  { "~SeqFnBody", "only a function declared sequential can have a body that is a sequential expression" },
  { "~StackOverflow", "stack overflow" },
  { "~StartEndTagMismatch", "start tag \"$2\" does not match end tag \"$3\"" },
  { "~StingLiteral", "string literal" },
  { "~StringValue", "string value" },
  { "~SwitchExpr11", "\"switch\" expressions only available in XQuery 1.1 or later" },
  { "~TrailingChar", "trailing '$3'" },
  { "~TryCatchExpr11", "\"try/catch\" expressions only available in XQuery 1.1 or later" },
  { "~TwoDecimalFormatsSameName", "\"$2\": two decimal formats with this name" },
  { "~TwoDefaultDecimalFormats", "two default decimal formats" },
  { "~TypeIsNotSubtype", "item type is not a subtype of \"$3\"" },
  { "~U_REGEX_BAD_ESCAPE_SEQUENCE", "unrecognized backslash escape sequence" },
  { "~U_REGEX_BAD_INTERVAL", "error in {min,max} interval" },
  { "~U_REGEX_INTERNAL_ERROR", "an internal ICU error (bug) was detected" },
  { "~U_REGEX_INVALID_BACK_REF", "backreference to a non-existent capture group" },
  { "~U_REGEX_INVALID_FLAG", "invalid value for match mode flags" },
  { "~U_REGEX_INVALID_RANGE", "in character range [x-y], x is greater than y" },
  { "~U_REGEX_INVALID_STATE", "RegexMatcher in invalid state for requested operation" },
  { "~U_REGEX_LOOK_BEHIND_LIMIT", "look-behind pattern matches must have a bounded maximum length" },
  { "~U_REGEX_MAX_LT_MIN", "in {min,max}, max is less than min" },
  { "~U_REGEX_MISMATCHED_PAREN", "incorrectly nested parentheses" },
  { "~U_REGEX_MISSING_CLOSE_BRACKET", "missing ']'" },
  { "~U_REGEX_NUMBER_TOO_BIG", "decimal number is too large" },
  { "~U_REGEX_OCTAL_TOO_BIG", "octal character constants must be <= 0377" },
  { "~U_REGEX_PROPERTY_SYNTAX", "incorrect Unicode property" },
  { "~U_REGEX_RULE_SYNTAX", "syntax error" },
  { "~U_REGEX_SET_CONTAINS_STRING", "can not have UnicodeSets containing strings" },
  { "~U_REGEX_STACK_OVERFLOW", "backtrack stack overflow" },
  { "~U_REGEX_STOPPED_BY_CALLER", "matching operation aborted by user callback fn" },
  { "~U_REGEX_TIME_OUT", "maximum allowed match time exceeded" },
  { "~U_REGEX_UNIMPLEMENTED", "use of regular expression feature that is not yet implemented" },
  { "~UnbalancedChar", "missing '$3'" },
  { "~UnexpectedElement", "unexpected element" },
  { "~ValueCompOneItemOnly", "value comparisons must not be made with sequences longer than one item" },
  { "~VariabledHasNoValue", "variable has no value" },
  { "~VariabledUndeclared", "undeclared variable" },
  { "~WindowClause11", "\"window\" clause only available in XQuery 1.1 or later" },
  { "~WrongWordNetEndianness", "wrong endianness" },
  { "~XQueryVersionV1_0", "\"$2\": XQuery version must be at least 1.0" },
  { "~XUST0001_CONCAT", "comma expression with updating and non-updating branches" },
  { "~XUST0001_Generic", "updating expression illegal here" },
  { "~XUST0001_IF", "conditional expression with updating and non-updating branch" },
  { "~XUST0001_UDF", "\"$2\": function declared simple but body is updating" },
  { "~XUST0002_Transform", "transform expression witn non-updating or vacuous modify clause" },
  { "~XUST0002_UDF", "\"$2\": function declared updating but body is not updating or vacuous" },
  { "~Zorba API error", "Zorba API error" },
  { "~Zorba data-definition error", "Zorba data-definition error" },
  { "~Zorba error", "Zorba error" },
  { "~Zorba serialization error", "Zorba serialization error" },
  { "~Zorba store error", "Zorba store error" },
  { "~dynamic error", "dynamic error" },
  { "~error", "error" },
  { "~format_integer_bad_picture_format", "bad $picture format: $2" },
  { "~format_integer_duplicated_optional_format_modifier", "duplicated optional format modifier '$2'" },
  { "~format_integer_optional_format_modifier_not_closed", "bad optional format modifier ($2), cannot find closing ')' " },
  { "~format_integer_picture_empty", "$picture parameter should not be empty" },
  { "~format_integer_unknown_optional_format_modifier_character", "unknown optional format modifier character '$2'" },
  { "~format_integer_value_1_10", "$value ($2) should be between 1 and 10 for this formatting picture" },
  { "~format_integer_value_1_20", "$value ($2) should be between 1 and 20 for this formatting picture" },
  { "~format_integer_value_gt_3000", "$value ($2) should be less than 3000 for Roman representation" },
  { "~operating system error", "operating system error" },
  { "~serialization error", "serialization error" },
  { "~static error", "static error" },
  { "~type error", "type error" },
  { "~user-defined error", "user-defined error" },
  { "~xqueryx_empty_content", "xqueryx content is empty" },

  // PLEASE LEAVE THE BLANK LINE ABOVE
};
DEF_DICT_END(en);

///////////////////////////////////////////////////////////////////////////////

} // namespace dict
} // namespace err
} // namespace zorba
/* vim:set et sw=2 ts=2: */
