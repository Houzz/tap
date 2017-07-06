<?php

for ($x = 0 , $y = 0 ; $x < 3 ; ++$x, ++$y) {
    $z = 10;
}

__tap_check($y, "int");
__tap_check($z, "int|null");

for ( ; ; ) {}
for ($x = 0 ; ; ++$x) {}
for ($x = 0 ; $x ; ++$x) {}  // wrong, $x need to be bool

