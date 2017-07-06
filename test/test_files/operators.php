<?php

function f() {
    $x = true ? 1 : "str";
    __tap_check($x, "int|string");
    $x = "str" ? "yes" : "no";
    $x = (1 << 2);
    __tap_check($x, "int");
}

function f2() {
    $x = 1;
    $x += 2;

    $y = 1;
    $y <<= 2;
}

function f3() {
    $x = (1 <= 2);
    __tap_check($x, "bool");
    $x = ("str" <= 2);  // error
    $x = (1 == 3);
    $x = (1 == "str");  // error
}

