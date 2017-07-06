<?php

$x = new DateTime();
$timestamp = $x->getTimestamp();
__tap_check($timestamp, "int");

$y = new DateTime2();   // class not found

