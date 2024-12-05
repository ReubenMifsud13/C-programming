#include <stdio.h>

#define SIZE 101 //size of array dimensions

double func(int x, int y, int z){
    return x + (6*y) + (7.2*z);
}

int main(){
    double resultArr[SIZE][SIZE][SIZE];

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
                resultArr[i][j][k] = func(i,j,k);
            }
        }
    }
    return 0;

    //This program works, however due to very large stack frame usage (total no. of values = 101^3 > 1,000,000 outputs), it easily crashes.
}