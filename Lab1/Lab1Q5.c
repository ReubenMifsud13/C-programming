#include <stdio.h>

//Function prototyping:

void add(int num1, int num2);

void subtract(int num1, int num2);

void multiply(int num1, int num2);

int main(void){
    //calling all functions
    add(1,45);
    subtract(4, 7);
    multiply(6,5);
    return 0;
}

void add(int num1, int num2){ //addition function - displays the numbers added and their total
    printf("%d + %d = %d\n", num1, num2, (num1 + num2));
}

void subtract(int num1, int num2){ //subtraction function - displays the numbers subtracted and their result
    printf("%d - %d = %d\n", num1, num2, (num1 - num2));
}

void multiply(int num1, int num2){ //multiplication function - displays the numbers multiplied and their product
    printf("%d * %d = %d\n", num1, num2, (num1 * num2));
}