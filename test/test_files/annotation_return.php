<?php

/**
 * If no annotation, all of them are acceptable: return a value, return void, no return statement
 * btw, from the caller side, the return type will be considered as Any.
 *
 * @param int $a
 */
function noReturnAnnotation($a) {
    if ($a == 0) return;
    else if ($a == 1) return 1;
    else {
    }
}

/**
 * Explicit return type annotation, then return incompatible type, return void, or no return stmt will be wrong
 *
 * @param int $a
 * @return bool
 */
function returnValue($a) {
    if ($a == 0) return true;
    else if ($a == 1) return "str";  // wrong return type
}   // wrong because it's possible that no return stmt executed

/**
 * @param int $a
 * @return bool
 */
function returnValue2($a) {
    $a = 1;
    // wrong because of no return
}

/**
 * Explicit void return type, then return void and no return stmt will be correct
 *
 * @param int $a
 * @return void
 */
function returnVoid($a) {
  if ($a == 0) return;
  else return 1; // wrong
}

/**
 * @param int $a
 * @return void
 */
function returnVoid2($a) {
  $a = 1;
  // correct for no return stmt
}

