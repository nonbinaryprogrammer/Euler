#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 4: Largest Palindrome Product
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99. Find the largest
 * palindrome made from the product of two 3-digit numbers.
 * Incorrect
 *******************************************************************************/

int palindrome(long long prod) {
  int i, j;
  long long r;
  char p[6], m, n;

  for(i=5; i>=0; i--) {
    r = prod % 10;
    prod = prod/10;
    p[i] = r + 30;
  }

  i=0;
  while(1) {
    m = p[i];
    if(p[i] != 0) {
      j = i;
      while(p[j] != 0) {
        j++;
      }
      j--;
    } else {
      return 1;
    }
    if(m != p[j]) {
      return 0;
    } else {
      p[i] = 0;
      p[j] = 0;
      i++;
    }
  }
}

int main() {
  int i, j;
  long long prod;

  for(i=999; i>0; i--) {
    for(j=999; j>0; j--) {
      prod = i*j;
      if(palindrome(prod) == 1) {
        printf("largest palindrome: %llu\n", prod);
        return 0;
      }
    }
  }

  return 0;
}
