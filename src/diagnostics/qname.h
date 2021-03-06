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

#ifndef ZORBA_DIAGNOSTIC_QNAME_H
#define ZORBA_DIAGNOSTIC_QNAME_H

#include <zorba/config.h>

#include "store/api/item.h"

namespace zorba {
namespace diagnostic {

///////////////////////////////////////////////////////////////////////////////

template<class QNameType>
QNameType to_QName( store::Item_t const &qname ) {
  return QNameType(
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str()
  );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace diagnostic
} // namespace zorba

#endif /* ZORBA_DIAGNOSTIC_QNAME_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
