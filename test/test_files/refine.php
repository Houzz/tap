<?php

/**
 * @param string $str
 */
function takeString($str) {
}

/**
 * @param array $x
 */
function takeArray($x) {
}

/**
 * @param int $x
 */
function takeInt($x) {
}

/**
 * This one is valid.
 *
 * @param int|null $x
 * @return int
 */
function refine($x) {
    if ($x === null) {
        return 2;
    }
    return $x+1;
}

/**
 * @param string|null $x
 */
function refine2($x) {
    if ($x !== null) {
        takeString($x);
    } else {
        __tap_check($x, "null");
    }
}

/**
 * @param string|int|array $x
 */
function refine_is_xxx($x) {
    if (is_string($x)) {
        takeString($x);
    } else if (is_array($x)) {
        takeArray($x);
    } else {
        takeInt($x);
    }
}

/**
 * @param int|null $x
 */
function refine_isset($x) {
    if (isset($x)) {
        $x + 1;
    }
}

function refine3() {
    $x = "str";
    if (is_array($x))   // impossible to be executed
        takeArray($x);
    else if (is_string($x))
        $x + 1;     // incorrect
    else                // impossible to be executed
        $x + 1;
}

// TODO: is_int, etc

