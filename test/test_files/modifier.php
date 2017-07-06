<?php

class A {
    public $publicProp;
    private $privateProp;
    protected $protectedProp;
    var $defaultProp;

    function defaultMethod() {
        $this->privateA();
        $this->privateProp = 1;
    }

    public function publicA() {
    }

    private function privateA() {
    }

    protected function protectedA() {
    }
}

class B extends A {
    public function publicB() {
        $this->privateB();
        $this->privateA();  // wrong
        $this->protectedA();
        $this->publicA();
        $this->publicC();   // wrong
    }
    private function privateB() {}
}

class C {
    public function publicC() {}
}

$a = new A();
echo $a->publicProp;
echo $a->protectedProp; // wrong
echo $a->privateProp;   // wrong
echo $a->defaultProp;
$a->publicA();
$a->privateA();     // wrong
$a->protectedA();   // wrong
$a->defaultMethod();

$b = new B();
$b->publicB();
$b->publicA();
$b->publicC();      // wrong
$b->privateB();     // wrong

class D extends B {
    public function publicD() {
        $this->protectedA();
        $this->privateA();  // wrong
    }
}
