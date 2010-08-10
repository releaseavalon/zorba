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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "runtime/any_uri/any_uri.h"
#include "functions/func_any_uri.h"


namespace zorba{



PlanIter_t fn_resolve_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ResolveUriIterator(sctx, loc, argv);
}

void populate_context_any_uri(static_context* sctx)
{
  DECL(sctx, fn_resolve_uri,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

}


}