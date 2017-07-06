<?php

$arr = array();
foreach ($arr as $k => $v) {
  __tap_check($k, "any");
  __tap_check($v, "any");
}
foreach ($arr as $v) {
  __tap_check($k, "any");
}

/**
 * @var vector<string>
 */
$vec = array("str1", "str2");
foreach ($vec as $k => $v) {
   __tap_check($k, "int");
   __tap_check($v, "string");
}
foreach ($vec as $v) {
   __tap_check($v, "string");
}

$map = array("str1" => 1, "str2" => 2);
foreach ($map as $k => $v) {
  __tap_check($k, "string");
  __tap_check($v, "int");
}
foreach ($map as $v) {
  __tap_check($v, "int");
}

// check undefined variable
foreach ($arr as $v) {
  $x = 1;
}
__tap_check($x, "int|null");

$a = array("str1"); // this is considered as tuple
foreach ($a as $k => $v) {
  __tap_check($k, "int");
  __tap_check($v, "any");
}
foreach ($a as $v) {
  __tap_check($v, "any");
}

