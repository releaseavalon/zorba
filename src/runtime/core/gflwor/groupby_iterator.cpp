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
#include "stdafx.h"

#include "zorbautils/fatal.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "system/globalenv.h"

using namespace zorba;

namespace zorba 
{

namespace flwor 
{

SERIALIZABLE_CLASS_VERSIONS(GroupByIterator)
END_SERIALIZABLE_CLASS_VERSIONS(GroupByIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByState                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
GroupByState::GroupByState() 
  :
  theGroupMap(0)
{
}


/***************************************************************************//**

********************************************************************************/
GroupByState::~GroupByState() 
{
  GroupHashMap::iterator iter = theGroupMap->begin();
  GroupHashMap::iterator end = theGroupMap->end();
  for (; iter != end; ++iter)
  {
    delete (*iter).first;
    delete (*iter).second;
  }

  delete theGroupMap;
  theGroupMap = 0;
}
  

/***************************************************************************//**

********************************************************************************/
void GroupByState::init(
    PlanState& aState,
    const TypeManager* tm,
    const QueryLoc& loc,
    std::vector<GroupingSpec>* gspecs) 
{
  PlanIteratorState::init(aState);

  GroupTupleCmp cmp(loc, aState.theLocalDynCtx, tm, gspecs);
  theGroupMap = new GroupHashMap(cmp, 1024, false);
}


/***************************************************************************//**

********************************************************************************/
void GroupByState::reset(PlanState& aPlanState) 
{
  PlanIteratorState::reset(aPlanState);

  GroupHashMap::iterator iter = theGroupMap->begin();
  GroupHashMap::iterator end = theGroupMap->end();
  for (; iter != end; ++iter)
  {
    delete (*iter).first;
    delete (*iter).second;
  }

  theGroupMap->clear();
}
  

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
GroupByIterator::GroupByIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    PlanIter_t aTupleIterator,
    std::vector<GroupingSpec> aGroupingSpecs,
    std::vector<NonGroupingSpec> aNonGroupingSpecs) 
  :
  Batcher<GroupByIterator>(sctx, aLoc),
  theTupleIter(aTupleIterator),
  theGroupingSpecs(aGroupingSpecs),
  theNonGroupingSpecs(aNonGroupingSpecs) 
{
}
  

/***************************************************************************//**

********************************************************************************/
GroupByIterator::~GroupByIterator() 
{
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Batcher<GroupByIterator>*)this);
  ar & theTupleIter;
  ar & theGroupingSpecs;
  ar & theNonGroupingSpecs;
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByIterator::getStateSize() const  
{
  return StateTraitsImpl<GroupByState>::getStateSize();
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByIterator::getStateSizeOfSubtree() const 
{
  int32_t size = this->getStateSize();
  size  += theTupleIter->getStateSizeOfSubtree();

  ulong numSpecs = (ulong)theGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    size += theGroupingSpecs[i].getStateSizeOfSubtree();
  }

  numSpecs = (ulong)theNonGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    size += theNonGroupingSpecs[i].getStateSizeOfSubtree();
  }
  return size;
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);
      
  theTupleIter->accept(v);

  ulong numSpecs = (ulong)theGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theGroupingSpecs[i].accept(v);
  }

  numSpecs = (ulong)theNonGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theNonGroupingSpecs[i].accept(v);
  }

  v.endVisit(*this);
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::openImpl(PlanState& planState, uint32_t& aOffset) 
{
  StateTraitsImpl<GroupByState>::createState(planState, theStateOffset, aOffset);

  GroupByState* state = StateTraitsImpl<GroupByState>::getState(planState,
                                                                theStateOffset);
      
  state->init(planState, theSctx->get_typemanager(), loc, &theGroupingSpecs); 
      
  theTupleIter->open(planState, aOffset);

  ulong numSpecs = (ulong)theGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    GroupingSpec& spec = theGroupingSpecs[i];

    spec.open(planState, aOffset);

    if (spec.theCollation.size() != 0) 
    {
      spec.theCollator = theSctx->get_collator(spec.theCollation, loc);
    }
    else
    {
      spec.theCollator = theSctx->get_default_collator(loc);
    }
  }

  numSpecs = (ulong)theNonGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theNonGroupingSpecs[i].open(planState, aOffset);
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::closeImpl(PlanState& planState) 
{
  ulong numSpecs = (ulong)theGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theGroupingSpecs[i].close(planState);
  }

  numSpecs = (ulong)theNonGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theNonGroupingSpecs[i].close(planState);
  }

  theTupleIter->close(planState);
  
  StateTraitsImpl<GroupByState>::destroyState(planState, theStateOffset);
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::resetImpl(PlanState& planState) const 
{
  ulong numSpecs = (ulong)theGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theGroupingSpecs[i].reset(planState);
  }

  numSpecs = (ulong)theNonGroupingSpecs.size();

  for (ulong i = 0; i < numSpecs; ++i)
  {
    theNonGroupingSpecs[i].reset(planState);
  }

  theTupleIter->reset(planState);
  
  StateTraitsImpl<GroupByState>::reset(planState, theStateOffset);
}


/***************************************************************************//**

********************************************************************************/
bool GroupByIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const 
{
  GroupByState* lState;
  DEFAULT_STACK_INIT(GroupByState, lState, aPlanState);

  while (consumeNext(aResult, theTupleIter, aPlanState)) 
  {
    try 
    {
      matVarsAndGroupBy(lState, aPlanState);
    }
    catch (XQueryException& lError)
    {
      set_source( lError, loc );
      throw;
    }
  }

  if (!lState->theGroupMap->empty()) 
  {
    lState->theGroupMapIter = lState->theGroupMap->begin();
    while(lState->theGroupMapIter != lState->theGroupMap->end())
    {
      bindGroupBy(lState->theGroupMapIter, lState, aPlanState);

      ++lState->theGroupMapIter;

      STACK_PUSH(true, lState);
    }
  }

  STACK_END(lState);
}
  

