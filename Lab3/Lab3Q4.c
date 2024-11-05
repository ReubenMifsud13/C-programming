#include <stdio.h>

int main(void){
    for(int rows = 1; rows <= 10; rows++){
        for(int columns = 1; columns <= 10; columns++){
            printf("%-3d ", (rows * columns));
        }
        printf("\n"); //new line
    }

    return 0;
}