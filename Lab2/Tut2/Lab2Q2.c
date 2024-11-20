# include <stdio.h>

int main() {

  int value;
  float weight;
  
  printf("Enter your weight in pounds: \n");
  scanf("%f", &weight);

  // Platinum is $1770 / pound
  // 14.5 troy ounces in 1 pound

  value = 1770.0 * weight * 14.5;

  printf("%c", value);
  printf("Your weight in platinum costs: \n");
  printf("In decimal float: %.4f\n", value);
  printf("In decimal : %d\n", value);
  printf("In octal : %o\n", value);
  printf("In hexadecimal : %x\n", value);

}

/*
1. $4234725.00
2. $4234725.00
4. %f: $0.0000 %d: $4234725 The %f is not able to output the integer correctly.
5. The non-printable character is attempted to print it could result in odd behavior, such as no visible output or strange symbols on the screen ( � ).
*/