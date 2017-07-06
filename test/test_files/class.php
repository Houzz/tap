<?php

class ClassA {
  /**
   * @var float
   */
  public $p1, $p2;

  /**
   * @param int $a
   * @param string $b
   * @return bool
   */  
  public function methodA($a, $b) {
      $c = $a + 1;
      return $c;    // wrong return type
  }
}

