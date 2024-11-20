#include <stdio.h>

int main (void){
    int input, result = 1;
    // Asking for input and recording.
    printf("Enter a number n, for n!\n");
    scanf("%d", &input);

    // Calculating
    for(int i = input; i > 1; i--){
        result *= i;
    }

    // Outputting the result
    printf("The result of %d! is %d\n", input, result);
    return 0;
}