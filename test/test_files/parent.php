<?php

class A {
    public function foo() {
        echo "hello\n";
    }
}

class B extends A {
    public function foo() {
        parent::foo();
        parent::bar();  // error
    }
}

