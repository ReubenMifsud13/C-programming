// gcc Ex8.c -lm FOR COMPILATION
#include <stdio.h>
#include <math.h>

int main (void){
    int iterations = 1; // By an iteration, one understands the amount of numbers to be computed and summed.
    double input, result = 0;
    
    // Asking for input and recording.
    printf("Enter a number s in the Riemann Zeta Function: ");
    scanf("%lf", &input);
    printf("Enter the number of iterations wanted: ");
    scanf("%d", &iterations);

    // Calculating
    for(int i = 1; i <= iterations; i++){
        result += pow(i, (-input));
    }

    // Outputting the result
    printf("The result is %.20lf\n", result);
    return 0;
}