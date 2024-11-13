#include <stdio.h>

void toCeilingNoMath(double *num){
    *num = (double) (int) *num;
}

void toFloorNoMath(double *num){
    *num = (double) (int) (*num+1);
}

int main(void){
    double x = 5.12;
    printf("Before Ceiling: %lf\n", x);
    toCeilingNoMath(&x);
    printf("After Ceiling: %lf\n\n", x);

    double y = 5.12;
    printf("Before Floor: %lf\n", y);
    toFloorNoMath(&y);
    printf("After Floor: %lf\n", y);

    return 0;
}