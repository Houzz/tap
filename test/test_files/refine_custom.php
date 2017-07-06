<?php

class ClassA {
    public function foo() {}
};

/**
 * @param ClassA|null $p1
 */
function refineCustomClass($p1) {
    $p1->foo();     // error
    if ($p1 !== null) {
        $p1->foo();
        $p1->bar(); // error
    }
    $p1->foo();     // error
    if ($p1 === null)
        return;
    $p1->foo();
}

