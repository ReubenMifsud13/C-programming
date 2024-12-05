#include <stdio.h>

#define SIZE 5

void copyArr(int ogArr[], int newArr[], int sizeOfBoth){
    for(int i = 0; i < sizeOfBoth; i++){
        newArr[i] = ogArr[i];
    }
}

int main(void){
    int array[] = {1,5,7,9,10};
    int newArray[SIZE];

    //print original array
    printf("Original: ");
    for(int i = 0; i < SIZE+4; i++){
        printf("%d ", array[i]);
    }
    
    copyArr(array, newArray, SIZE+4);

    //print resultant array
    printf("\nResult: ");
    for(int i = 0; i < SIZE+4; i++){
        printf("%d ", newArray[i]);
    }

    /*
     Because there is no bounds checking in C, the program will run without crashing.
     However, now not only is the data for newArray updated,
     but so is the data in the following memory locations - i.e. Corruption of Memory
    */
    return 0;
}