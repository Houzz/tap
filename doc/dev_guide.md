# Developer's Guide

## Introduction

The parser of Tap is modified from [Zend](https://github.com/php/php-src/tree/master/Zend)
and [HHVM](https://github.com/facebook/hhvm/tree/master/hphp/parser). The generated AST is mostly a simplifed version of the AST in HHVM.

Tap has two main passes for the code repository. For the first pass, Tap scans the "signatures" of functions,
class methods/properties/consts, but the implementation detail of functions/methods will be ignored.
The signatures will be stored into a (conceptually) large hash set. For the second pass, Tap will check
every line of each function implementation for any type incompatibility.

The first pass is much faster than the second full scan. This two-pass design will be helpful if we want to 
detect errors in realtime as the code is being changed in the future versions.

## Core internal concepts

### TapType hierarchy (tap/type/tap_type.h) 

```
 * Class Diagram:
 *
 * abstract TapType
 *      |
 *      |-----------------------------------------------------------------------------
 *      |                          |             |              |          |         |
 * abstract SingleTapType    UnionTapType   MixedTapType  AnyTapType  VoidType   UnresolvedType
 *      |
 *      |-----------------------------------
 *      |                   |              |
 *   PrimitiveTapType   CustomTapType    CollectionTapType
```

Here the `PrimitiveTapType` means null, integer, float, bool, string. `CustomTapType` means user-defined class.
`CollectionTapType` means vector, map and tuple.

`UnionTapType` is a list of SingleTapTypes, like `int|vector<string>|null`.

`VoidType` is only valid for function return type.

`UnresovledType` is not exposed to user. It is used as an intermediate type between the 2 passes. (See details below)

### Code Repository (tap/entity/class_repo.h and some others)

After the first pass, all types of "entities" will be stored into ClassRepo singleton (conceptually it's just a huge
hash map from name to the entity object.) And also, on initialization Tap will store all PHP built-in functions/classes/consts.

## Two Passes in detail

We use Visitor pattern for the passes. Specifically speaking, the parent abstract class is `AstVisitor` (visitor/ast_visitor.h).
We use `SignatureScanner` (visitor/signature_scanner.h) for the first pass, `FullAnalyzer` (visitor/full_analyizer.h) for the second pass.
And we use `ExpressionVisitor` (visitor/expression_visitor.h) when we need to process an expression (mostly for the second pass).

Between these two passes, there are actully more things to do:
* **Class Expansion**:
we add all the public and protected methods/properties of parent class into child class after the first pass. Otherwise we will have to search up the inheritance tree in the second pass everytime, which is considered too slow.
* **Cross reference resolving**: 
PHP allows cross-class reference like that:
```
class A {
    const CA = 1;
    const REFER_OTHER_CLASS_AFTER = B::CONST_AFTER;
}

class B {
    const REFER_OTHER_CONST = A::CA;
    const REFER_SELF_BEFORE = self::REFER_OTHER_CONST;
    const REFER_SELF_AFTER = self::CONST_AFTER;
    const CONST_AFTER = 3;
}
```
So we need find a toplogical order (and cycle detection) to resolve them or report error. This is also done between the first and second pass.

## Type refining

TODO

## Unit test

TODO

