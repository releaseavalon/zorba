/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#include "json_items.h"
#include "simple_item_factory.h"
#include "simple_store.h"
#include "item_iterator.h"

#include "store/api/copymode.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

namespace zorba
{

namespace simplestore
{

namespace json
{

/******************************************************************************

*******************************************************************************/
store::Item* JSONNull::getType() const
{
  return GET_STORE().JDM_NULL_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool JSONNull::equals(
    const store::Item* other,
    long /* timezone */,
    const XQPCollator* /* collation */) const
{
  return other->getTypeCode() == store::JDM_NULL;
}


/******************************************************************************

*******************************************************************************/
uint32_t JSONNull::hash(long /* tmz */, const XQPCollator* /* collation */) const
{
  const void* tmp = this; // there is only one instance in the store
  return hashfun::h32(&tmp, sizeof(void*), FNV_32_INIT);
}


/******************************************************************************

*******************************************************************************/
void JSONNull::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  iter = NULL;
  val = this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Object                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
}


/******************************************************************************

*******************************************************************************/
void setJSONRoot(store::Item* aJSONItem, const JSONItem* aRoot)
{
  if (aJSONItem->isJSONObject())
  {
    assert(dynamic_cast<SimpleJSONObject*>(aJSONItem));
    SimpleJSONObject* lObject = static_cast<SimpleJSONObject*>(aJSONItem);

    // Only attach or detach allowed - no direct reattach.
    assert(aRoot == NULL || lObject->theRoot == NULL);
    lObject->setRoot(aRoot);
  }
  else if (aJSONItem->isJSONArray())
  {
    assert(dynamic_cast<SimpleJSONArray*>(aJSONItem));
    SimpleJSONArray* lArray = static_cast<SimpleJSONArray*>(aJSONItem);

    // Only attach or detach allowed - no direct reattach.
    assert(aRoot == NULL || lArray->theRoot == NULL);
    lArray->setRoot(aRoot);
  } 
  else
  {
    assert(false);
  }
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::~SimpleJSONObject()
{
  ASSERT_INVARIANT();
  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lName = lIter->first;
    store::Item* lChild = lIter->second;
    if (getCollection() != NULL && lChild->isJSONItem())
    {
      setJSONRoot(lChild, NULL);
    }
    lName->removeReference();
    lChild->removeReference();
  }
  theKeys.clear();
  thePairs.clear();
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObject::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  ASSERT_INVARIANT();
  SimpleJSONObject* lNewObject = const_cast<SimpleJSONObject*>(this);
 
 if (copymode.theDoCopy)
  {
    lNewObject = new SimpleJSONObject();

    for (Pairs::const_iterator lIter = thePairs.begin();
         lIter != thePairs.end();
         ++lIter)
    {
      store::Item_t lKey = lIter->first;
      store::Item_t lValue = lIter->second;
      
      if (lValue->isJSONObject() ||
           lValue->isJSONArray() ||
           lValue->isNode())
      {
        store::Item_t lCopiedValue = lValue->copy(NULL, copymode);
        lNewObject->add(lKey, lCopiedValue, false);
      }
      else
      {
        lNewObject->add(lKey, lValue, false);
      }
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    assert(dynamic_cast<JSONArray*>(parent));
    JSONArray* a = static_cast<JSONArray*>(parent);

    a->push_back(lNewObject);
  }
  
  return lNewObject;
}


/*******************************************************************************

********************************************************************************/
void SimpleJSONObject::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
  ASSERT_INVARIANT();
  // Ensures one either detaches or attaches.
  assert(collection == NULL || theCollection == NULL);

  theCollection = collection;
  
  if (theCollection != NULL)
  {
    // Attach
    setRoot(this);
  }
  else 
  {
    // Detach
    setRoot(NULL);
  }
  
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::add(
    const store::Item_t& aName,
    const store::Item_t& aValue,
    bool accumulate)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();

  if (!theKeys.exists(lName))
  {
    store::Item* lValue = aValue.getp();

    if (getCollection() != NULL && aValue->isJSONItem())
    {
      setJSONRoot(lValue, theRoot);
    }
    
    csize lPosition = thePairs.size();
    theKeys.insert(lName, lPosition);
    aName->addReference();
    lValue->addReference();
    if (lPosition == thePairs.size())
    {
      thePairs.push_back(std::make_pair(aName.getp(), lValue));
    } else { 
      thePairs[lPosition] = std::make_pair(aName.getp(), lValue);
    }

    ASSERT_INVARIANT();
    return true;
  }
  else if (accumulate)
  {
    csize lPosition;
    theKeys.get(lName, lPosition);
    assert(thePairs[lPosition].first->getStringValue() == lName);
    store::Item* lValue = thePairs[lPosition].second;

    if (lValue->isJSONArray())
    {
      static_cast<SimpleJSONArray*>(lValue)->push_back(aValue);
    }
    else
    {
      SimpleJSONArray_t array = new SimpleJSONArray();
      array->push_back(lValue);
      array->push_back(aValue);

      if (getCollection() != NULL)
      {
        setJSONRoot(array.getp(), theRoot);
      }

      lValue->removeReference();
      array->addReference();
      thePairs[lPosition].second = array;
    }
    ASSERT_INVARIANT();
    return true;
  }

  ASSERT_INVARIANT();
  return false;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::remove(const store::Item_t& aName)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();
  csize lPosition;
  store::Item_t lRes;

  if (!theKeys.get(lName, lPosition))
  {
    ASSERT_INVARIANT();
    return 0;
  }
  
  Pairs::iterator lIterator;
  csize lIteratorPosition;
  for (lIterator = thePairs.begin(), lIteratorPosition = 0;
       lIterator != thePairs.end();
       ++lIterator, ++lIteratorPosition)
  {
    if (lIteratorPosition < lPosition)
    {
      continue;
    }
  
    // This is the position we are looking for.
    else if (lIteratorPosition == lPosition)
    {
      // Preparing the returned item.
      assert(lIterator->first->getStringValue() == lName);
      lRes = lIterator->second;
      if (getCollection() != NULL && lRes->isJSONItem())
      {
        setJSONRoot(lRes.getp(), NULL);
      }

      // Erasing the corresponding entries.
      lIterator->first->removeReference();
      lIterator->second->removeReference();
      lIterator = thePairs.erase(lIterator);
      theKeys.erase(lName);
    }
    
    // Rebuilding the key positions after this removed pair.
    assert(lIterator->first != NULL);
    assert(lIterator->second != NULL);
    Keys::iterator lKeyIterator = theKeys.find(lIterator->first->getStringValue());
    assert(lKeyIterator != theKeys.end());
    assert(lKeyIterator.getValue() == lPosition + 1);
    lKeyIterator.setValue(lPosition);
  }

  ASSERT_INVARIANT();
  return lRes;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::setValue(
    const store::Item_t& aName,
    const store::Item_t& aValue)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();

  if (!theKeys.exists(lName))
  {
    ASSERT_INVARIANT();
    return NULL;
  }

  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == lName);
  store::Item_t lRes = thePairs[lPosition].second;

