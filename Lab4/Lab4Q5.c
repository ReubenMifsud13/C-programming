#include <stdio.h>
#include <ctype.h>

void showDetails(char *string) {
    // Calculating length of string
    int length = 0;
    while (string[length] != '\0') { // Loop until End of String is found
        length++;
    }

    // Checking validity
    int valid = 1;
    for (int i = 0; i < length; i++) {
        if (isdigit(string[i])) {
            printf("String is Invalid (Contains numeric character/s)\n");
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("String is Valid\n");
    }

    printf("String Length: %d Characters\n", length);
    printf("First Character: %c\n", string[0]);

    // Calculating most frequent character(s) (mode/s)
    char modes[length];
    int max_count = 0, count, ptr = 0;

    for (int i = 0; i < length; i++) {
        count = 0;
        if (isdigit(string[i])) {
            continue; // Do not account for numbers
        }
        for (int j = 0; j < length; j++) {
            if (string[i] == string[j]) {
                count++;
            }
        }

        if (count > max_count) { // New mode
            ptr = 0; // Reset the modes array
            modes[ptr++] = string[i]; // Store new mode and increment ptr
            max_count = count;
        } else if (count == max_count) {
            // Check if the character is already in modes array
            int alreadyExists = 0;
            for (int k = 0; k < ptr; k++) {
                if (modes[k] == string[i]) {
                    alreadyExists = 1;
                    break;
                }
            }

            if (!alreadyExists) { // Add new mode character
                modes[ptr++] = string[i];
            }
        }
    }

    // Displaying Modes
    if (ptr == 1) { // Single mode
        printf("Mode = '%c'\n", modes[0]);
    } else { // Multiple modes
        printf("Modes = ");
        for (int i = 0; i < ptr; i++) {
            printf("'%c'", modes[i]);
            if (i < ptr - 1) {
                printf(", ");
            }
        }
        printf(".\n");
    }
}

int main(void) {
    printf("Insert a sequence of strings which must NOT include numeric characters\nInsert \\0 to stop\n");
    char str[50];
    while (scanf("%s", str) == 1) {
        if (str[0] == '\\' && str[1] == '0') { // Stop if "\0" is entered
            break;
        }
        showDetails(str);
    }
    return 0;
}