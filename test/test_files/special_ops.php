<?php

function test() {
    $a = __DIR__;
    __tap_check($a, "string");
    $b = __FILE__;
    __tap_check($b, "string");
    $c = false;
    $d = !$c;
    __tap_check($d, "bool");
}
 
function test2() {
    $a = "str";
    $b = "this is embeded var $a";
    __tap_check($b, "string");
}

test();
