<?php

class A {
    public function fa() {}
}

class B {
    /** @var A */
    private $a;

    public function fb() {
        $aa = new A();
        $aa->fa();
        $aa->fb(); // error

        $this->a = new A();
        $this->a->fa();
        $this->a->fb(); // error

        $this->a = new C(); // error
        $this->a = new D();
    }
}

class C {}
class D extends A {}

class A2 {
    /** @var A */
    public $a, $b = null, $c = 2;

    /** @var int */
    public $inta = 3, $intb;

    public $noDocA = "str", $noDocB;

    public function f() {
        __tap_check($this->a, "A");
        __tap_check($this->b, "A|null");
        __tap_check($this->c, "A");
        __tap_check($this->inta, "int");
        __tap_check($this->intb, "int");
        __tap_check($this->noDocA, "string");
        __tap_check($this->noDocB, "any");
    }
}

