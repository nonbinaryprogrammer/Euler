#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

class BigInt {
  private:
    int array[100000];
    int digits;

  public:
  /***************************************************************************
   * print number in big endian
   **************************************************************************/
  void print(void) {
    int i;

    for(i=digits-1; i>=0; i--) {
      printf("%d", array[i]);
    }
    printf("\n");

    if(digits == 0) {
      printf("0\n");
    }

    return;
  }

  /***************************************************************************
   * ASSIGNMENT OPERATOR OVERLOADS
   **************************************************************************/
  /***************************************************************************
   * begin =
   **************************************************************************/
  void operator=(int n) {
    digits = 0;
    while(n != 0) {
      array[digits] = n%10;
      n = n/10;
      digits++;
    }

    return;
  }

  void operator=(long n) {
    digits = 0;
    while(n != 0) {
      array[digits] = n%10;
      n = n/10;
      digits++;
    }

    return;
  }

  void operator=(string n) {
    digits = 0;
    while(n != "") {
      array[digits] = (int)n[n.size()-1] - 48;
      n.erase(n.size()-1);
      digits++;
    }

    return;
  }

  void operator=(const BigInt& n) {
    digits = 0;
    while(digits < n.digits) {
      array[digits] = n.array[digits];
      digits++;
    }

    return;
  }
  /***************************************************************************
   * end =
   **************************************************************************/

  /***************************************************************************
   * begin +=
   **************************************************************************/
  void operator+=(int n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(long n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(string n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(const BigInt& n) {
    BigInt s;

    s = (*this) + n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end +=
   **************************************************************************/

  /***************************************************************************
   * begin -=
   **************************************************************************/
  void operator-=(int n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(long n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(string n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(const BigInt& n) {
    BigInt s;

    s = (*this) - n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end -=
   **************************************************************************/

  /***************************************************************************
   * begin *
   **************************************************************************/
  void operator*=(int n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(long n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(string n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(const BigInt& n) {
    BigInt s;

    s = (*this) * n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end *
   **************************************************************************/

  /***************************************************************************
   * END ASSIGNMENT OPERATOR OVERLOADS
   **************************************************************************/
  
  /***************************************************************************
   * ARITHMETIC OPERATOR OVERLOADS
   **************************************************************************/
  /***************************************************************************
   * begin +
   **************************************************************************/
  BigInt operator+(int n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(long n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(string n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(const BigInt &n) {
    BigInt sol;
    int i, carry;

    sol = n;
    carry = 0;
    for(i=0; i<digits; i++) {
      array[i] += carry;
      carry = 0;
      if(i < sol.digits) {
        sol.array[i] += array[i];
        if(sol.array[i] > 9) {
          sol.array[i] %= 10;
          carry = 1;
        }
      } else {
        sol.array[i] = array[i] + carry;
        if(sol.array[i] > 9) {
          sol.array[i] %= 10;
          carry = 1;
        } else { carry = 0; }
        sol.digits++;
      }
    }
    if(carry == 1) {
      sol.array[sol.digits] = 1;
      carry = 0;
      sol.digits++;
    }

    return sol;
  }
  /***************************************************************************
   * end +
   **************************************************************************/

  /***************************************************************************
   * begin -
   **************************************************************************/
  BigInt operator-(int n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(long n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(string n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(const BigInt &n) {
    BigInt sol;
    int i, borrow;

    sol = (*this);
    borrow = 0;
    for(i=0; i<digits; i++) {
      sol.array[i] -= borrow;
      borrow = 0;
      if(i < n.digits) {
        sol.array[i] -= n.array[i];
      }
      if(sol.array[i] < 0) {
        sol.array[i] += 10;
        borrow = 1;
      }
    }
    while(sol.array[sol.digits-1] == 0) {
      sol.digits--;
    }

    return sol;
  }
  /***************************************************************************
   * end -
   **************************************************************************/

  /***************************************************************************
   * begin *
   **************************************************************************/
  BigInt operator*(int n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(long n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(string n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(const BigInt &n) {
    BigInt sol;
    int i, j, temp;

    sol = 0;
    if(n == 0) {
      return sol;
    }
    for(i=0; i<n.digits; i++) {
      temp = n.array[i];
      for(j=0; j<digits; j++) {
        sol.array[i+j] += temp * array[j];
        if(sol.digits <= i+j) {
          sol.digits++;
        }
        if(sol.array[i+j] > 9) {
          sol.array[i+j+1] += sol.array[i+j] / 10;
          if(sol.digits <= i+j+1) {
            sol.digits++;
          }
          sol.array[i+j] %= 10;
        }
      }
    }
    printf("sol count: %d\n", sol.digits);

    return sol;
  }
  /***************************************************************************
   * end *
   **************************************************************************/

  /***************************************************************************
   * begin arithmetic on digits
   **************************************************************************/
  BigInt sumdigits(void) {
    BigInt sum;
    int i;

    sum = 0;
    for(i=0; i<digits; i++) {
      sum += array[i];
    }

    return sum;
  }

  BigInt proddigits(void) {
    BigInt product;
    int i;

    product = 1;
    for(i=0; i<digits; i++) {
      product *= array[i];
    }

    return product;
  }
  /***************************************************************************
   * end arithmetic on digits
   **************************************************************************/

  /***************************************************************************
   * END ARITHMETIC OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * BEGIN LOGICAL OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * begin ==
   **************************************************************************/
  bool operator==(int n) {
    BigInt i;
    int j;

    i = n;

    if(digits != i.digits) {
      return 0;
    }

    for(j=0; j<digits; j++) {
      if(array[j] != i.array[j]) {
        return 0;
      }
    }

    return 1;
  }

  /***************************************************************************
   * end ==
   **************************************************************************/

  /***************************************************************************
   * END LOGICAL OPERATOR OVERLOADS
   **************************************************************************/
};

int main() {
  int i = 2000;
  BigInt b, c;

  printf("testing assignment (=):\n");
  b = i;
  b.print();
  c = b;
  c.print();
  b = (long)i;
  b.print();
  b = "2000";
  b.print();
  printf("\n");

  printf("testing +=:\n");
  c = i;
  c += (int)2111;
  c.print();
  c += (long)2111;
  c.print();
  c += "2111";
  c.print();
  b = 2111;
  b = 999;
  c += b;
  c.print();
  c += b;
  c.print();
  printf("\n");

  printf("testing +:\n");
  c = i;
  c = c + (int)2111;
  c.print();
  c = c + (long)2111;
  c.print();
  c = c + "2111";
  c.print();
  b = 999;
  c = c + b;
  c.print();
  c = c + b;
  c.print();
  printf("\n");

  printf("testing -:\n");
  c = 1000;
  b = 999;
  c = c - b;
  c.print();
  b = b - 123;
  b.print();
  b = b - (long)123;
  b.print();
  b = b - "123";
  b.print();
  printf("\n");

  printf("testing -=:\n");
  c = 1000;
  b = 999;
  c -= b;
  c.print();
  b -= 123;
  b.print();
  b -= (long)123;
  b.print();
  b -= "123";
  b.print();
  printf("\n");

  printf("testing *:\n");
  b = 4;
  c = 3;
  b = c * b;
  b.print();
  b = c * b;
  b.print();
  b = c * b;
  b.print();
  printf("\n");

  printf("testing sumdigits()\n");
  c = 123456789;
  b = c.sumdigits();
  b.print();
  printf("\n");

  printf("testing proddigits()\n");
  c = 123456789;
  b = c.proddigits();
  b.print();

  return 0;
}
