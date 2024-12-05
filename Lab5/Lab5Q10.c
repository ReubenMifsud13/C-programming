#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //Checking for incorrect input
    if(argc != 3){ //more/less than 2 inputs were given
        fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
        return 0;
    }
    
    char *endptr1, *endptr2;
    double num1 = strtod(argv[1], &endptr1); 
    //if argv[1] is not fully numerical, endptr1 will point to the first non-numerical value.
    //Otherwise is points to "\0"
    double num2 = strtod(argv[2], &endptr2);

    // Check for conversion errors
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        fprintf(stderr, "Error: Both arguments must be numeric.\n");
        return 1; // Return non-zero exit code to indicate error
    }

    // Add the two numbers
    double sum = num1 + num2;

    // Print the result
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, sum);
    return 0; // Return 0 to indicate success

    return 0;
}