  if (getCollection() != NULL && lRes->isJSONItem())
  {
    setJSONRoot(lRes.getp(), NULL);
  }

  if (getCollection() != NULL && aValue->isJSONItem())
  {
    setJSONRoot(aValue.getp(), theRoot);
  }

  lRes->removeReference();
  aValue->addReference();
  thePairs[lPosition].second = aValue.getp();

  ASSERT_INVARIANT();
  return lRes;
}

/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::rename(
    const store::Item_t& aName,
    const store::Item_t& aNewName)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();
  zstring lNewName = aNewName->getStringValue();

  if (theKeys.exists(lNewName))
  {
    ASSERT_INVARIANT();
    return false;
  }
  
  if (!theKeys.exists(lName)) 
  {
    ASSERT_INVARIANT();
    return false;
  }

  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == lName);
  
  thePairs[lPosition].first->removeReference();
  aNewName->addReference();
  thePairs[lPosition].first = aNewName.getp();
  theKeys.erase(lName);
  theKeys.insert(lNewName, lPosition);

  ASSERT_INVARIANT();
  return true;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;

  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    if (lValue->isJSONObject())
    {
      assert(dynamic_cast<SimpleJSONObject*>(lValue));
      SimpleJSONObject* lObject = static_cast<SimpleJSONObject*>(lValue);

      lObject->setRoot(aRoot);
    }
    else if (lValue->isJSONArray())
    {
      assert(dynamic_cast<SimpleJSONArray*>(lValue));
      SimpleJSONArray* lArray = static_cast<SimpleJSONArray*>(lValue);
      
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONObject::getStringValue() const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getStringValue2(zstring& val) const
{
  ASSERT_INVARIANT();
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::appendStringValue(zstring& buf) const
{
  ASSERT_INVARIANT();
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::getObjectValue(const store::Item_t& aKey) const
{
  ASSERT_INVARIANT();
  zstring lName = aKey->getStringValue();
  if (!const_cast<Keys&>(theKeys).exists(lName))
  {
    return NULL;
  }

  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->equals(aKey));
  return thePairs[lPosition].second;
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONObject::getObjectKeys() const
{
  ASSERT_INVARIANT();
  return new KeyIterator(const_cast<SimpleJSONObject*>(this));
}


/******************************************************************************

*******************************************************************************/
const store::Collection* SimpleJSONObject::getCollection() const
{
  if (theRoot == this)
  {
    return theCollection;
  }
  else if (theRoot != NULL)
  {
    return theRoot->getCollection();
  }
  else
  {
    return NULL;
  }
}


#ifndef NDEBUG

/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::assertInvariant() const
{
  // Note: only root objects may point to a collection, so if theCollection ==
  // NULL, it doesn't mean that the object does not belong to a collection.
  assert(theCollection == NULL || theRoot == this);

  if (theRoot != NULL)
  {
    const store::Collection* lCollection = getCollection();
    assert(lCollection != NULL);

    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(theRoot);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(theRoot);

    assert(lObject != NULL || lArray != NULL);

    if (lObject != NULL) 
    {
      assert(lObject->isThisRootOfAllDescendants(theRoot));
      assert(lObject->isThisJSONItemInDescendance(this));
    }
    else
    {
      assert(lArray->isThisRootOfAllDescendants(theRoot));
      assert(lArray->isThisJSONItemInDescendance(this));
    }
  }

  assert(theKeys.size() == thePairs.size());

  for(Keys::iterator lIter = theKeys.begin();
      lIter != theKeys.end();
      ++lIter)
  {
    csize lPosition = lIter.getValue();
    assert(lPosition < thePairs.size());
    assert(thePairs[lPosition].first != NULL);
    assert(thePairs[lPosition].first->isAtomic());
    assert(thePairs[lPosition].first->getStringValue() == lIter.getKey());
    assert(thePairs[lPosition].second != NULL);
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if (theRoot != aRoot)
  {
    return false;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const SimpleJSONObject* lObject =
      dynamic_cast<const SimpleJSONObject*>(lValue);
    const SimpleJSONArray* lArray =
      dynamic_cast<const SimpleJSONArray*>(lValue);
 
   if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if (this == anItem)
  {
    return true;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const SimpleJSONObject* lObject =
      dynamic_cast<const SimpleJSONObject*>(lValue);
    const SimpleJSONArray* lArray =
      dynamic_cast<const SimpleJSONArray*>(lValue);
 
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}
#endif // NDEBUG


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::KeyIterator::~KeyIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::open()
{
  theIter = theObject->thePairs.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::KeyIterator::next(store::Item_t& res)
{
  while (theIter != theObject->thePairs.end() && theIter->first == NULL)
  {
    ++theIter;
  }
  if (theIter != theObject->thePairs.end())
  {
    res = theIter->first;
    ++theIter;
    return true;
  } else {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::close()
{
  theIter = theObject->thePairs.end();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Array                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONArray::getType() const
{
  return GET_STORE().JDM_ARRAY_QNAME;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::~SimpleJSONArray()
{
  ASSERT_INVARIANT();
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if (getCollection() != NULL && (*lIter)->isJSONItem())
    {
      setJSONRoot(*lIter, NULL);
    }
    (*lIter)->removeReference();
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const store::Item_t& aValue)
{
  ASSERT_INVARIANT();

  if (getCollection() != NULL && aValue->isJSONItem())
  {
    setJSONRoot(aValue.getp(), theRoot);
  }

  aValue->addReference();
  theContent.push_back(aValue.getp());

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  theContent.reserve(theContent.size() + members.size());
  add(theContent.size(), members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_front(const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  theContent.reserve(theContent.size() + members.size());
  add(0, members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& pos,
    const store::Item_t& member)
{
  ASSERT_INVARIANT();

  if (getCollection() != NULL && member->isJSONItem())
  {
    setJSONRoot(member.getp(), theRoot);
  }

  member->addReference();
  theContent.insert(theContent.begin() + (cast(pos) - 1), member.getp());

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos) - 1, members);

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_after(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos), members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::add(
    uint64_t aTargetPos,
    const std::vector<store::Item_t>& aNewMembers)
{
  ASSERT_INVARIANT();
  for (size_t i = 0; i < aNewMembers.size(); ++i)
  {
    store::Item* lItem = aNewMembers[i].getp();

    if (getCollection() != NULL && lItem->isJSONItem())
    {
      setJSONRoot(lItem, theRoot);
    }

    lItem->addReference();
    theContent.insert(theContent.begin() + aTargetPos + i, lItem);
  }

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::remove(const xs_integer& aPos)
{
  ASSERT_INVARIANT();
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    setJSONRoot(lItem.getp(), NULL);
  }

  lItem->removeReference();
  uint64_t lPosStartingZero = cast(aPos) - 1;
  theContent.erase(theContent.begin() + lPosStartingZero);

  ASSERT_INVARIANT();
  return lItem;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::replace(
    const xs_integer& aPos,
    const store::Item_t& value)
{
  ASSERT_INVARIANT();
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    setJSONRoot(lItem.getp(), NULL);
  }

  uint64_t pos = cast(aPos) - 1;

  if (getCollection() != NULL && value->isJSONItem())
  {
    setJSONRoot(value.getp(), theRoot);
  }

  theContent[pos]->removeReference();
  value->addReference();
  theContent[pos] = value.getp();
  
  ASSERT_INVARIANT();
  return lItem;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;

  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if ((*lIter)->isJSONObject())
    {
      assert(dynamic_cast<SimpleJSONObject*>(*lIter));
      SimpleJSONObject* lObject = static_cast<SimpleJSONObject*>(*lIter);

      lObject->setRoot(aRoot);
    }
    else if ((*lIter)->isJSONArray())
    {
      assert(dynamic_cast<SimpleJSONArray*>(*lIter));
      SimpleJSONArray* lArray = static_cast<SimpleJSONArray*>(*lIter);
      
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
uint64_t SimpleJSONArray::cast(const xs_integer& i)
{
  try 
  {
    return to_xs_unsignedLong(i);
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::getArrayValue(const xs_integer& aPosition) const
{
  ASSERT_INVARIANT();
  uint64_t lPos = cast(aPosition);

  if (lPos == 0 || lPos > theContent.size())
  {
    return 0;
  }
  else
  {
    return theContent[lPos-1];
  }
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONArray::getArrayValues() const
{
  ASSERT_INVARIANT();
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
xs_integer SimpleJSONArray::getArraySize() const
{
  ASSERT_INVARIANT();
  store::Item_t lRes;
  xs_integer lSize(theContent.size());
  return lSize;
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONArray::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  ASSERT_INVARIANT();
  SimpleJSONArray* lNewArray = const_cast<SimpleJSONArray*>(this);
  if (copymode.theDoCopy)
  {
    lNewArray = new SimpleJSONArray();
    lNewArray->theContent.reserve(theContent.size());

    for (Members::const_iterator lIter = theContent.begin();
         lIter != theContent.end();
         ++lIter)
    {
      store::Item_t lValue = *lIter;
      if (lValue->isJSONObject() ||
          lValue->isJSONArray() ||
          lValue->isNode())
      {
        lValue = lValue->copy(NULL, copymode);
      }
      lNewArray->push_back(lValue);
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    JSONArray* a = static_cast<JSONArray*>(parent);
    a->push_back(lNewArray);
  }

  return lNewArray;
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONArray::getStringValue() const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("array"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getStringValue2(zstring& val) const
{
  ASSERT_INVARIANT();
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::appendStringValue(zstring& buf) const
{
  ASSERT_INVARIANT();
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("array"));
}


/*******************************************************************************

********************************************************************************/
void SimpleJSONArray::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
  ASSERT_INVARIANT();
  // Ensures one either detaches or attaches.
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
  
  if (theCollection != NULL)
  {
    // Attach
    setRoot(this);
  }
  else
  {
    // Detach
    setRoot(NULL);
  }
  
  ASSERT_INVARIANT();
}

/******************************************************************************

*******************************************************************************/
const store::Collection* SimpleJSONArray::getCollection() const
{
  if (theRoot == this)
  {
    return theCollection;
  }
  else if (theRoot != NULL)
  {
    return theRoot->getCollection();
  }
  else
  {
    return NULL;
  }
}


#ifndef NDEBUG

/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::assertInvariant() const
{
  assert(theCollection == NULL || theRoot == this);
  if (theRoot != NULL)
  {
    const store::Collection* lCollection = getCollection();
    assert(lCollection != NULL);
    const SimpleJSONObject* lObject = dynamic_cast<const SimpleJSONObject*>(theRoot);
    const SimpleJSONArray* lArray = dynamic_cast<const SimpleJSONArray*>(theRoot);
    assert(lObject != NULL || lArray != NULL);
    if (lObject != NULL) {
      assert(lObject->isThisRootOfAllDescendants(theRoot));
      assert(lObject->isThisJSONItemInDescendance(this));
    } else {
      assert(lArray->isThisRootOfAllDescendants(theRoot));
      assert(lArray->isThisJSONItemInDescendance(this));
    }
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if(theRoot != aRoot)
  {
    return false;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(*lIter);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(*lIter);
    if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if(this == anItem)
  {
    return true;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(*lIter);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(*lIter);
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}

#endif // NDEBUG


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::ValuesIterator::~ValuesIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::open()
{
  theIter = theArray->theContent.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::ValuesIterator::next(store::Item_t& res)
{
  if (theIter != theArray->theContent.end())
  {
    res = *theIter;
    ++theIter;
    return true;
  }
  else
  {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::close()
{
  theIter = theArray->theContent.end();
}




} // namespace json
} // namespace simplestore
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
