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

#include <zorba/config.h>

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_CXX_NULLPTR

#include <zorba/internal/cxx_util.h>

zorba::internal::nullptr_type const zorba_nullptr = { };

#endif /* ZORBA_CXX_NULLPTR */

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
