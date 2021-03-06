(:
 : Copyright 2006-2016 zorba.io
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

module namespace mod2 = "http://www.mod2.com/";

import module namespace ddl = "http://zorba.io/modules/store/static/collections/dml";

import module namespace mod3 = "http://www.mod3.com/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/managers/module3.xq";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:ordered collection mod2:coll as node()*;

declare index mod2:index
  on nodes ddl:collection(xs:QName("mod2:coll"))
  by data(@id) as xs:string;


(: test that a temp index doesn't have impact on the indexes 
   returned by the static collection mgr :)
declare function mod2:foo()
{
  for $i in 1 to 10
  for $j in 1 to 10
  where $i eq $j
  return $i
};
