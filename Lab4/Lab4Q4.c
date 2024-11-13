#include <stdio.h>

void toHex(int num){
    if(num == 0){
        return;
    }

    toHex(num / 16); //move 4 bits closer to most significant bit 

    printf("%x", (num % 16));
}

void reverse(char *s, int start, int end){
    if(start >= end){
        return;
    }

    //swap letters
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverse(s, start + 1, end - 1); //do the same with smaller bounds
}

int main(void){
    printf("Insert number to convert to hex\n");
    int n;
    scanf("%d", &n);

    toHex(n);

    printf("\nInsert string to reverse\n");
    char string[20];
    int end = 0;
    scanf("%s", string);

    //getting actual end index to ignore NULL values
    while (string[end] != '\0') {
        end++;
    }
    end--;  // Set 'end' to the index of the last character

    reverse(string, 0, end);

    printf("Reversed string: %s\n", string);
    
    return 0;
}