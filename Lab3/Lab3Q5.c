#include <stdio.h>
#define numSize 20

int get_int();
int is_valid();
float mean_value();
int value_in_array();
int get_occurences();
void get_mode();

int main(void){
    int nums[numSize];
    int total = 0;
    float mean, median;

    printf("Insert an integer number from 1 to 100\n");
    nums[0] = get_int();
    total += nums[0];

    //Reading 20 numbers:
    for(int count = 1; count < numSize; count++){
        printf("Insert a number from 1 to 100 which is greater than or equal to %d: ", nums[(count-1)]);
        nums[count] = get_int();

        if(is_valid(nums[count-1], nums[count]) == 0){ //checking whether the integer is in ascending order & in range
            printf("The number you have inserted is invalid\n", nums[count]);
            count--;
            continue; //so to not count the total (for mean)
        }
        total += nums[count];
    }
    //calculating & displaying mean
    mean = mean_value(total, numSize);
    printf("Mean = %.2f\n", mean);

    //calculating & displaying median
    int middle = numSize / 2; //point to middle of array
    total = nums[middle] + nums[middle-1];
    median = mean_value(total, 2);
    printf("Median = %.2f\n", median);

    get_mode(nums); //calculates and displays the mode/s

    return 0;
}

int get_int(){
    int input;
    char ch;

    while(scanf("%d", &input) != 1){
        while((ch = getchar()) != '\n'); //discarding unwanted characters
        printf("Invalid Input. Insert an integer value: ");

    }
    return input;
}

int is_valid(int prev, int curr){
    if(prev > curr || curr < 1 || curr > 100){ //all invalid input
        return 0;
    }
    return 1; //case for when the integer is in ascending order
}

float mean_value(int total, int size){
    return (total / (float)size);
}

void get_mode(int *arr){
    int modes[numSize]; // Array to store multiple modes
    int pointer = 0;    // Pointer to track the number of modes
    int max_count = 0;  // Track the highest frequency

    // Find the mode(s)
    for(int i = 0; i < numSize; i++){
        int counter = get_occurences(arr, arr[i]);

        if(counter > max_count){ //finding the mode and its frequency
            max_count = counter;
            pointer = 0;
            modes[pointer] = arr[i];
        }
        else if(counter == max_count && arr[i] != modes[pointer]){ //searching for other numbers with the same frequency (also modes)
            pointer++;
            modes[pointer] = arr[i];
        }
    }

    // Display the mode(s)
    if (pointer == 0) { //print the single mode
        printf("Mode = %d\n", modes[0]);
    } else { //multiple modes exist
        printf("Modes = ");
        for(int i = 0; i < pointer; i++){
            printf("%d, ", modes[i]);
        }
        printf("%d.\n", modes[pointer]);
    }
}

int get_occurences(int *arr, int value){
    int counter = 0;
    for(int j = 0; j < numSize; j++){  //to count occurences of a specific number
        if(value == arr[j]){
            counter++;
        }
    }
    return counter;
}