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

SET(rubyPathFiles ${CMAKE_BINARY_DIR}/swig/ruby)
IF (MSVC_IDE)
  SET(rubyPath ${CMAKE_BINARY_DIR}/swig/ruby/@CMAKE_BUILD_TYPE@)
ELSE (MSVC_IDE)
  SET(rubyPath ${CMAKE_BINARY_DIR}/swig/ruby)
ENDIF (MSVC_IDE)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/books.xml ${CMAKE_CURRENT_BINARY_DIR}/books.xml COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/compilerHints.xq ${CMAKE_CURRENT_BINARY_DIR}/compilerHints.xq COPYONLY)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test01.rb ${CMAKE_CURRENT_BINARY_DIR}/test01.rb)
ADD_TEST("ruby_test01" ${RUBY_EXECUTABLE} test01.rb)
SET_TESTS_PROPERTIES("ruby_test01" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test02.rb ${CMAKE_CURRENT_BINARY_DIR}/test02.rb)
ADD_TEST("ruby_test02" ${RUBY_EXECUTABLE} test02.rb)
SET_TESTS_PROPERTIES("ruby_test02" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test03.rb ${CMAKE_CURRENT_BINARY_DIR}/test03.rb)
ADD_TEST("ruby_test03" ${RUBY_EXECUTABLE} test03.rb)
SET_TESTS_PROPERTIES("ruby_test03" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test04.rb ${CMAKE_CURRENT_BINARY_DIR}/test04.rb)
ADD_TEST("ruby_test04" ${RUBY_EXECUTABLE} test04.rb)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test04.xq ${CMAKE_CURRENT_BINARY_DIR}/test04.xq COPYONLY)
SET_TESTS_PROPERTIES("ruby_test04" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test05.rb ${CMAKE_CURRENT_BINARY_DIR}/test05.rb)
ADD_TEST("ruby_test05" ${RUBY_EXECUTABLE} test05.rb)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test05.xq ${CMAKE_CURRENT_BINARY_DIR}/test05.xq COPYONLY)
SET_TESTS_PROPERTIES("ruby_test05" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test06.rb ${CMAKE_CURRENT_BINARY_DIR}/test06.rb)
ADD_TEST("ruby_test06" ${RUBY_EXECUTABLE} test06.rb)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test06.xq ${CMAKE_CURRENT_BINARY_DIR}/test06.xq COPYONLY)
SET_TESTS_PROPERTIES("ruby_test06" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test07.rb ${CMAKE_CURRENT_BINARY_DIR}/test07.rb)
ADD_TEST("ruby_test07" ${RUBY_EXECUTABLE} test07.rb)
SET_TESTS_PROPERTIES("ruby_test07" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

# CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test08.rb ${CMAKE_CURRENT_BINARY_DIR}/test08.rb)
# ADD_TEST("ruby_test08" ${RUBY_EXECUTABLE} test08.rb)
# SET_TESTS_PROPERTIES("ruby_test08" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

# CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test09.rb ${CMAKE_CURRENT_BINARY_DIR}/test09.rb)
# ADD_TEST("ruby_test09" ${RUBY_EXECUTABLE} test09.rb)
# SET_TESTS_PROPERTIES("ruby_test09" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test10.rb ${CMAKE_CURRENT_BINARY_DIR}/test10.rb)
ADD_TEST("ruby_test10" ${RUBY_EXECUTABLE} test10.rb)
SET_TESTS_PROPERTIES("ruby_test10" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test11.rb ${CMAKE_CURRENT_BINARY_DIR}/test11.rb)
ADD_TEST("ruby_test11" ${RUBY_EXECUTABLE} test11.rb)
SET_TESTS_PROPERTIES("ruby_test11" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/satellites.json ${CMAKE_CURRENT_BINARY_DIR}/satellites.json COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/satellites.json ${CMAKE_CURRENT_BINARY_DIR}/satellites.json COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test12.rb ${CMAKE_CURRENT_BINARY_DIR}/test12.rb)
ADD_TEST("ruby_test12" ${RUBY_EXECUTABLE} test12.rb)
SET_TESTS_PROPERTIES("ruby_test12" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

# CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test13.rb ${CMAKE_CURRENT_BINARY_DIR}/test13.rb)
# ADD_TEST("ruby_test13" ${RUBY_EXECUTABLE} test13.rb)
# SET_TESTS_PROPERTIES("ruby_test13" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

#CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test14.rb ${CMAKE_CURRENT_BINARY_DIR}/test14.rb)
#ADD_TEST("ruby_test14" ${RUBY_EXECUTABLE} test14.rb)
#SET_TESTS_PROPERTIES("ruby_test14" PROPERTIES PASS_REGULAR_EXPRESSION "Success")

