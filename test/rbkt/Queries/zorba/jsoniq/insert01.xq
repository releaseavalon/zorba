import module namespace j = "http://www.jsoniq.org/functions";

variable $o := { "foo" : "bar" };

(j:insert-into($o, pair { "bar" : "foo" }), j:insert-into($o, pair { "blub": "so" })) ;

$o
