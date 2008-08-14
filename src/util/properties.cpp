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
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

#include "util/properties.h"

#include "zorba/config.h"

#define CONFIG_FOLDER "zorba"
#define CONFIG_FILE "properties.cfg"

namespace po = boost::program_options;

namespace zorba
{
  struct env_mapper {
    std::string operator() (std::string name) {
      static const char *pfx = "ZORBA_";
      static int pfx_len = strlen (pfx);
      if (name.compare (0, pfx_len, pfx) != 0) return "";
      std::string result (name, pfx_len, std::string::npos);
      for (unsigned i = 0; i < result.length (); i++)
        if (result [i] == '_') result [i] = '-'; 
        else if (isupper (result [i])) result [i] += 'a' - 'A';
      return result;
    }
  };
  

  bool Properties::theLoaded = false;
  
  Properties::Properties() 
  : theQuery(""),
    theTraceParsing(false),
    theTraceScanning(false),
    theUseSerializer(false),
    theUseOptimizer(true),
    theResultFile(""),
    theUseResultFile(false),
    thePrintQuery(false),
    thePrintTime(false),
    thePrintAST(false),
    thePrintNormalizedExpressions(false),
    thePrintOptimizedExpressions(false),
    thePrintIntermediateOptimizations (false),
    thePrintIteratorTree(false),
    thePrintItemFlow(false),
    theStableIteratorIds(false),
    theNoTreeIds (false)
#ifndef NDEBUG
   ,theTraceTranslator(false)
   ,theTraceCodegen(false)
#endif
   ,theCompileOnly(false)
   ,theTimezone (0)
  {
  }
  
  bool Properties::getOSConfigFolder(std::string& aFolderURI) {
    char *pValue;
    
#ifdef __unix__
    pValue = getenv("HOME"); 
#elif defined WINCE
    pValue = NULL;
#elif defined WIN32
    size_t len;
    _dupenv_s( &pValue, &len, "APPDATA" );
#else
    pValue = getenv( "APPDATA" );
#endif
    if (pValue == 0)
      return false;
    aFolderURI = pValue;
    
    return true;
  }
  
  bool Properties::getOSConfigFile(std::string& aFileURI) {
    std::string lFolder;
    std::stringstream lStream;
    
    
    if (getOSConfigFolder(lFolder)) {
#if defined (WIN32) || defined (UNIX)
#define DOT_FILE "."
#else
#define DOT_FILE ""
#endif

#ifdef __win32__
      lStream << lFolder << "\\" << DOT_FILE CONFIG_FOLDER << "\\" << CONFIG_FILE;
# else
      lStream << lFolder << "/" << DOT_FILE CONFIG_FOLDER << "/" << CONFIG_FILE;
#endif
      aFileURI = lStream.str();
      return true;
    }
    return false;
  }
  
