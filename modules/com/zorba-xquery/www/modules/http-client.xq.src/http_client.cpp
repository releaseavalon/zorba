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
#include <curl/curl.h>
#include <map>
#include <zorba/zorba.h>
#include <zorba/serializer.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/empty_sequence.h>

#include "http_request_handler.h"
#include "request_parser.h"
#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba {

  namespace http_client {
    
    class HttpSendFunction : public NonePureStatelessExternalFunction {
    protected:
      const ExternalModule*     theModule;
      ItemFactory*              theFactory;
      
    public:
      HttpSendFunction(const ExternalModule* aModule) 
      : theModule(aModule),
      theFactory(Zorba::getInstance(0)->getItemFactory()) {}
      
      virtual ~HttpSendFunction() {}
      
    public:
      virtual String
      getURI() const { return theModule->getURI(); }
      
      virtual String
      getLocalName() const { return "http-sequential-impl"; }
      
      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aStaticContext, const DynamicContext* aDynamicContext)
      const;
    };
    
    class HttpReadFunction : public HttpSendFunction {
    public:
      HttpReadFunction(const ExternalModule* aModule) 
      : HttpSendFunction(aModule) {}
      
      virtual ~HttpReadFunction() {}
      
    public:
      virtual String
      getLocalName() const { return "http-nondeterministic-impl"; }
      
    }; 
    
    class HttpClientModule : public ExternalModule {
    protected:
      class ltstr
      {
      public:
        bool operator()(const String& s1, const String& s2) const
        {
          return s1.compare(s2) < 0;
        }
      };
      
      typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;
      
      mutable FuncMap_t theFunctions;
      
    public:
      virtual ~HttpClientModule();
      
      HttpClientModule() 
      {
        for (FuncMap_t::const_iterator lIter = theFunctions.begin();
             lIter != theFunctions.end(); ++lIter) {
          delete lIter->second;
        }
        theFunctions.clear();
      }
      
      virtual String
      getURI() const { return "http://www.zorba-xquery.com/modules/http-client"; }
      
      virtual StatelessExternalFunction*
      getExternalFunction(String aLocalname) const
      {
        StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
        if (!lFunc) {
          if (aLocalname.equals("http-sequential-impl")) {
            lFunc = new HttpSendFunction(this);
          } else if (aLocalname.equals("http-nondeterministic-impl")) {
            lFunc = new HttpReadFunction(this);
          } 
        }
        return lFunc;
      }
      
      virtual void
      destroy()
      {
        if (!dynamic_cast<HttpClientModule*>(this)) {
          return;
        }
        delete this;
      }
    };

    ItemSequence_t
    general_evaluate(const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext,
      ItemFactory* aFactory)
    {
      CURL* lCURL = curl_easy_init();
      CURLM* lCURLM = curl_multi_init();
      
      Item lRequest;
      Item lHref;
      Item lContent;

      bool lReqSet = args[0]->next(lRequest);
      bool lHrefSet = args[1]->next(lHref);

      std::string lData;

      std::auto_ptr<HttpRequestHandler> lHandler;
      std::auto_ptr<RequestParser> lParser;
      struct curl_slist* lHeaderList = 0;

      if (lReqSet) {
        lHandler.reset(new HttpRequestHandler(lCURL, args[2]));
        lParser.reset(new RequestParser(lHandler.get()));
        lParser->parse(lRequest);
      }
      if (lHrefSet) {
        curl_easy_setopt(lCURL, CURLOPT_URL, lHref.getStringValue().c_str());
      }
      curl_easy_setopt(lCURL, CURLOPT_USERAGENT, "libcurl-agent/1.0");
      HttpResponseHandler lRespHandler(aFactory);
      //This gives the ownership of lCurl to the HttpResponseParser
      String lOverrideContentType;
      if (lHandler.get())
        lHandler->getOverrideContentType(lOverrideContentType);
      bool lStatusOnly =
          lHandler.get() == NULL ? false : (lHandler->isStatusOnly() || lHandler->isHeadRequest());
      HttpResponseParser lRespParser(lRespHandler, lCURL, lCURLM,
        lOverrideContentType.c_str(), lStatusOnly);
      lRespParser.parse();

      if (lHeaderList) {
        curl_slist_free_all(lHeaderList);
      }

      return ItemSequence_t(lRespHandler.getResult());
    }

    ItemSequence_t 
    HttpSendFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext) const 
    {
      return general_evaluate(args, aStaticContext, aDynamicContext, theFactory);
    }

    HttpClientModule::~HttpClientModule()
    {
      for (FuncMap_t::const_iterator lIter = theFunctions.begin();
           lIter != theFunctions.end(); ++lIter) {
        delete lIter->second;
      }
      theFunctions.clear();
    }

  } // namespace http_request
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::http_client::HttpClientModule();
}

