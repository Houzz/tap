<?php

class A {}

$a = array();
$a[1] = 10;
$a["str"] = 100;
$num = 1;
$a[$num] = 10;
$b = new A();
$a[$b] = 10;    // wrong, only string and int can be used as array key
$b[1] = 10;     // wrong, $b is not an array
$a[] = "str";

