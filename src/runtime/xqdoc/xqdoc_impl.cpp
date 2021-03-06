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

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "diagnostics/dict.h"
#include "diagnostics/util_macros.h"

#include "context/static_context.h"
#include "context/uri_resolver.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compiler_api_consts.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

#include "runtime/xqdoc/xqdoc.h"

namespace zorba {

/**
 * Helper function to transfrom the option item optionally passed to the
 * xqdoc functions into an uint32_t option value.
 */
void readOptions(uint32_t& aOptions, const store::Item& aOptionItem)
{
  aOptions = xqdoc_component_none;

  store::Iterator_t lChildrenIter = aOptionItem.getChildren();
  lChildrenIter->open();
  store::Item_t lChild;

  while (lChildrenIter->next(lChild))
  {
    zstring lLocalName = lChild->getNodeName()->getLocalName();
    zstring lValue = lChild->getStringValue();

    if(lValue != "true")
      continue;

    if (lLocalName == "comments")
      aOptions |= xqdoc_component_comments;
    else if (lLocalName == "imports")
      aOptions |= xqdoc_component_imports;
    else if (lLocalName == "variables")
      aOptions |= xqdoc_component_variables;
    else if (lLocalName == "functions")
      aOptions |= xqdoc_component_functions;
    else if (lLocalName == "collections")
      aOptions |= xqdoc_component_collections;
    else if (lLocalName == "indexes")
      aOptions |= xqdoc_component_indexes;
  }
}


/*******************************************************************************

********************************************************************************/
bool
XQDocContentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lCodeItem, lFileNameItem, lOptionsItem;
  //bool lIgnoreComments = true;
  uint32_t lXQDocOptions;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the module code to generate xqdoc for
  consumeNext(lCodeItem, theChildren[0].getp(), planState);

  consumeNext(lFileNameItem, theChildren[1].getp(), planState);

  if (theChildren.size() > 2)
  {
    // retrieve the options
    consumeNext(lOptionsItem, theChildren[2].getp(), planState);
    readOptions(lXQDocOptions, *lOptionsItem);
  }
  else
  {
    // if no option passed, everything is printed
    lXQDocOptions = 0xFFFFFFFF;
  }

  try
  {
    std::istringstream is(lCodeItem->getStringValue().c_str());

    // setup a new CompilerCB and a new XQueryCompiler
    CompilerCB lCompilerCB(*planState.theCompilerCB);

    // the XQueryCompiler's constructor destroys the existing type manager
    // in the static context. Hence, we create a new one
    XQueryCompiler lCompiler(&lCompilerCB);

    // retrieve the xqdoc elements
    lCompiler.xqdoc(is,
                    lFileNameItem->getStringValue(),
                    result,
                    planState.theLocalDynCtx->get_current_date_time(),
                    lXQDocOptions);
  }
  catch (XQueryException& e)
  {
    set_source( e, loc );
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