/***************************************************************************//**

********************************************************************************/
void GroupByIterator::matVarsAndGroupBy(
    GroupByState* aGroupByState,
    PlanState& aPlanState) const 
{
  store::Item_t temp;

  GroupTuple* groupTuple = new GroupTuple();
  std::vector<store::Item_t>& groupTupleItems = groupTuple->theItems;
  std::vector<store::Item_t>& groupTupleValues = groupTuple->theTypedValues;

  ulong numVars = (ulong)theGroupingSpecs.size();

  // For each grouping variable
  for (ulong i = 0; i < numVars; ++i)
  {
    groupTupleItems.push_back(NULL);
    groupTupleValues.push_back(NULL);

    // Get the 1st item in the value of the current grouping variable. Push this
    // item into the groupTupleItems, and push the typed value of the item into
    // groupTupleValues, making sure that the typed value of the item consists
    // of a single item. 
    store::Item_t& item = groupTupleItems.back();
    bool status = consumeNext(item, theGroupingSpecs[i].theInput.getp(), aPlanState);

    if (status)
    {
      // Check that the value of the current grouping var does not have more
      // than 1 item.
      if (consumeNext(temp, theGroupingSpecs[i].theInput.getp(), aPlanState)) 
      {
        throw XQUERY_EXCEPTION(
          err::XPTY0004,
          ERROR_PARAMS( ZED( GroupByVarHasMoreThanOneItem_2 ) ),
          ERROR_LOC( loc )
        );
      }

      store::Iterator_t typedValueIter;
      store::Item_t typedValue;
      item->getTypedValue(typedValue, typedValueIter);
      if (typedValueIter == NULL)
      {
        groupTupleValues.back().transfer(typedValue);
      }
      else
      {
        typedValueIter->open();

        try
        {
          if (typedValueIter->next(typedValue)) 
          {
            groupTupleValues.back().transfer(typedValue);
            
            if (typedValueIter->next(temp))
            {
              throw XQUERY_EXCEPTION(
                err::XPTY0004,
                ERROR_PARAMS( ZED( AtomizationOfGroupByMakesMoreThanOneItem ) ),
                ERROR_LOC( loc )
              );
            }
          }
        }
        catch(...)
        {
          typedValueIter->close();
          throw;
        }

        typedValueIter->close();
      }
    }

    theGroupingSpecs[i].theInput->reset(aPlanState);
  }

  GroupHashMap* groupMap = aGroupByState->theGroupMap;

  numVars = (ulong)theNonGroupingSpecs.size();

  std::vector<store::TempSeq_t>* nonGroupTuple = NULL;

  if (groupMap->get(groupTuple, nonGroupTuple)) 
  {
    assert(nonGroupTuple != NULL);

    for (ulong i = 0; i < numVars; ++i)
    {
      store::Iterator_t iterWrapper = 
      new PlanIteratorWrapper(theNonGroupingSpecs[i].theInput, aPlanState);

      // FIXME are those settings right? I think copy is correct 
      (*nonGroupTuple)[i]->append(iterWrapper, false);

      theNonGroupingSpecs[i].theInput->reset(aPlanState);
    }

    delete groupTuple;
  }
  else
  {
    nonGroupTuple = new std::vector<store::TempSeq_t>();

    for (ulong i = 0; i < numVars; ++i)
    {
      store::Iterator_t iterWrapper = 
      new PlanIteratorWrapper(theNonGroupingSpecs[i].theInput, aPlanState);

      // FIXME are those settings (no-copy and no-lazy) right? 
      store::TempSeq_t tempSeq = GENV_STORE.createTempSeq(iterWrapper, false, false); 

      nonGroupTuple->push_back(tempSeq);

      theNonGroupingSpecs[i].theInput->reset(aPlanState);
    }

    groupMap->insert(groupTuple, nonGroupTuple);
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::bindGroupBy(
    GroupHashMap::iterator aGroupMapIter,
    GroupByState* aGroupByState,
    PlanState& aPlanState) const 
{
  // Bind grouping vars
  ulong numVars = (ulong)theGroupingSpecs.size();

  GroupTuple* groupTuple = (*aGroupMapIter).first;

  for (ulong i = 0; i < numVars; ++i)
  {
    ulong numVarRefs = (ulong)theGroupingSpecs[i].theVarRefs.size();

    for (ulong j = 0; j < numVarRefs; ++j)
    {
      theGroupingSpecs[i].theVarRefs[j]->bind(groupTuple->theItems[i], aPlanState);
    }
  }

  // Bind non-grouping vars
  numVars = (ulong)theNonGroupingSpecs.size();

  std::vector<store::TempSeq_t>* nonGroupTuple = (*aGroupMapIter).second;

  for (ulong i = 0; i < numVars; ++i)
  {
    store::TempSeq_t nonGroupVar = (*nonGroupTuple)[i].getp();

    ulong numVarRefs = (ulong)theNonGroupingSpecs[i].theVarRefs.size();

    for (ulong j = 0; j < numVarRefs; ++j)
    {
      theNonGroupingSpecs[i].theVarRefs[j]->bind(nonGroupVar, aPlanState);
    }
  }
}
  

} //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
