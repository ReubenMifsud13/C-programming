// fathm_ft.c -- converts 2 fathoms to feet

#include <stdio.h>

int main(void)

{

    int feet, fathoms; /*Declaration of integer variables: feet & fathoms are symbolic identifiers - they are the variable names of 2 integer variables respectively
                        A storage area of 2 or 4 bytes (int) is created and is represented by the variable name*/



    fathoms = 2; //fathoms (the lvalue) represents the memory address, 2 (the rvalue) is the content to be stored in the lvalue 'fathoms'

    feet = 6 * fathoms; //feet is the lvalue, 6*fathoms is the rvalue

    printf("There are %d feet in %d fathoms!\n", feet, fathoms);

    printf("Yes, I said %d feet!\n", 6 * fathoms);



    return 0;

}