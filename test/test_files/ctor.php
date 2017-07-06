<?php

class A {
    /**
     * @param int $a
     *
     */
    public function __construct($a) {
        echo $a + 1;
    }
}

$a = new A();           // error
$a = new A(1);

class B extends A {
    public function __construct() {
        parent::__construct();  // error
    }
}

class C extends A {
    public function __construct() {
        parent::__construct(1);
    }
}

$c = new C();
$c = new C(1);      // error

class D extends A {
    /**
     * @param string $x
     */
    function D($x) {
        parent::__construct(3);
    }
}

$d = new D();       // error
$d = new D(2);      // error
$d = new D("str");

