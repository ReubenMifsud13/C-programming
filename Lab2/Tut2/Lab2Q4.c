#include <stdio.h>
#include <string.h>

// Arrays declared outside to be accessible to functions
char name[10][11];
char surname[10][11];
int age[10];
float salary[10];
float salary13[10];

// Function Prototyping
void tableInput(int start);
void tableOutput(int start);


int main(void){
    float avgSalary, totalSalary;

    tableInput(0);
    tableOutput(0);
    tableInput(5);
    tableOutput(5);
   
    // Summation of all 10 salaries
    for(int j = 0; j < 10; j++){
        totalSalary += salary[j];
    }
    // Average salary calculation
    avgSalary = totalSalary/10;
    printf("Average Salary of all 10 employees is: €%.2f \n", avgSalary);
    return 0;
}

// Input and truncation is handeled in the below function, aswell as the multiplication for the 13month salary.
void tableInput(int start){ // If 0, first half, If 5 second half.
    char temp[100]; // Temporary String buffer
    int end = start+5;


    for(int i = start; i < end; i++){
        printf("Employee No. %d:\n", (i+1));
        printf("Name: ");
        scanf("%s", &temp); // String is read into temp
       
        strncpy(name[i], temp, 10); // First 10 characters are copied to the array
        name[i][10] = '\0'; // The last character is then turned into the null-terminated


        printf("Surname: ");
        scanf("%s", &temp);


        strncpy(surname[i], temp, 10);
        surname[i][10] = '\0';
       
        printf("Age: ");
        scanf("%d", &age[i]);
       
        printf("Salary: ");
        scanf("%f", &salary[i]);
        salary13[i] = 13*salary[i];
        printf("\n");
    }


}

// Outputs the data into a table and requests the user to input the decimal places of the salary output.
void tableOutput(int start){ // If 0, first half, If 5 second half.
    int end = start+5;
    int dec;

    printf("How many decimal points do you want to add?\n");
    scanf("%d", &dec);

    printf("| %3s | %10s | %10s | %10s | %10s | %10s |\n", "Num", "Name", "Surname", "Age", "Salary", "13-Month");

    for(int i = start; i < end; i++){
        printf("| %3d | %10s | %10s | %10d | %10.*f | %10.*f |\n", (i+1), name[i], surname[i], age[i], dec,  salary[i], dec, salary13[i]);
    }
}