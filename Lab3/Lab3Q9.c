#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RANGE 250
#define MIN_RANGE -250

int main(void){
    //opening output file to write in:
    FILE *outputFile = fopen("output.txt", "w");
    if(outputFile == NULL){ //checking for erors while opening file
        perror("Error opening file");
        return 1;
    }

    char stream[500];
    
    printf("Insert a stream of real numbers (separate each one by whitespace)\n");
    //reading stream
    fgets(stream, sizeof(stream), stdin);

    //tokenizing stream of numbers by whitespace
    char *numtok = strtok(stream, " \t");
    
    double number;
    char *endPtr; //pointer for the strtod method

    while(numtok != NULL){
        number = strtod(numtok, &endPtr);

        if(endPtr != numtok){ //token is a valid number
            if (number >= MIN_RANGE && number <= MAX_RANGE) {
                // Write the valid number to the output file
                fprintf(outputFile, "%.2f\n", number);
            } else {
                printf("Warning: Number %.2f is out of the specified range [%d, %d]\n", number, MIN_RANGE, MAX_RANGE);
            }
        }
        else{
            printf("Warning: Invalid input '%s'. Not a valid number.\n", numtok);
        }

        //getting the next token
        numtok = strtok(NULL, " \t");
    }

    fclose(outputFile); //closing the file

    return 0;
}