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
#pragma once
#ifndef ZORBA_XERCESINCLUDES_H_
#define ZORBA_XERCESINCLUDES_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#ifdef __GNUC__
  // disable a warning in xerces 
#  pragma GCC diagnostic ignored "-Wparentheses"
#  pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#endif

#include <xercesc/util/XercesVersion.hpp>
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSConstants.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSValue.hpp>

#include <xercesc/framework/URLInputSource.hpp>

#if (XERCES_VERSION_MAJOR < 3)
#  include <xercesc/internal/XMLGrammarPoolImpl.hpp>
#else
#  include <xercesc/framework/XMLGrammarPoolImpl.hpp>
#endif

#include <xercesc/internal/BinMemOutputStream.hpp>
#include <xercesc/util/BinMemInputStream.hpp>

#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>

#include <xercesc/validators/common/GrammarResolver.hpp>
#include <xercesc/validators/schema/SchemaValidator.hpp>

#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/XMLUri.hpp>
#include <xercesc/util/XMLURL.hpp>

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wctor-dtor-privacy"
#  pragma GCC diagnostic warning "-Wparentheses"
#endif


//daniel: this is to make cygwin work; xerces defines WIN32 in case of cygwin, which is wrong
#ifdef CYGWIN
#undef WIN32
#endif

#endif //ZORBA_NO_XMLSCHEMA

#endif /*ZORBA_XERCESINCLUDES_H_*/
/* vim:set et sw=2 ts=2: */
