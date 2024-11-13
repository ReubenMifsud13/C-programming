#include <stdio.h>

void Fibonacci(int terms) {
    if (terms > 1) {
        int n1 = 0, n2 = 1, temp;
        printf("%d %d ", n1, n2); // Print the first two terms

        for (int count = 2; count < terms; count++) {
            temp = n2;
            n2 += n1;
            n1 = temp;
            printf("%d ", n2); // Print each next term
        }
    }
    else if (terms == 1) {
        printf("0 "); // Print the first term if terms is 1
    }
}

int RecFibonacci(int terms) {
    if (terms > 1) {
        return RecFibonacci(terms - 1) + RecFibonacci(terms - 2); //2 stack calls each time - high stack frame usage
                                                        //However, it is more readable because it only takes 1 loc
    }
    else if (terms == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    printf("Iterative Fibonacci:\n");
    Fibonacci(7);
    printf("\n");

    printf("Recursive Fibonacci:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", RecFibonacci(i));
    }
    printf("\n");

    return 0;
}