#include <stdio.h>

// Iterative function
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}
// Recursive function
long rfact(int n) {
    long ans;
    if (n > 0)
        ans = n * rfact(n - 1); //value of the memory addressof this function call is pushed to stack each time
    else
        ans = 1;
    return ans;
}

int main(void){
    printf("Iterative = %d\nRecursive = %d", fact(4), rfact(4)); //check whether they both workd
    return 0;
}