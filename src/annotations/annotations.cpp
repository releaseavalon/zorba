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

#include <cmath>

#include "annotations/annotations.h"
#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "compiler/expression/expr.h"

#include "zorbaserialization/serialization_engine.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)

SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)

SERIALIZABLE_CLASS_VERSIONS(AnnotationList)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationList);


std::vector<store::Item_t> 
AnnotationInternal::theAnnotId2NameMap;

ItemHandleHashMap<AnnotationInternal::AnnotationId> 
AnnotationInternal::theAnnotName2IdMap(0, NULL, 64, false);

std::vector<AnnotationInternal::RuleBitSet> 
AnnotationInternal::theRuleSet;


/*******************************************************************************
  Static method, called from GlobalEnvironment::init()
********************************************************************************/
void AnnotationInternal::createBuiltIn()
{
  store::Item_t qname;
  AnnotationId id;

  theAnnotId2NameMap.resize(zann_end+1);

  //
  // W3C annotations
  //
  GENV_ITEMFACTORY->createQName(qname, static_context::W3C_FN_NS, "fn", "public");
  id = fn_public;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

  GENV_ITEMFACTORY->createQName(qname, static_context::W3C_FN_NS, "fn", "private");
  id = fn_private;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

#define ZANN(a, b)                                                     \
  GENV_ITEMFACTORY->createQName(qname, ZORBA_ANNOTATIONS_NS, "", #a);  \
  id = zann_##b;                                                      \
  theAnnotId2NameMap[id] = qname;                                     \
  theAnnotName2IdMap.insert(qname, id);


  //
  // Zorba annotations - deterministic/nondeterministic
  //
  ZANN(deterministic, deterministic);
  ZANN(nondeterministic, nondeterministic);

  //
  // Zorba annotations - xquery scripting
  //
  ZANN(assignable, assignable);
  ZANN(nonassignable, nonassignable);

  ZANN(sequential, sequential);
  ZANN(nonsequential, nonsequential);

  //
  // Zorba annotations - misc
  //
  ZANN(variadic, variadic);

  ZANN(streamable, streamable);

  //
  // Zorba annotations - xqddf
  //
  ZANN(unique, unique);
  ZANN(nonunique, nonunique);

  ZANN(value-equality, value_equality);
  ZANN(general-equality, general_equality);
  ZANN(value-range, value_range);
  ZANN(general-range, general_range);

  ZANN(automatic, automatic);
  ZANN(manual, manual);

  ZANN(mutable, mutable);
  ZANN(queue, queue);
  ZANN(append-only, append_only);
  ZANN(const, const);

  ZANN(ordered, ordered);
  ZANN(unordered, unordered);

  ZANN(read-only-nodes, read_only_nodes);
  ZANN(mutable-nodes, mutable_nodes);

#undef ZANN

  // create a set of rules to detect conflicts between annotations
#define ZANN(a) \
  ( 1 << static_cast<uint64_t>(AnnotationInternal::a) )

  theRuleSet.push_back(
       ZANN(zann_unique) |
       ZANN(zann_nonunique));

  theRuleSet.push_back(
      ZANN(zann_value_equality) |
      ZANN(zann_general_equality) |
      ZANN(zann_value_range) |
      ZANN(zann_general_range));

  theRuleSet.push_back(
      ZANN(zann_automatic) |
      ZANN(zann_manual));

  theRuleSet.push_back(
      ZANN(zann_mutable) |
      ZANN(zann_queue) |
      ZANN(zann_append_only) |
      ZANN(zann_const));

  theRuleSet.push_back(
      ZANN(zann_ordered) |
      ZANN(zann_unordered));

  theRuleSet.push_back(
      ZANN(zann_assignable) |
      ZANN(zann_nonassignable));

  theRuleSet.push_back(
      ZANN(zann_deterministic) |
      ZANN(zann_nondeterministic));

  theRuleSet.push_back(
      ZANN(zann_sequential) |
      ZANN(zann_nonsequential));

  theRuleSet.push_back(
      ZANN(fn_private) |
      ZANN(fn_public));

  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_queue));

  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_append_only));

  theRuleSet.push_back(
      ZANN(zann_queue) |
      ZANN(zann_append_only));

  theRuleSet.push_back(
      ZANN(zann_read_only_nodes) |
      ZANN(zann_mutable_nodes));
#undef ZANN
}


