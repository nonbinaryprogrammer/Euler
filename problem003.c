#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 3: Largest Prime Factor
 * The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime
 * factor of the number 600851475143 ?
 * Correct
 *******************************************************************************/

long long sqroot(long long num) {
  long long i;

  for(i=2; i<num; i+=2) {
    if(i == num/i) {
      printf("num: %llu, i: %llu\n", num, i);
      return i;
    }
  }

  printf("num: %llu, i: %llu\n", num, i);
  return num;
}

int main() {
  long long num = 600851475143;
  long long i, end;

  end = sqroot(num);

  for(i=3; i<end; i++) {
    while(1) {
      if(num % i == 0) {
        num = num/i;
        printf("%llu ", i);
      } else {
        break;
      }
    }
  }

  printf("%llu\n", num);

  return 0;
}
