#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int errorCount = 0;
    int uppercaseFound = 0;

    printf("Insert your text stream\n");
    char line[500];
    fgets(line, sizeof(line), stdin); //reading stream
   
    //Removing the \n for clarity of output
    if(line[strlen(line) - 1]  == '\n'){
        line[strlen(line)-1] = '\0';
    }

    //MODIFICATIONS:
    int i = 0;
    while(line[i] != '\0'){

        if(line[i] == ' ' && line[i+1] == ' '){ //checking for repeated spaces
            printf("WARNING: Repeated spaces found at index %d\n", i);
            errorCount++;
            //skipping over repeated spaces:
            while(line[i] == ' ') i++;
        }
        else{
            i++;
        }

        if(i > 0 && line[i-1] == ' ' && ispunct(line[i])){ //checking for punctuation after space
            printf("WARNING: Punctuation preceeded by a space at index %d\n", i);
            errorCount++;
        }
    }

    char *word = strtok(line, " \t"); //tokenizing the stream into words

    while(word != NULL){
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

    //displaying error count
    if(errorCount == 0){
        printf("No errors found\n");
    }    
    else if(errorCount == 1){
        printf("1 error found\n");
    }
    else{
        printf("%d errors found\n", errorCount);
    }
    
    return 0;
}