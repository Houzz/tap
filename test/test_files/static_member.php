<?php

class A {
    /** @var int */
    public static $instance;

    public function testF() {
        A::$instance = 1;
        A::$instance = "abc";       // wrong
        self::$instance = 1;
        self::$instance = "abc";    // wrong
    }
}

class B {
    public static $staticVar = 1;
    public $nonStaticVar = "str";
    
    public static function staticFunc() {
        self::$staticVar = 2;
        $this->staticVar = 2;           // wrong, don't use $this in static method, and shouldn't access static via '->'
        self::$nonStaticVar = "str2";   // wrong, couldn't access non-static var from static method
        $this->nonStaticVar = "str2";   // wrong, don't use $this in static method
        self::nonStaticFunc();          // wrong, couldn't call non-static method from static method
        $this->nonStaticFunc();         // wrong, don't use $this in static method
    }

    public function nonStaticFunc() {
        self::$nonStaticVar = "str2";   // wrong, shouldn't access non-static var via '::'
        $this->nonStaticVar = "str2";
        self::$staticVar = 2;
        $this->staticVar = 3;   // wrong, should not access static variable via '->'
        self::staticFunc();
        $this->staticFunc();    // wrong
    }
}

function f() {
    B::nonStaticFunc();    // wrong
    B::staticFunc();
    $b = new B();
    $b::nonStaticFunc();    // wrong
    $b::staticFunc();
    $b->nonStaticFunc();
    $b->staticFunc();       // wrong
}

// test init static member with const
class D {
    const CONST_VALUE = 2;
    static $s1 = self::CONST_VALUE;
    static $s2 = self::CONST_VALUE2;
    const CONST_VALUE2 = 2;
    static $staticArray = array(self::CONST_VALUE, self::CONST_VALUE2);
}

__tap_check(D::$s1, "int");
__tap_check(D::$staticArray, "vector<int>");
