#include <stdlib.h>
#include <stdio.h>

/*******************************************************************************
 * Project Euler Problem 9: Special Pythagorean Triplet
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which, a^2 + b^2 = c^2. There exits exactly one Pythagorean triplet for which
 * a + b + c = 1000. Find the product a*b*c.
 * Correct
 * Runs in O(333*449) = O(a*b)
 *******************************************************************************/

// 1000 = a + b + c, therefore:
// 0 <= a <= 332
// 1 <= b <= 449
// 2 <= c <= 999
//
// a^2 + b^2 = c^2, therefore:
// c = sqrt(a^2 + b^2)
//
// 1000 = a + b + sqrt(a^2 + b^2)

int main() {
  int a, b, c;

  for(a=0; a<=332; a++) {
    for(b=1; b<=449; b++) {
      c = 1000 - a - b;
      if(a*a + b*b == c*c) {
        printf("product of special pythagorean triplet: %llu\n", (unsigned long long)a*b*c);
      }
    }
  }

  return 0;
}
