#include <stdio.h>

int main(void)

{

    int dogs, cats;

    //Prompting & storing user input:
    printf("How many cats do you have?\n");

    scanf("%d", &cats);

    printf("How many dogs do you have?\n");

    scanf("%d", &dogs);

    printf("So you have %d dog(s) and %d cat(s)!\n", dogs, cats); //displaying cats & dogs separately

    printf("This gives a total of %d pets", (dogs+cats)); //displaying total cats & dogs

    return 0;

}