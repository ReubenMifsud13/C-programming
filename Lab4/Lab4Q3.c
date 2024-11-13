#include <stdio.h>

int GCD(int x, int y) {
    int gcd, temp;
    while(y != 0){
        gcd = x%y;
        temp = y; //for swap
        y = x % y;
        x = temp; 
    }
    return x;   
}

int RecGCD(int x, int y) {
    if (y == 0) {
        return x;
    }
    else {
        return RecGCD(y, x % y); //much more readable - but more stack usage
    }
}

int main(void) {
    int x = 20, y = 5; //x > y
    printf("Iterative GCD: %d\n", GCD(x,y));
    printf("Recursive GCD: %d\n", RecGCD(x,y));
    return 0;
}