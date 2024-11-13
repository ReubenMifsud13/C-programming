#include <stdio.h>
#include <math.h>

void toCeiling(double *num){
    *num = ceil(*num);
}

void toFloor(double *num){
    *num = floor(*num);
}

int main(void){
    double x = 5.12;
    printf("Before Ceiling: %lf\n", x);
    toCeiling(&x);
    printf("After Ceiling: %lf\n\n", x);

    double y = 5.12;
    printf("Before Floor: %lf\n", y);
    toFloor(&y);
    printf("After Floor: %lf\n", y);

    return 0;
}