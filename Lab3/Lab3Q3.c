#include <stdio.h>
#define PIN 4723 //This is the PIN to guess

int get_int(void);

int main(void){
    int userGuess;
    int guessed = 0;

    for(int tries = 5; tries > 0; tries--){
        printf("Guess the PIN - 4-digit integer\n");
        userGuess = get_int();

        if (userGuess == PIN){
            guessed = 1; //successful guess
            break;
        }
    }

    if(guessed == 1){ //correct guess by the user
        printf("Correct Guess");
    }
    else{
        printf("Your number of tries has expired. The correct PIN was %d", PIN);
    }

    return 0;
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