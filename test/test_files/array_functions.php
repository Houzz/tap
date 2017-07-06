<?php

function f() {
    $a = array("str1" => 1, "str2" => 2);
    __tap_check($a, "map<string,int>");

    __tap_check(array_change_key_case($a), "map<string,int>");
    __tap_check(array_chunk($a, 2), "map<int,map<string,int>>");

    $b = array("str1", "str2");
    $c = array(true, false);
    __tap_check(array_combine($b, $c), "map<string,bool>");

    __tap_check(array_count_values($b), "map<string,int>");
    __tap_check(array_count_values($c), "map<bool,int>");

    __tap_check(array_fill_keys($b, 123), "map<string,int>");

    __tap_check(array_keys($a), "vector<string>");
    __tap_check(array_values($a), "vector<int>");

    __tap_check(array_flip($a), "map<int,string>");
    __tap_check(array_flip($b), "map<string,int>");

    array_diff($b, $c);     // error
}

