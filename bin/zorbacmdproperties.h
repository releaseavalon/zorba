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
#ifndef ZORBA_CMD_PROPERTIES_H
#define ZORBA_CMD_PROPERTIES_H

#include <zorba/config.h>

#include "zorbacmdproperties_base.h"

class ZorbaCMDProperties : public zorbacmd::ZorbaCMDPropertiesBase {
public:
  struct ExternalVariable {
    std::string var_name;
    std::string var_value;
    bool        inline_file;
  };
  typedef std::vector<ExternalVariable> ExternalVars_t;
  typedef std::vector<std::string>      QueriesOrFiles_t;

protected:
  ExternalVars_t theExternalVars;

  unsigned int theRequestPort;
  unsigned int theEventPort;

public:
  ExternalVars_t::const_iterator
  externalVarsBegin() const  { return theExternalVars.begin(); }

  ExternalVars_t::const_iterator
  externalVarsEnd() const    { return theExternalVars.end(); }

  QueriesOrFiles_t::const_iterator
  queriesOrFilesBegin() const { return theQueriesOrFiles.begin(); }

  QueriesOrFiles_t::const_iterator
  queriesOrFilesEnd() const   { return theQueriesOrFiles.end(); }
  
  std::vector<std::pair<std::string,std::string> > 
  getSerializerParameters() const;
  
  bool hasNoSyntaxHighlighting(){ return theNoColors; }

  bool isDebugClient(){ return theDebugClient; }

  bool isDebugServer(){ return theDebugServer; }

  bool hasNoLogo(){ return theNoLogo; }

  unsigned int getRequestPort(){ return theRequestPort; }

  unsigned int getEventPort(){ return theEventPort; }

  std::string check_args ();

  void printHelp(std::ostream& os) const {
    os << "Zorba XQuery Engine\n";
    os << "Available options:\n";
    os << get_help_msg ();
  }

  bool loadProperties(int argc, char* argv[]);
};
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
