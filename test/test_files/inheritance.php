<?php

class A {
    const CONST_A = "str";
}

class B extends A {
    // const CONST_B = self::CONST_A;
}

function check() {
    __tap_check(B::CONST_A, "string");
}
