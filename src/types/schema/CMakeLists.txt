# Copyright 2006-2016 zorba.io
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


IF (NOT ZORBA_NO_XMLSCHEMA)
    SET(SCHEMA_SRCS
        schema.cpp
        validate.cpp
        LoadSchemaErrorHandler.cpp
        PrintSchema.cpp
        EventSchemaValidator.cpp
        SchemaValidatorFilter.cpp
        StrX.cpp
        ValidationEventHandler.cpp
        revalidateUtils.cpp
        XercesParseUtils.cpp
        XercSchemaValidator.cpp
        )
ELSE (NOT ZORBA_NO_XMLSCHEMA)
    SET(SCHEMA_SRCS
        schema.cpp
        )
ENDIF (NOT ZORBA_NO_XMLSCHEMA)
