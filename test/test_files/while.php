<?php

$x = 1;
while ($x) {}   // error for $x's type

while (true) {
  $y = 2;
}

__tap_check($y, "int|null");
