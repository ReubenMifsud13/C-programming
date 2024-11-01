#include <stdio.h>

int main(void){
    int A3stock = 1000, A4stock = 1000, A5stock = 1000; // preset stock amount
    int newA3, newA4, newA5; //variables to store user input

    //Prompting & reading user input:
    printf("Please insert amount of A3 packs to order");
    scanf("%d", &newA3);
    A3stock -= newA3; //subtracting from stock
 
    printf("Please insert amount of A4 packs to order");
    scanf("%d", &newA4);
    A4stock -= newA4;

    printf("Please insert amount of A5 packs to order");
    scanf("%d", &newA5);
    A5stock -= newA5;
    
    printf("Updated stock:\nA3 packs:\t %d\nA4 packs:\t %d\nA5 packs:\t %d", A3stock, A4stock, A5stock);
    return 0;
}