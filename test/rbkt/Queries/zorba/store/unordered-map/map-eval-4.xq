import module namespace map = "http://zorba.io/modules/unordered-maps";
import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";

map:create("map", xs:QName("xs:string"),{ "persistent": false() });
reflection:eval('map:available-maps()')

