#include <stdlib.h>
#include <stdio.h>

/*******************************************************************************
 * Project Euler Problem 7: 10001st Prime
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13. What is the 10 001st prime number?
 * Correct
 *******************************************************************************/

int isprime(int n) {
  int i;

  for(i=2; i<n; i++) {
    if(n % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int prime, num;

  num = 14;
  prime = 6;

  while(prime < 10001) {
    if(isprime(num) == 1) {
      prime++;
    }
    if(prime != 10001) {
      num++;
    } else {
      break;
    }
  }

  printf("10001st prime: %d\n", num);

  return 0;
}
