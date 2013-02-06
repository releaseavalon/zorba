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
#ifndef ZORBA_STORE_SIMPLE_COLLECTION
#define ZORBA_STORE_SIMPLE_COLLECTION

#include "shared_types.h"

#include "collection.h"

#include "store/api/iterator.h"
#include "store/api/collection.h"
#include "tree_id.h"
#include "tree_id_generator.h"

#include "zorbautils/latch.h"
#include "zorbautils/checked_vector.h"


namespace zorba { namespace simplestore {


/*******************************************************************************
  theId:
  ------
  An internally generated unique id for the collection.

  theName:
  --------
  The user provided qname of the collection (inherited from simplestore::Collection).

  theIsDynamic:
  -------------
  Whether the collection is dynamic or not. Static (ie, non-dynamic) collections
  must be declared in the static context to be usable, whereas dynamic ones do
  not have any declarations. As far as the store is concerned, this property 
  is used only for naming purposes: a static and a dynamic collection may have
  the same name, so the isDynamic property is used to resolve such name conflicts.

  theTrees:
  ------------
  The root nodes of the XML and/or JSON trees that comprise this collection.

  theTreeIdGenerator:
  -------------------
  A generator of tree ids for the trees that belong to this collection. The
  generated tree ids are unique within the collection. Every time a tree is
  added to the collection it is assigned a new tree id that is generated by 
  this generator.

  theAnnotations:
  ---------------
  The properties of the collection. For static collections, the values of these
  properties are specified by the user in the collection declaration. Dynamic
  collections use pre-determined default values.

  theLatch:
  ---------
  Synchronizes concurrent accesses to the collection.
********************************************************************************/
class SimpleCollection : public Collection
{
  friend class CollectionIter;
  friend class UpdTruncateCollection;

public:
  class CollectionIter : public store::Iterator
	{
  protected:
    rchandle<SimpleCollection>              theCollection;
    checked_vector<store::Item_t>::iterator theIterator;
    checked_vector<store::Item_t>::iterator theEnd;
    bool                                    theHaveLock;
    xs_integer                              theSkip;

  public:
    CollectionIter(SimpleCollection* collection, const xs_integer& skip);

    ~CollectionIter();

    void open();
    bool next(store::Item_t& result);
    void reset();
    void close();

  private:
    void skip();
  };


protected:
  ulong                                  theId;

  checked_vector<store::Item_t>          theTrees;

  bool                                   theIsDynamic;

  TreeIdGenerator                      * theTreeIdGenerator;

  const std::vector<store::Annotation_t> theAnnotations;

  SYNC_CODE(Latch                        theLatch;)

protected:
  // default constructor added in order to allow subclasses to instantiate
  // a collection without name
  SimpleCollection();

public:
  SimpleCollection(
      const store::Item_t& name,
      const std::vector<store::Annotation_t>& annotations,
      bool isDynamic = false);

  virtual ~SimpleCollection();
  
  //
  // Store API methods
  //

  const store::Item* getName() const { return theName.getp(); }

  xs_integer size() const { return xs_integer( theTrees.size() ); }

  bool isDynamic() const { return theIsDynamic; }

  void getAnnotations(std::vector<store::Annotation_t>& annotations) const;

  store::Iterator_t getIterator(const xs_integer& skip, const zstring& start);

  bool findNode(const store::Item* node, xs_integer& position) const;

  store::Item_t nodeAt(xs_integer position);

  //
  // simplestore methods
  //
  ulong getId() const { return theId; }

  TreeId createTreeId();

  void addNode(store::Item* node, xs_integer position = xs_integer(-1));

  xs_integer addNodes(
      std::vector<store::Item_t>& nodes,
      const store::Item* targetNode,
      bool before);

  bool removeNode(store::Item* node, xs_integer& pos);

  bool removeNode(xs_integer position);

  void removeAll();

  xs_integer removeNodes(xs_integer position, xs_integer num);

  void adjustTreePositions();
};

} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
