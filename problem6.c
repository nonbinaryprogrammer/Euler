#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 6: Sum Square Difference
 * The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... +
 * 10^2 = 385. The square of the sum of the first ten natural numbers is, (1 +
 * 2 + ... + 10)^2 = 55^2 = 3025. Hence the difference between the sum of the
 * squares of the first ten natural numbers and the square of the sum is 3025 −
 * 385 = 2640. Find the difference between the sum of the squares of the first
 * one hundred natural numbers and the square of the sum.
 * Correct
 *******************************************************************************/

int main() {
  int sosq, sqos;
  int i;

  sosq = 0;
  sqos = 0;

  for(i=1; i<101; i++) {
    sqos += i*i;
    sosq += i;
  }

  sosq = sosq*sosq;

  printf("diff: %d\n", sosq-sqos);

  return 0;
}
