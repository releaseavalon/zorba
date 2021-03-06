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

#include <zorba/properties.h>

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/util/timeout.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/visitors/printer_visitor_api.h"

using namespace std;

namespace zorba {

/*******************************************************************************

********************************************************************************/
PlanWrapper::PlanWrapper(
    PlanIterator* aIter,
    CompilerCB* aCompilerCB,
    dynamic_context* aDynamicContext,
    XQueryImpl* query,
    uint32_t aStackDepth,
    bool haveTimeout,
    unsigned long timeout)
  :
  theIterator(aIter),
  theDynamicContext(NULL),
  theIsOpen(false),
  theTimeout(NULL),
  theExitValue(0)
{
  assert (aCompilerCB);

  if (aDynamicContext == NULL)
  {
    // aDynamicContext is NULL when we try to execute the plan of an expression
    // that is being folded by the optimizer. 
    aDynamicContext = new dynamic_context();
    theDynamicContext = aDynamicContext;
  }

  uint32_t lStateSize = theIterator->getStateSizeOfSubtree();

  thePlanState = new PlanState(aDynamicContext,
                               aDynamicContext,
                               lStateSize,
                               aStackDepth,
                               Properties::instance().getMaxUDFCallDepth());

  // set the compiler cb in the state
  thePlanState->theCompilerCB = aCompilerCB;
  thePlanState->theQuery = query;
#ifdef ZORBA_WITH_DEBUGGER
  thePlanState->theDebuggerCommons = aCompilerCB->theDebuggerCommons;
#endif

  if (haveTimeout) 
  {
    StateWrapper lWrapper(*thePlanState);
    theTimeout = new Timeout(timeout, lWrapper);
  }
}


/*******************************************************************************

********************************************************************************/
PlanWrapper::~PlanWrapper()
{
  if (theIsOpen)
    theIterator->close(*thePlanState);

  if (theTimeout) 
  {
    // Terminate could throw an exception
    // but does not for this particular implementation
    theTimeout->terminate();
  }

  delete theTimeout;

  delete thePlanState; 
  thePlanState = NULL;

  // De-allocate locally allocated dctx, if any
  if (theDynamicContext != NULL)
  {
    delete theDynamicContext;
    theDynamicContext = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void PlanWrapper::open()
{
  ZORBA_ASSERT(!theIsOpen);

  uint32_t offset = 0;
  theIterator->open(*thePlanState, offset);

  if (theTimeout) 
  {
    // Start a thread that will suspend itself for the given amount of time,
    // and then it will wake up and set theHasToQuit flag of the plan state.
    theTimeout->start();
  }

  theIsOpen = true;
}


/*******************************************************************************

********************************************************************************/
bool PlanWrapper::next(store::Item_t& result)
{
  ZORBA_ASSERT(theIsOpen);
  // bugfix for #3042039
  // from the scripting spec:
  // "If an exit expression is evaluated within a query body
  // (i.e., not within the body of a function),
  // further evaluation of the query is interrupted and the XDM instance
  // returned by the operand expression is returned as the result of the query."
  // However, for reasons of lazy evaluation, we also return the result
  // that was computed before the exit expression was evaluated
  // (see test scripting/exit4.xq)
  if (!theExitValue) 
  {
    try
    {
      return PlanIterator::consumeNext(result, theIterator, *thePlanState);
    }  
    catch (ExitException &e)
    {
      theExitValue = e.val;
    }
  }
  return theExitValue->next(result);
}


/*******************************************************************************

********************************************************************************/
bool PlanWrapper::skip(int64_t count)
{
  ZORBA_ASSERT(theIsOpen);

  return theIterator->skip(count, *thePlanState);
}


/*******************************************************************************

********************************************************************************/
void PlanWrapper::reset()
{
  ZORBA_ASSERT(theIsOpen);

  theIterator->reset(*thePlanState); 
  theExitValue = 0;
}


/*******************************************************************************

********************************************************************************/
void PlanWrapper::close()
{
  ZORBA_ASSERT(theIsOpen);
  
  theIterator->close(*thePlanState);
  theExitValue = 0;

  theIsOpen = false;
}


/*******************************************************************************

********************************************************************************/
void PlanWrapper::checkDepth(const QueryLoc& loc)
{
  thePlanState->checkDepth(loc);
}


/******************************************************************************

 ******************************************************************************/

void PlanWrapper::profile() const {
  Zorba_profile_format_t const format = Properties::instance().getProfileFormat();
  if ( format )
  {
    std::ostream &os = Properties::instance().getDebugStream();
    unique_ptr<IterPrinter> printer;
    switch ( format ) {
      case PROFILE_FORMAT_DOT:
        printer.reset( new DOTIterPrinter( os ) );
        break;
      case PROFILE_FORMAT_JSON:
        printer.reset( new JSONIterPrinter( os ) );
        break;
      case PROFILE_FORMAT_XML:
        printer.reset( new XMLIterPrinter( os ) );
        break;
      default: // to silence warning
        break;
    } // switch
  print_iter_plan( *printer, theIterator, thePlanState );
  }
}

/*******************************************************************************

********************************************************************************/
#ifndef NDEBUG
std::string PlanWrapper::toString() const
{
  std::stringstream ss;
  ss << this << " = PlanWrapper iterator: " << theIterator->toString();
  return ss.str();
}
#endif

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
