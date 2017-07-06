<?php

list($a, $b) = array(1, "str");
__tap_check($a, "int");
__tap_check($b, "string");

list($a, $b) = array(1, 2);
__tap_check($a, "int");
__tap_check($b, "int");

list($a, list($b, $c)) = array(1, array(true, "str"));
__tap_check($a, "int");
__tap_check($b, "bool");
__tap_check($c, "string");

list($a, $b) = array(1);  // error

function func($anyTypeVar) {
    list($x, $y) = $anyTypeVar;
    __tap_check($x, "any");
    __tap_check($y, "any");
    list($x, list($y, $z)) = $anyTypeVar;
    __tap_check($x, "any");
    __tap_check($y, "any");
    __tap_check($z, "any");
}
