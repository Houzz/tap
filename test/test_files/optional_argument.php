<?php

/**
 * @param int $a
 * @param int|null $b
 */
function checkOptionalParam($a, $b = null) {}

checkOptionalParam(3);
checkOptionalParam(3, 4);
checkOptionalParam(3, 4, 5);    // error, too more args
