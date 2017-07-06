<?php

class A {}

function t() {
    $className = "classA";
    $a = new $className();
    __tap_check($a, "any");

    $a = new A();
    $b = $a->$methodName();
    __tap_check($b, "any");
    $c = $a->$propertyName;
    __tap_check($c, "any");
}

