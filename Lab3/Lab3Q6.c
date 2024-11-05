#include <stdio.h>

int main(void){
    //Prompting & Calculating according to user input
    printf("What is your yearly pay in euros?");

    float yearlyPay, taxReduction;
    scanf("%f", &yearlyPay);
    getchar(); //dispose unwanted input

    char ictYorN, dispYorN; //Yes or No chars

    do{
        printf("Do you work in the ICT industry? Y/N\n");
        ictYorN = getchar(); //dispose unwanted input
        getchar();
        if (ictYorN != 'Y' && ictYorN != 'N'){ //validation
            printf("Invalid input. You must either enter Y or N.\n");
        }
        
    }while(ictYorN != 'Y' && ictYorN != 'N'); //keep iterating until the correct input is given

    do{
        printf("Do you collect old electronic equipment for green disposal? Y/N\n");
        dispYorN = getchar();
        getchar(); //dispose unwanted input
        if (dispYorN != 'Y' && dispYorN != 'N'){ //validation
            printf("Invalid input. You must either enter Y or N.\n");
        }
    }while(dispYorN != 'Y' && dispYorN != 'N'); //keep iterating until the correct input is given

    //Calculating Tax Reduction:
    int bracket1 = 10000;
    int bracket2 = 18000;

    if(dispYorN == 'Y'){
        bracket1 = 15000;
        bracket2 = 23000;
    }

    if(yearlyPay >= bracket1){
        taxReduction = bracket1 * 0.18;
        if(yearlyPay >= bracket2){
            taxReduction += 8000 * 0.20;
            if(yearlyPay > bracket2){
                taxReduction += (yearlyPay - 18000) * 0.25;
            }
        }
    }

    if(ictYorN == 'Y'){
        taxReduction -= taxReduction*0.05;
    }

    float netPay = yearlyPay - taxReduction;

    printf("Net Pay: Eur %.2f\n", netPay);

    return 0;
}