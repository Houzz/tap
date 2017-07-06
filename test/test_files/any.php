<?php

/**
 * If we can't get more information, assume everything is any
 */
function f($a) {
    __tap_check($a, "any");
    __tap_check($a->b, "any");
    __tap_check($a->method(1, "str"), "any");
}

