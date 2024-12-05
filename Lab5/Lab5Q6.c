#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 40
#define MAX_STRING_LENGTH 30
#define MAX_SUFFIX_LENGTH 10

// Function to safely get a single character
char getChar() {
    char ch = getchar();
    while (getchar() != '\n') continue; // Clear the input buffer
    return ch;
}

int main() {
    char strings[MAX_STRINGS][MAX_STRING_LENGTH]; // 2D array to store strings
    char suffix[MAX_SUFFIX_LENGTH];              // Suffix to append
    char choice;                                 // User's choice
    int stringsLen = 0;                          // Number of strings entered

    printf("Insert any amount of strings you like. Enter \\0 to stop.\n");

    // Input strings
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("\nString no. %d: ", i + 1);
        fgets(strings[i], MAX_STRING_LENGTH, stdin);

        // Remove trailing newline character, if any
        strings[i][strcspn(strings[i], "\n")] = '\0';

        // Check for termination input
        if (strcmp(strings[i], "\\0") == 0) {
            stringsLen = i; // Save the count of valid strings
            break;
        }
    }

    // Input the suffix
    printf("\nWhat is the suffix you would like to apply?\n");
    fgets(suffix, MAX_SUFFIX_LENGTH, stdin);

    // Remove trailing newline character from suffix, if any
    suffix[strcspn(suffix, "\n")] = '\0';

    // Ask the user whether to append the suffix to each string
    for (int i = 0; i < stringsLen; i++) {
        printf("\nInsert 'Y' if you want the suffix to be appended to \"%s\": ", strings[i]);
        choice = getChar();

        if (choice == 'Y') {
            // Ensure concatenation doesn't exceed maximum length
            if (strlen(strings[i]) + strlen(suffix) < MAX_STRING_LENGTH) {
                strcat(strings[i], suffix); // Appending the suffix
            } else {
                printf("Error: Suffix cannot be appended to \"%s\" as it exceeds the maximum length.\n", strings[i]);
            }
        }
    }

    // Printing results
    printf("\n\nRESULTS:\n");
    for (int i = 0; i < stringsLen; i++) {
        puts(strings[i]);
    }

    return 0;
}