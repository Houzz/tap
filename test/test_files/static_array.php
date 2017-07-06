<?php

class A {
    /** @var vector<int> */
    public static $arr = array(1);
    /** @var vector<vector<string>> */
    public static $arr2;

    public function fun() {
        __tap_check(self::$arr[1], "int");
        __tap_check(self::$arr2[0], "vector<string>");
        __tap_check(self::$arr2[0][0], "string");
    }
}

