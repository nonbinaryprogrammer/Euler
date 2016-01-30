#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 1: Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000.
 * Correct
 *******************************************************************************/

int main() {
  int i, sum, n;

  sum = 0;

  for(i=1; i<1000; i++) {
    n = i+i+i;
    if(n >= 1000) {
      break;
    }
    sum += n;

    n = i*5;
    if(n < 1000 && n%3 != 0) {
      sum += n;
    }
  }

  printf("sum: %d\n", sum);

  return 0;
}
