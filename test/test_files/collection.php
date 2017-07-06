<?php

$varInt = 1;
$varStr = "ss";
$a = array();
__tap_check($a, "array");

$a = array(1, 2, $varInt);
__tap_check($a, "vector<int>");
$b = array(1, "str");
__tap_check($b, "tuple<int,string>");

/**
 * @var tuple<int,int,int>
 */
$a = array(1, 2, $varInt);
__tap_check($a, "tuple<int,int,int>");

$a = array(1 => $varStr, $varInt => "str2");
__tap_check($a, "map<int,string>");

$a = array($varInt, $varStr);
$a = array(1 => "str", 2 => $varInt); // error
$a = array(1 => $varStr, "str2" => "str3");   // error
$a = array(1 => "str", 2);  // error


$varArr = array();
$varArr[1] = 2;
$varArr["str"] = "value";

/**
 * @var vector<int>
 */
$varVec = array(1, 2, 3);
$varVec[1] = 2;
$varVec[2] = "str";     // wrong

$varMap = array("str" => 1);
$varMap["str2"] = 2;
$varMap["str2"] = "strValue";   // wrong
$varMap[2] = 1;         // wrong

__tap_check($varArr[1], "any");
__tap_check($varArr["s"], "any");
__tap_check($varVec[0], "int");
__tap_check($varMap["s"], "int");

$varArr[] = "str";
$varArr[] = 1;
$varVec[] = "str";  // wrong
$varVec[] = 1;
$varMap[] = 1;      // wrong

$a = array(1, "str", array(1, 2));
__tap_check($a, "tuple<int,string,vector<int>>");

$a = array("str");
__tap_check($a, "tuple<string>");
