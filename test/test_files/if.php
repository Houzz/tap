<?php

/**
 * We won't check if the boolean expression is tautology.
 *
 * @return string|int
 */
function checkIf() {
    if (true) {
        $x = 1;
    } else {
        $x = "hz";
    }
    __tap_check($x, "string|int");
    return $x;
}

/**
 * @return string|int
 */
function checkIf2() {
    $x = 1;
    if (true) {
        $x = "hz";
    }
    __tap_check($x, "string|int");
    return $x;
}

/**
 * @return int
 */
function checkIf3() {
    if (true)
        $x = 1;
    return $x;  // error, because x may be undefined
}

/**
 * @return string|int
 */
function checkMultiLayerIf() {
    $x = 1;
    if (true) {

    } else {
        if (false)
        if (true) {
            $x = "hz";
        }
    }
    __tap_check($x, "int|string");
    return $x;
}

function returnAnyType() {}

function checkNullMerge() {
    $x = null;
    if (true)
        $x = returnAnyType();
    __tap_check($x, "any");
}

function checkMergeToOne() {
    $x = "str";
    if (true) {
        __tap_check($x, "string");
        $x = 2;
    } else $x = 3;
    __tap_check($x, "int");
}

