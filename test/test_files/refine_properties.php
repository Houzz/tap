<?php

/**
 * @param string $str
 */
function takeString($str) {
}

/**
 * @param array $x
 */
function takeArray($x) {
}

/**
 * @param int $x
 */
function takeInt($x) {
}

class A {
    /** @var string|null */
    private $x;

    /** @var int|null */
    private static $static_var;

    public function testPropertyRefine() {
        if ($this->x !== null) {
            // TODO: takeString($this->x);
        }
        if (self::$static_var !== null) {
            // TODO: takeInt(self::$static_var);
        }
    }
}

