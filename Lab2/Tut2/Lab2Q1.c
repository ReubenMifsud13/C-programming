#include <stdio.h>

int main (void){
    
    int input;
    // Asking for and storing user input.
    printf("Enter a character: ");
    scanf("%d", &input);

    // Converting the integer to the corresponding character and printing it
    printf("The integer %d is converted to %c.\n", input, (char)input);

    return 0;
}