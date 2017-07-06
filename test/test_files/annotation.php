<?php

/**
 * @param string $str
 * @param int|null $arg2
 * @return string|bool
 */
function check($str, $arg2) {
    $result = $str . "cd";
    return $result;
}

function callerCorrect() {
    check("abc", 2);
}

function callerCorrectFewer() {
    check("abc");
}

function callerWrongTooFew() {
    check();
}

function callerWrongTooMany() {
    check("abc", 2, 3);
}

/**
 * @param int[]|string[] $a
 */
function testArray($a) {
}

/**
 * @param $a
 */
function testVarNameOnly($a) {
    __tap_check($a, "any");
}

