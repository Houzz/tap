<?php

class A {
    const CA = 1;
    const CB = "str";
    const CC = true;
    const CD = -1;
    const REFER_OTHER_CLASS_AFTER = B::CONST_AFTER;
}

function checks() {
    __tap_check(A::CA, "int");
    __tap_check(A::CB, "string");
    __tap_check(A::CC, "bool");
    __tap_check(A::CD, "int");
    __tap_check(A::REFER_OTHER_CLASS_AFTER, "int");
}

/**
 * @param int $a
 */
function testConstAsDefault($a = A::CA) {
    __tap_check($a, "int");
}

class B {
    const REFER_OTHER_CONST = A::CA;
    const REFER_SELF_BEFORE = self::REFER_OTHER_CONST;
    const REFER_SELF_AFTER = self::CONST_AFTER;
    const CONST_AFTER = 3;
    const REFER_NOT_EXISTING = A::XXX;
}

function checks2() {
    __tap_check(B::REFER_OTHER_CONST, "int");
    __tap_check(B::REFER_SELF_BEFORE, "int");
    __tap_check(B::REFER_SELF_AFTER, "int");
    __tap_check(C::X_REFER_LOOP, "any");
}

class C {
    const SELF_REFER_LOOP = C::SELF_REFER_LOOP;
    const SELF_REFER_LOOP2 = self::SELF_REFER_LOOP2;
    const X_REFER_LOOP = D::X_REFER_LOOP_IN_D;
}

class D {
    const X_REFER_LOOP_IN_D = C::X_REFER_LOOP;
    const CONST_NEG_INT = -1;
    const CONST_NEG_FLOAT = -1.0;
}

