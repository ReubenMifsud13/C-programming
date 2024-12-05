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
    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }

    copyArr(array, newArray, SIZE);

    //print resultant array
    printf("\nResult: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", newArray[i]);
    }

    return 0;
}