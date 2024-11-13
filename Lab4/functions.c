#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include "functions.h"

// Iterative function
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}

void Fibonacci(int terms) {
    if (terms > 1) {
        int n1 = 0, n2 = 1, temp;
        printf("%d %d ", n1, n2); // Print the first two terms

        for (int count = 2; count < terms; count++) {
            temp = n2;
            n2 += n1;
            n1 = temp;
            printf("%d ", n2); // Print each next term
        }
    }
    else if (terms == 1) {
        printf("0 "); // Print the first term if terms is 1
    }
}

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

void toHex(int num){
    if(num == 0){
        return;
    }

    toHex(num / 16); //move 4 bits closer to most significant bit 

    printf("%x", (num % 16));
}

void reverse(char *s, int start, int end){
    if(start >= end){
        return;
    }

    //swap letters
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverse(s, start + 1, end - 1); //do the same with smaller bounds
}

void showDetails(char *string) {
    // Calculating length of string
    int length = 0;
    while (string[length] != '\0') { // Loop until End of String is found
        length++;
    }

    // Checking validity
    int valid = 1;
    for (int i = 0; i < length; i++) {
        if (isdigit(string[i])) {
            printf("String is Invalid (Contains numeric character/s)\n");
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("String is Valid\n");
    }

    printf("String Length: %d Characters\n", length);
    printf("First Character: %c\n", string[0]);

    // Calculating most frequent character(s) (mode/s)
    char modes[length];
    int max_count = 0, count, ptr = 0;

    for (int i = 0; i < length; i++) {
        count = 0;
        if (isdigit(string[i])) {
            continue; // Do not account for numbers
        }
        for (int j = 0; j < length; j++) {
            if (string[i] == string[j]) {
                count++;
            }
        }

        if (count > max_count) { // New mode
            ptr = 0; // Reset the modes array
            modes[ptr++] = string[i]; // Store new mode and increment ptr
            max_count = count;
        } else if (count == max_count) {
            // Check if the character is already in modes array
            int alreadyExists = 0;
            for (int k = 0; k < ptr; k++) {
                if (modes[k] == string[i]) {
                    alreadyExists = 1;
                    break;
                }
            }

            if (!alreadyExists) { // Add new mode character
                modes[ptr++] = string[i];
            }
        }
    }

    // Displaying Modes
    if (ptr == 1) { // Single mode
        printf("Mode = '%c'\n", modes[0]);
    } else { // Multiple modes
        printf("Modes = ");
        for (int i = 0; i < ptr; i++) {
            printf("'%c'", modes[i]);
            if (i < ptr - 1) {
                printf(", ");
            }
        }
        printf(".\n");
    }
}

void toCeiling(double *num){
    *num = ceil(*num);
}

void toFloor(double *num){
    *num = floor(*num);
}

int get_int(void){ //Validation of integer input

    int input;
    char ch;



    while (scanf("%d", &input) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input - Avoid infinite loops
            printf(" is not an integer.\nPlease enter an\ninteger value, such as 25, -178, or 3: ");
    }

    return input;

}

double get_double(void){ //Validation of integer input

    double input;
    char ch;



    while (scanf("%lf", &input) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input - Avoid infinite loops
            printf(" is not a double.\nPlease enter a\ndouble value, such as 25.6, 5.99, or 190.8: ");
    }

    return input;

}