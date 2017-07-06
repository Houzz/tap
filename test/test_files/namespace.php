<?php

namespace test\space {

function testF() {
}

class A {
    const C = "str";
}

}

namespace test\space2 {

function testF() {  // not a dupliation
    $a = A::C;   // A::C not in namespace test\space2;
    __tap_check(\test\space\A::C, "string");
}

}

namespace test {
    function testF() {
        $a = space\A::C;
        __tap_check($a, "string");
    }
}
