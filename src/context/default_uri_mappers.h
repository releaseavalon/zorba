/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#pragma once
#ifndef ZORBA_DEFAULT_URI_MAPPERS_H
#define ZORBA_DEFAULT_URI_MAPPERS_H


/**
 * This file contains the Zorba built-in URI Mappers and URL
 * Resolvers.  This comprises the file: and http: URLResolvers and the
 * module-versioning and automatic filesystem URIMappers.
 */

#include <memory>
#include <istream>
#include <zorbatypes/zstring.h>
#include "context/uri_resolver.h"

namespace zorba {

namespace impl {

/**
 * @brief Automatic Filesystem URI Mapper.
 */
class ZorbaAutoFSURIMapper : public impl::URIMapper
{
public:

  virtual ~ZorbaAutoFSURIMapper();

  virtual impl::URIMapper::Kind mapperKind() throw ();

  virtual void mapURI(zstring const& aUri,
    Resource::EntityType aEntityType,
    static_context const& aSctx,
    std::vector<zstring>& oUris) throw ();
};


} /* namespace zorba::impl */

} /* namespace zorba */

#endif /* ZORBA_DEFAULT_URI_MAPPERS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
