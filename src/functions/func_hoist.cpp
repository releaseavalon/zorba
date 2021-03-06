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

#include "functions/func_hoist.h"
#include "functions/function_impl.h"

#include "compiler/expression/fo_expr.h"

#include "runtime/core/internal_operators.h"

namespace zorba 
{


class zop_hoist : public function 
{
public:
  zop_hoist(const signature& sig) : function(sig, FunctionConsts::OP_HOIST_1) {}

  xqtref_t getReturnType(const fo_expr* caller) const
  {
    return caller->get_arg(0)->get_return_type();
  }

  bool isMap(csize input) const
  {
    return true;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  bool propagatesSortedNodes(csize producer) const
  {
    return producer == 0;
  }

  bool propagatesDistinctNodes(csize producer) const
  {
    return producer == 0;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const
  {
    return fo->getIgnoresDuplicateNodes();
  }


  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const
  {
    return fo->getIgnoresDuplicateNodes();
  }

  DEFAULT_NARY_CODEGEN(HoistIterator);
};


class zop_unhoist : public function 
{
public:
  zop_unhoist(const signature& sig) : function(sig, FunctionConsts::OP_UNHOIST_1) {}

  xqtref_t getReturnType(const fo_expr* caller) const
  {
    return caller->get_arg(0)->get_return_type();
  }

  bool isMap(csize input) const
  {
    return true;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  bool propagatesSortedNodes(csize producer) const
  {
    return producer == 0;
  }

  bool propagatesDistinctNodes(csize producer) const
  {
    return producer == 0;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const
  {
    return fo->getIgnoresDuplicateNodes();
  }


  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const
  {
    return fo->getIgnoresDuplicateNodes();
  }

  DEFAULT_NARY_CODEGEN(UnhoistIterator);
};


void populateContext_Hoisting(static_context* sctx)
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS;

  DECL(sctx, zop_hoist,
       (createQName(zorba_op_ns, "", "hoist"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, zop_unhoist,
       (createQName(zorba_op_ns, "", "unhoist"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
/* vim:set et sw=2 ts=2: */
