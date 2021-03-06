/*
 * Copyright 2006-2013 2006-2016 zorba.io.
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

#ifndef ZORBA_FTP_CLIENT_FTP_MODULE_H
#define ZORBA_FTP_CLIENT_FTP_MODULE_H

// standard
#include <map>

// Zorba
#include <zorba/external_module.h>

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

class module : public ExternalModule {
public:
  module();
  ~module();

  ItemFactory* getItemFactory() const;

  // inherited
  virtual void destroy();
  virtual ExternalFunction* getExternalFunction( String const& );
  virtual String getURI() const;

private:
  // map function names -> ExternalFunction*
  typedef std::map<String,ExternalFunction*> func_map_type;
  mutable func_map_type func_map_;
  mutable ItemFactory *item_factory_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba

#endif /* ZORBA_FTP_CLIENT_FTP_MODULE_H */
/* vim:set et sw=2 ts=2: */
