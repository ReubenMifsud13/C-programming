#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L; /* initialize sum to zero */
    int status;

    printf("Please enter next integer (q to quit): ");

    while(scanf("%ld", &num) == 1){
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
    }

    printf("Those integers sum to %ld.\n", sum);

    return 0;
}
