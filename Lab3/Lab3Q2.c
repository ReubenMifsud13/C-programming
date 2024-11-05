#include <stdio.h>

int main(void){
    int status = 0;
    int n, factorial = 1;

    printf("Insert an integer number\n");
    status = scanf("%d", &n);
    
    while(status != 1){
        printf("Invalid input. Your input must be of type Integer\nRe-enter the integer number\n");
        status = scanf("%d", &n);
    }

    //Calculating n!
    for(int i = n; i > 1; i--){
        factorial *= i;
    }

    printf("%d! = %d\n5", n, factorial);

    return 0;
}