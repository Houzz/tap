<?php

function testPredefineConst() {
    $a = PHP_INT_MAX + 1;
    __tap_check($a, "int");
    $b = PHP_VERSION;
    __tap_check($b, "string");
}

