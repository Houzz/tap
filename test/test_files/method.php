<?php

class A {
    public function func() {
    }
}

function testMethod() {
    $a = new A();
    $a->func();
    $a->func(1);    // error
    $a->notExisting();  // error
    $b = new B();   // error
}


