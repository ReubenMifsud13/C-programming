#include <stdio.h>
#include "functions.h"

void displayMenu(){
    printf("Select an option:\n");
    printf("1. Get Factorial\n2. Display Fibonacci Sequence\n3. Get GCD\n4. Get Hex Value\n5. Reverse a String\n");
    printf("6. Get the details of a String\n7. Round a number up\n8. Truncate a number down\n9. Quit\n");
}

int main(void){
    int userChoice, intNum, result, x, y, end = 0;
    char ch, input;
    double dNum;
    char str[50];

    do{
        displayMenu();
        userChoice = get_int();

        switch (userChoice){
        case 1:
            printf("Insert a number to get its factorial: ");
            intNum = get_int();
            printf("%ld\n", fact(intNum));
            break;
        
        case 2:
            printf("Insert number of terms you want for fibonacci: ");
            intNum = get_int();
            Fibonacci(intNum);
            break;

        case 3:
            printf("Insert a positive integer, y: ");
            y = get_int();
            printf("Insert another positive integer greater than %d: ", y);
            x = get_int();
            printf("%d\n", GCD(x, y));
            break;

        case 4:
            printf("Insert number to convert to hex: ");
            intNum = get_int();
            printf("Hex value of %d is: 0x", intNum);
            toHex(intNum);
            break;

        case 5:
            printf("\nInsert string to reverse (up to 20 characters)\n");
            scanf("%s", str);

            //getting actual end index to ignore NULL values
            while (str[end] != '\0') {
                end++;
            }
            end--;  // Set 'end' to the index of the last character

            reverse(str, 0, end);

            printf("Reversed string: %s\n", str);
            break;

        case 6:
            printf("Insert a sequence of strings which must NOT include numeric characters\nInsert \\0 to stop\n");
            while (scanf("%s", str) == 1) {
                if (str[0] == '\\' && str[1] == '0') { // Stop if "\0" is entered
                    break;
                }
                showDetails(str);
            }
            break;

        case 7:
            printf("Insert number to round up: ");
            dNum = get_double();
            printf("Before Ceiling: %lf\n", dNum);
            toCeiling(&dNum);
            printf("After Ceiling: %lf\n\n", dNum);
            break;

        case 8:
            printf("Insert number to truncate down: ");
            dNum = get_double();
            printf("Before Floor: %lf\n", dNum);
            toFloor(&dNum);
            printf("After Floor: %lf\n\n", dNum);
            break;

        case 9:
            printf("Insert 9 again to confirm quit\n");
            userChoice = get_int();
            break;

        default:
        printf("\nInvalid input\n");
            break;
        }
    }while(userChoice != 9);

    return 0;
}