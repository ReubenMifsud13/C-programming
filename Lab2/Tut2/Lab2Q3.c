# include <stdio.h>
# include <string.h>

void reverseWord(char word[]); // Function Prototyping

int main() {

    char word1[50], word2[50], word3[50];

    // Ask user to enter word, outputs beginning of outut and calls function.
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("The word reversed is: ");    
    reverseWord(word1);

    printf("Enter second word: ");
    scanf("%s", word2);
    printf("The word reversed is: ");
    reverseWord(word2);   

    printf("Enter third word: ");
    scanf("%s", word3);
    printf("The word reversed is: ");   
    reverseWord(word3);
    return 0;
}

void reverseWord(char word[]) {
    int len = strlen(word);  // Find the length of the word
    char rev[len];

    // Put the word in reverse order
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        rev[j] = word[i];
        j++;
    }
    rev[j] = '\0';

    // Prints the reversed word
    printf("%s\n", rev);
}