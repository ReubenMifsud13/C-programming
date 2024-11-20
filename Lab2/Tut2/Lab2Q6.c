#include <stdio.h>

#define USD_EU 0.92
#define MAX_INPUTS 10

int main (void){
    float inputs[10], euro[10];

    for(int i = 0; i < MAX_INPUTS; i++){
        // Asking and reading for user inputs.
        printf("Enter a dollar quantity: $");
        scanf("%f", &inputs[i]);

        // Conversion
        euro[i] = USD_EU*inputs[i];

        // Printing the result
        printf("$%.2f converts to €%.2f.\n", inputs[i], euro[i]);
    }
    return 0;
}