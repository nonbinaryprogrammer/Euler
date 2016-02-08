#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 4: Largest Palindrome Product
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99. Find the largest
 * palindrome made from the product of two 3-digit numbers.
 * Correct
 *******************************************************************************/

int palindrome(int prod) {
  int i, j;
  int r;
  int p[7], m, n;

  for(i=0; i<7; i++) {
    if(prod != 0) {
      r = prod % 10;
      prod = prod/10;
      p[i] = r;
    } else {
      p[i] = -1;
    }
  }

  i = 0;
  while(i<7) {
    j = i;
    if(p[i] == -1) {
      return 1;
    }
    m = p[i];
    while(p[j] != -1 && j<=7) {
      j++;
    }
    j--;
    if(m != p[j]) {
      return 0;
    }
    p[i] = -1;
    p[j] = -1;
    i++;
  }

  return 1;
}

int main() {
  int i, j;
  int prod, max;

  for(i=999; i>0; i--) {
    for(j=999; j>0; j--) {
      prod = i*j;
      if(palindrome(prod) == 1) {
        if(prod > max) {
          max = prod;
        }
      }
    }
  }

  printf("largest palindrome: %d\n", max);

  return 0;
}
