#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Project Euler Problem 5: Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1
 * to 10 without any remainder. What is the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20?
 * Correct
 *******************************************************************************/

int main() {
  int num, div;

  num = 20;

  while(1) {
    for(div=20; div>0; div--) {
      if(num % div != 0) {
        num++;
        break;
      }
      if(div == 1) {
        printf("smallest number divisible by nums 1-20: %d\n", num);
        return 0;
      }
    }
  }

  return 0;
}
