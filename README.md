# Tap: Type Analyzer for PHP

Tap (**T**ype **A**nalyzer for **P**HP) is a static analyzer for PHP. Based on the optional PhpDoc of functions, methods and properties, Tap will try to deduce local variables' types and check the compatibility. It can reveal potential bugs before the code is really running on production.

## Why static analysis for PHP?

There are two main categories of programming languages: statically typed languages like C++/Java, and dynamically typed languages like Python/PHP/Javascript.

The dynamic languages have the benefits such as fast development speed, no need for compilation, flexible design patterns, and so on. However, this flexibility also comes together with vulnerability. In large codebase, it's very easy to make mistakes like passing a map to a function which is expecting a list, or trying to access a member function `$a->foo()` while `$a` is actually null. What's worse, these kind of bugs usually hide in a particular code path which couldn't be detected until it breaks on production.

Static analysing for dynamic languages tries to take advantage of both flexibility and rigorousness. By checking the code statically (i.e., without really running), the analyzer will try to deduce the types of local variables, check the compatibility of function arguments, check if a variable nullable or not, etc. Basically, static analysis will help you find bugs at development stage.

## Tap basic

Tap uses phpDoc-like for type declaration. [PhpDoc](https://www.phpdoc.org/docs/latest/index.html) is multi-line comments between `/**` and `*/`, containing annotations start with `@`. PhpDoc is also used by IDEs like PHPStorm for similar purpose.

The most useful annotations are `@param` (for function/method param type), `@return` (for function/method return type) and `@var` (for object property type). Here is an example:
```
<?php

class TestClass {
    /** @var int */
    private $intProperty;

    /** @var string */
    private $stringProperty;

    /**
     * @param string $str
     * @param int $i
     * @return int
     */
    public function foo($str, $i) {
        $x = $str . $this->stringProperty;   
        $y = $str + $this->intProperty;     // error because trying to add string with int
        return $this->intProperty + $i;
    }

    /**
     * @param int|null $nullableObj
     * @return int
     */
    public function unionTypeDemo($nullableObj) {
        $x = $nullableObj + 42;       // error because $nullableObj can be null
        if ($nullableObj !== null) {
            return $nullableObj + 42;   // tap is smart enough to know $nullableObj is not null here
        } else {
            return -1;
        }
    }

    /**
     * @param vector<int> $myVec
     * @param map<string,bool> $myMap
     */
    public function collectionTypeDemo($myVec, $myMap) {
        $myVec[1] = 2;
        $myVec[2] = "str";  // error
        $myMap[1] = true;   // error
        $myMap["str"] = true;
        $myMap["str"] = 42; // error
    }
}
```

Tap will report some errors:
```
$ ./tap_server -m single -f tap_example.php
[E_EXPECTED_TYPE] tap_example.php[17:14 - 17:38] Expect numeric type, actually get string
[E_EXPECTED_TYPE] tap_example.php[26:14 - 26:30] Expect numeric type, actually get int|null
[E_EXPECTED_TYPE] tap_example.php[40:9 - 40:17] Right-hand-side of assignment is expecting type int but got string
[E_MAP_KEY_TYPE] tap_example.php[41:9 - 41:17] expected key type string actually got int
[E_EXPECTED_TYPE] tap_example.php[43:9 - 43:21] Right-hand-side of assignment is expecting type bool but got int
```

Tap takes these annotations as source of truth, trying to deduce all local variables inside functions, and trying to report type incompatibilities. If you don't provide any annotation for your methods/properties, Tap can only do minimum work. So, to make full use of its power, please annotate your classes as much as possible.

Tap provides you many useful types. See the full document about Tap types.

If you want to know more about what types of errors Tap can detect, see the test php files at `tap/test/test_files/` and `tap/test/expected_output/`.

## Tap Usage

```
Usage: tap_server -m mode [-r report_file] [-d report_db_path] [-s src_root] [-f single_filename] [-v]
    -m: options are single/batch/daemon
    -r: optional, specify the report text file
    -d: specify the report db path, applied to batch and daemon mode
    -s: specify source root, which should contain .tap config file
        if not specified, we will start from current dir and going upward, until find .tap file
        this option applied to batch mode and daemon mode
    -f: specify the single php file to check, only applied to single mode
    -v: verbose output
```

Tap supports three running modes: single-file, batch, and daemon (experimental).

**Single Mode**

Single mode is mostly used for demonstrating Tap's basic functionality, and used for Tap's self-inspection test. Just use `-f` to specify a single php file you want to check. Please note that if this file uses any classes/functions/consts defined otherwhere, Tap won't know and simply report errors like `DEFINITION_NOT_FOUND`.

**Batch Mode**

Batch mode will do a full scan on the whole repository. If the `-s` argument specified, Tap will take it as the source root, and check `.tap` config file there. If `-s` isn't specified, Tap will try to find the first `.tap` file at or above current directory, and check all php files under the location where `.tap` resides.

Here is an example of `.tap` config file:
```
{
    "skip": [
        "asset/dirToSkip",
    ],
    "scanOnly": [
        "third-party-lib",
        "thrift-gen"
    ]
}
```

Basically you can specify which directories to skip, and which directories to be scan-only. "ScanOnly" means that Tap will only check the functions' signature but not the implementation, which is much faster than full scan. It can be applied to third-party libraries and auto-generated classes.

You can use `-r` to specify the human-readable error report file, and `-d` to specify the sqlite db file which is supposed to be read by web UI tool.

**Daemon Mode**

*Daemon mode is still under development. Be prepared to see any weird error if you want a try.*

Daemon mode is supposed to run interactively during your php development. After started, it will do a quick scan for the whole repo, only recording the types of class properties and function signatures, but skipping the function implementation. And it will keep watching for any file changes and updating the recorded signatures in realtime. And later, for example, if you think your change is ready, and want Tap do a full scan before you commit, you can explicitly tell Tap to do it on the files/directories you touched. This mode is hopefully much faster than batch mode, and more suitable for the development process.
