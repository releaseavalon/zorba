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
#ifndef ZORBA_VALIDATE_IMPL_H
#define ZORBA_VALIDATE_IMPL_H


#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/booleans/compare_types.h"
#include "types/delegating_typemanager.h"
#include "types/schema/SchemaValidator.h"
#include "zorbatypes/xqpstring.h"

namespace zorba
{

class RuntimeCB; // TODO we should have a shared_runtime_types.h
class GenericCast;

    /*______________________________________________________________________
    |
    | 3.13 
    | validate [ | lax | strict] {  } 
    |
    | A validate expression returns a new node with its own identity and 
    | with no parent. The new node and its descendants are given type 
    | annotations that are generated by applying a validation process to 
    | the operand node. In some cases, default values may also be generated 
    | by the validation process.
    |_______________________________________________________________________*/
class ValidateIterator : public UnaryBaseIterator<ValidateIterator, PlanIteratorState>
{
private:
  bool _isLax;
  rchandle<TypeManager> typemgr;

public:
  ValidateIterator (
        const QueryLoc& loc,
        PlanIter_t& aIter,
        TypeManager *,
        bool isLax );

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;

  static bool effectiveValidationValue (
        store::Item_t& result,
        const QueryLoc& loc, 
        PlanState& planState,
        const PlanIterator* iter,
        TypeManager *,
        bool isLax);

  static store::Item_t processElement (
        PlanState& planState,
        DelegatingTypeManager* delegatingTypeManager, 
        SchemaValidator& schemaValidator,
        store::Item *parent,
        const store::Item_t& element);
  
  static void validateAttributes (
        SchemaValidator& schemaValidator,
        store::Iterator_t attributes);

  static void processAttributes(
        PlanState& planState,
        DelegatingTypeManager* delegatingTypeManager,
        SchemaValidator& schemaValidator,
        store::Item *parent,
        store::Iterator_t attributes);

  static void processChildren (
        PlanState& planState,
        DelegatingTypeManager* delegatingTypeManager,
        SchemaValidator& schemaValidator,
        store::Item *parent,
        store::Iterator_t children);

  static void processNamespaces (
        SchemaValidator& schemaValidator,
        const store::Item_t& item);
        
  static void processTextValue (
        PlanState& planState,
        DelegatingTypeManager* delegatingTypeManager, 
        store::NsBindings& bindings,
        store::Item_t typeQName,
        xqpStringStore_t& textValue, 
        std::vector<store::Item_t> &resultList);

  ~ValidateIterator () {};
};

}

#endif // ZORBA_NO_XMLSCHEMA    
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
