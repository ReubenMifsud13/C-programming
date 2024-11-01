#include <stdio.h>

void butler(char *name);      /* ISO/ANSI C function prototyping */

int main(void)

{

    printf("I will summon the butler function.\n");

    butler("Reuben"); //string Reuben is inserted as arguments

    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");



    return 0;

}



void butler(char *name)          /* start of function definition, argument is passed as an array of chars */

{

    printf("You rang, %s\n", name);

}