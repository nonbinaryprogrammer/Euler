#include "../MathLib/mathlib.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * Project Euler Problem 25: 1000-digit Fibonacci number
 * The Fibonacci sequence is defined by the recurrence relation Fn = Fn-1 +
 * Fn-2, where F1 = 1 and F2 = 1.
 * Correct
 *******************************************************************************/

int main() {
  int index;
  BigInt Fn, Fn1, Fn2;

  index = 12;
  Fn = 144;
  Fn1 = 89;

  while(Fn.length() < 1000) {
    Fn2 = Fn1;
    Fn1 = Fn;
    Fn = Fn1 + Fn2;
    index++;
  }

  printf("index: %d\n", index);

  return 0;
}