  Properties* Properties::instance(bool aCheckLoad)
  {
    static Properties lProperties;
    if (aCheckLoad && !theLoaded)
      lProperties.loadProps(0,0);
    return &lProperties;
  }

  
  /**
   * This function is programmed according to the description in
   * http://www.boost.org/doc/html/program_options/tutorial.html.
   * 
   * Important: 
   **/
  bool Properties::loadProps ( int argc, char *argv[])
  {
    std::string thePropFile;
    
    // Declaration of Generic Options
    po::options_description lGenericOptions ( "Generic Options" );
    lGenericOptions.add_options()
      ( "version,v", "print version std::string" )
      ( "help,h", "produce help message" )
      ( "property-file", po::value<std::string>(&thePropFile), "URI to property file")
    ;

    // Declaration of Configuration Options
    po::options_description lConfigOptions ( "Configuration Options" );
    lConfigOptions.add_options()
      // program flag. The value of the flag must be set at the end of this function
      ( "trace-parsing,p", "trace parsing" )
      ( "trace-scanning,s", "trace scanning" )
      ("use-serializer,r", "use serializer")
      ("optimizer,O", po::value<bool> (&theUseOptimizer), "optimization level (1=enabled (default), 0=off)")
      // program option with a value => the value is directly set to the variable theResultFile
      ("result-file,o", po::value<std::string>(&theResultFile), "result file")
      ("abort", "abort when fatal error happens")
      ("inline-query,e", "inline query")
      ("print-query,q", "print the query query")
      ("print-time,t", "print the execution time")
      ("print-ast,a", "print the parse tree")
      ("print-translated", "print the normalized expression tree")
      ("print-normalized,n", "print the translated expression tree")
      ("print-optimized", "print the optimized expression tree")
      ("print-iterator-tree,i", "print the iterator tree")
      ("print-item-flow,f", "show items produced by all iterators")
      ("stable-iterator-ids", "print the iterator plan with stable ids")
      ("no-tree-ids", "suppress ids and locations from compiler tree dumps")
      ("print-intermediate-opt", "print intermediate optimizations")
#ifndef NDEBUG
      ("trace-translator,l", "trace the translator")
      ("trace-codegen,c", "trace the codegenerator")
#endif
      ("compile-only", "only compile (don't execute)")
      ("tz", po::value<int>(&theTimezone), "implicit time zone (in minutes)")
      ("external-vars,x", po::value<std::vector<std::string> >(&theExternalVars), "external variables (e.g. -x x=file1.xml -x y:=strValue)")
    ;
  

    // Declaration of Hidden Options (hidden => not shown when --help is invoked)
    po::options_description lHiddenOptions ( "Hidden Options" );
    lGenericOptions.add_options()
      ( "input-query", po::value<std::string> ( &theQuery ), "input query (URI or query itself, default parameter)" )
    ;

    // Classifies everything which can be defined over the command line
    po::options_description lCmdlineOptions;
    lCmdlineOptions.add ( lGenericOptions ).add ( lConfigOptions );

    // Classifies everthing which can be defined over the configuration file
    po::options_description lConfigFileOptions;
    lConfigFileOptions.add ( lConfigOptions ).add ( lGenericOptions );

    // Classifies everthing which can be seen when --help is executed
    po::options_description lVisibleOptions ( "Allowed options" );
    lVisibleOptions.add ( lGenericOptions ).add ( lConfigOptions );

    // Classifies the option which can be passed without a name query or URI to query
    po::positional_options_description lPositionalOptions;
    lPositionalOptions.add ( "input-query",-1 );

    po::options_description lEnvOptions;
    lEnvOptions.add ( lGenericOptions ).add ( lConfigOptions );
      
    po::variables_map lVarMap;

    store (parse_environment(lEnvOptions, env_mapper()), lVarMap);

    // Applies the command line arguments
    if (argv != NULL)
      store ( po::command_line_parser ( argc, argv ).
              options ( lCmdlineOptions ).positional ( lPositionalOptions ).run(), lVarMap );
    
    // Ignites the command line parsing
    notify ( lVarMap );
    
    // Help output when demanded
    if ( lVarMap.count ( "help" ) )
    {
      std::cout << lVisibleOptions << std::endl;;
      return false;
    }

    // Version output when demanded
    if ( lVarMap.count ( "version" ) )
    {
      std::cout << "Zorba XQuery Engine, version 0.1" << std::endl;
      return false;
    }
    
    // parsing of the property file
    if (! thePropFile.empty ()) {
      std::ifstream lStreamFile( thePropFile.c_str() );
      if (!lStreamFile) {
        std::cerr << "Property file (" << thePropFile << ") not found" << std::endl;
        return false;
      }
      store ( parse_config_file(lStreamFile, lConfigFileOptions), lVarMap);
    } else {
      std::ifstream lStreamDot(CONFIG_FILE);
      if (lStreamDot) {
        store ( parse_config_file ( lStreamDot, lConfigFileOptions ), lVarMap );
      } else {
        std::string lFile;
        if (getOSConfigFile(lFile)) {
          std::ifstream lStreamHome(lFile.c_str());
          if (lStreamHome)
            store ( parse_config_file( lStreamHome, lConfigFileOptions ), lVarMap);
        }
      }
    }

    // Ignites the property file parsing
    notify ( lVarMap );

    // Setting flags
    theTraceParsing = (lVarMap.count("trace-parsing") != 0);
    theTraceScanning = (lVarMap.count("trace-scanning") != 0);
    theUseSerializer = (lVarMap.count("use-serializer") != 0);
    theUseResultFile = (lVarMap.count("result-file") != 0);
    theAbortWhenFatalError = (lVarMap.count("abort") != 0);
    theInlineQuery = (lVarMap.count("inline-query") != 0);
    thePrintQuery = (lVarMap.count("print-query") != 0);
    thePrintTime = (lVarMap.count("print-time") != 0);
    thePrintAST = (lVarMap.count("print-ast") != 0);
    thePrintNormalizedExpressions = (lVarMap.count("print-normalized") != 0);
    thePrintTranslatedExpressions = (lVarMap.count("print-translated") != 0);
    thePrintOptimizedExpressions = (lVarMap.count("print-optimized") != 0);
    thePrintIntermediateOptimizations = (lVarMap.count("print-intermediate-opt") != 0);
    thePrintIteratorTree = (lVarMap.count("print-iterator-tree") != 0);
    thePrintItemFlow = (lVarMap.count("print-item-flow") != 0);
    theStableIteratorIds = (lVarMap.count("stable-iterator-ids") != 0);
    theNoTreeIds = (lVarMap.count("no-tree-ids") != 0);
#ifndef NDEBUG
    theTraceTranslator = (lVarMap.count("trace-translator") != 0);
    theTraceCodegen = (lVarMap.count("trace-codegen") != 0);
#endif
    theCompileOnly = (lVarMap.count("compile-only") != 0);
    
    Properties::theLoaded = true;
    
    return true;
  }

  std::vector<std::pair<std::string,std::string> > Properties::getExternalVars() {
    std::vector<std::pair<std::string,std::string> > lResult;
    std::vector<std::string>::const_iterator lEnd = theExternalVars.end();
    for (
      std::vector<std::string>::const_iterator lIter = theExternalVars.begin();
      lIter != lEnd;
      ++lIter
    ) {
      std::string lStr = *lIter;
      std::string::size_type lPos = lStr.find_first_of("=");
      std::string lVarName = lStr.substr(0, lPos);
      std::string lValue = lStr.substr(lPos + 1);
      lResult.push_back(std::pair<std::string,std::string>(lVarName, lValue));
    }
    return lResult;
  }
  
  bool Properties::load(int argc, char *argv[]) {
    Properties* lProps = Properties::instance(false);
    return lProps->loadProps(argc, argv);
  }
} /* namespace zorba */
