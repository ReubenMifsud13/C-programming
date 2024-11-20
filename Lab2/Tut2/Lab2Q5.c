#include <stdio.h>

#define DAYS_IN_WEEK 7
#define MAX_INPUTS 10

int main (void){
    int inputs[10], days[10], weeks[10];

    // Asking and reading for user inputs.
    for(int i = 0; i < MAX_INPUTS; i++){
        printf("Enter a number of days: ");
        scanf("%d", &inputs[i]);
    }
    // Calculating Days and Weeks
    for(int i = 0; i < MAX_INPUTS; i++){
        weeks[i] = inputs[i]/DAYS_IN_WEEK;
        days[i] = inputs[i] - (weeks[i]*7);
    }
    // Outputting the numbers and results.
    for(int i = 0; i < MAX_INPUTS; i++){
        printf("%d Days convert to %d weeks & %d days.\n", inputs[i], weeks[i], days[i]);
    }
    return 0;
}