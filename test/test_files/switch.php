<?php

/**
 * @param int|string $x
 */
function f($x) {
    switch ($x) {
    case 1:
        $y = 1;
        $z = 1;
        break;
    case "str":
        $y = "str";
        $z = "str";
        break;
    case true:  // error
        $z = 1;
        break;
    default:
        $z = 2;
    }
    __tap_check($y, "int|string|null");
    __tap_check($z, "int|string");
}