/*******************************************************************************
  Static method, called from GlobalEnvironment::init()
********************************************************************************/
void AnnotationInternal::destroyBuiltIn()
{
  theAnnotId2NameMap.clear();
  theAnnotName2IdMap.clear();
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationId AnnotationInternal::lookup(
    const store::Item_t& qname)
{
  ItemHandleHashMap<AnnotationId>::iterator ite = theAnnotName2IdMap.find(qname);

  if (ite == theAnnotName2IdMap.end())
    return zann_end;

  return (*ite).second;
}


/*******************************************************************************

********************************************************************************/
store::Item* AnnotationInternal::lookup(AnnotationInternal::AnnotationId id)
{
  assert(id < theAnnotId2NameMap.size());

  return theAnnotId2NameMap[id].getp();
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(const store::Item_t& qname)
  :
  theId((*theAnnotName2IdMap.find(qname)).second),
  theQName(qname)
{
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(
  const store::Item_t& qname,
  const std::vector<AnnotationLiteral_t>& literals)
  :
  theId((*theAnnotName2IdMap.find(qname)).second),
  theQName(qname),
  theLiteralList(literals)
{
}


/*******************************************************************************

********************************************************************************/
void AnnotationInternal::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_ENUM(AnnotationId, theId);
  ar & theQName;
  ar & theLiteralList;
}


/*******************************************************************************

********************************************************************************/
const store::Item* AnnotationInternal::getQName() const
{
  return theQName.getp();
}


/*******************************************************************************

********************************************************************************/
csize AnnotationInternal::getNumLiterals() const
{
  return theLiteralList.size();
}


/*******************************************************************************

********************************************************************************/
const AnnotationLiteral* AnnotationInternal::getLiteral(csize index) const
{
  if (index < theLiteralList.size())
    return theLiteralList[index];
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
void AnnotationLiteral::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLiteral;
}


/*******************************************************************************

********************************************************************************/
AnnotationLiteral::AnnotationLiteral(const store::Item_t& aLiteralValue)
  :
  theLiteral(aLiteralValue)
{
}


/*******************************************************************************

********************************************************************************/
store::Item_t AnnotationLiteral::getLiteralItem() const
{
  return theLiteral;
}


/*******************************************************************************

********************************************************************************/
AnnotationList::AnnotationList()
{
}


/*******************************************************************************

********************************************************************************/
AnnotationList::~AnnotationList()
{
}


/*******************************************************************************

********************************************************************************/
void AnnotationList::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theAnnotationList;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal* AnnotationList::getAnnotation(csize index) const
{
  if (index < theAnnotationList.size())
    return theAnnotationList[index].getp();
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
void AnnotationList::push_back(
    const store::Item_t& qname,
    const std::vector<rchandle<const_expr> >& literals)
{
  std::vector<AnnotationLiteral_t> lLiterals;

  for (std::vector<rchandle<const_expr> >::const_iterator it = literals.begin();
       it != literals.end();
       ++it)
  {
    lLiterals.push_back(new AnnotationLiteral((*it)->get_val()));
  }

  theAnnotationList.push_back(new AnnotationInternal(qname, lLiterals));
}


#if 0
/*******************************************************************************

********************************************************************************/
bool AnnotationList::contains(const store::Item_t& aSearchQName) const
{
  if (aSearchQName.getp() == NULL)
    return false;

  // sequential search might not be the most efficient but
  // how many annotations might a function or variable have? 5?
  for (ListConstIter_t lIter = theAnnotationList.begin();
       lIter != theAnnotationList.end();
       ++lIter)
  {
    if ((*lIter)->getQName()->equals(aSearchQName))
      return true;
  }

  return false;
}
#endif

/*******************************************************************************

********************************************************************************/
bool AnnotationList::contains(AnnotationInternal::AnnotationId id) const
{
  for (ListConstIter_t ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    if ((*ite)->getId() == id)
      return true;
  }

  return false;
}


/*******************************************************************************
  Called from translator::end_visit(const AnnotationListParsenode& v, void*)
********************************************************************************/
void AnnotationList::checkConflictingDeclarations(const QueryLoc& loc) const
{
  // make sure we don't have more annotations then max 64 bit
  assert( static_cast<uint64_t>(AnnotationInternal::zann_end) <
          std::numeric_limits<uint64_t>::max() );

  RuleBitSet lCurrAnn;

  // mark and detect duplicates
  for (ListConstIter_t ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    const store::Item* qname = (*ite)->getQName();
    AnnotationId id = (*ite)->getId();

    // detect duplicate annotations (if we "know" them)
    if (lCurrAnn.test(id))
    {
      RAISE_ERROR(err::XQST0106, loc,
      ERROR_PARAMS(qname->getStringValue(), ZED(XQST0106_THE_SAME)));
    }

    lCurrAnn.set(id);
  }

  // check rules
  std::vector<RuleBitSet>::const_iterator ite = AnnotationInternal::theRuleSet.begin();
  std::vector<RuleBitSet>::const_iterator end = AnnotationInternal::theRuleSet.end();

  for (; ite != end; ++ite)
  {
    const RuleBitSet& lCurrSet = *ite;

    if ((lCurrAnn & lCurrSet).count() >  1)
    {
      // build error string to return set of conflicting annotations
      std::ostringstream lProblems;
      for (csize i = 0, j = 0;
           i < AnnotationInternal::zann_end;
           ++i)
      {
        if (lCurrSet.test(i))
        {
          AnnotationId id = static_cast<AnnotationId>(i);

          lProblems << AnnotationInternal::lookup(id)->getStringValue()
                    << ((j == lCurrSet.count() - 1) ? "" : ", ");
          ++j;
        }
      }

      RAISE_ERROR(err::XQST0106, loc,
      ERROR_PARAMS(lProblems.str(), ZED(XQST0106_CONFLICTING)));
    }
  }
}



} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
