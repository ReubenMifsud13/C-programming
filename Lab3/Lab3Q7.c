#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int errorCount = 0;
    int uppercaseFound;

    printf("Insert your text stream\n");
    char line[500];
    fgets(line, sizeof(line), stdin); //reading stream

    char *word = strtok(line, " \t");
   
    while(word != NULL){
        uppercaseFound = 0;
        int length = strlen(word);
        
        if(length > 10){
            if(strchr(word, '-') == NULL){ //i.e. Word is longer than 10 characters & contains no hyphen
                printf("WARNING: Word \'%s\' is longer than 10 characters & contains no hyphen\n", word);
                errorCount++;
            }
        }

        for(int i = 1; i < length; i++){
            if(isupper(word[i])){ //checking for uppercase letters beyond the 1st character
                errorCount++;
                if(uppercaseFound == 0){ //first finding of an uppercase letter
                    printf("WARNING: Word \'%s\' contains an uppercase character beyond the first character\n", word);
                    uppercaseFound = 1;
                }
            }
        }

        if(!(isalpha(word[0]))){ //checking if first letter is NOT alphabetical
            printf("WARNING: Word \'%s\' begins with a non-alphabetical character\n", word);
            errorCount++;
        }

        word  = strtok(NULL, " \t"); //adjusting pointer
    }

    if(errorCount == 0){
        printf("No errors found\n");
    }    
    else if(errorCount == 1){
        printf("1 error found\n");
    }
    else{
        printf("%d errors found", errorCount);
    }
    
    return 0;
}