#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defining Employee Structure
typedef struct {
    int ID;
    char name[30];
    char surname[30];
    float salary;
} Employee;

// Function Prototypes
int cmpID(const void *a, const void *b);
int cmpSurname(const void *a, const void *b);
void print_employees(Employee **employees, int size);

int main() {
    // Initializing Employee Database
    Employee db[] = {
        {123, "Jake", "Pace", 3000.25},
        {200, "Paul", "Mizzi", 1042.50},
        {53, "Abdullah", "Pisani", 4002.9},
        {1125, "Zackary", "Michallef", 1234.1},
        {500, "John", "Doe", 1240.82}
    };

    int size = sizeof(db) / sizeof(db[0]); // Calculate the number of employees

    // Creating pointers for sorting (by ID and Surname):
    Employee *point_by_id[size];       // Array to hold pointers sorted by ID
    Employee *point_by_surname[size]; // Array to hold pointers sorted by surname

    // Populating pointer arrays
    for (int i = 0; i < size; i++) {
        point_by_id[i] = &db[i];       // Pointing to the original Employee records
        point_by_surname[i] = &db[i]; // Same here
    }

    // Sorting pointers using qsort:
    qsort(point_by_id, size, sizeof(Employee *), cmpID);        // Sort by ID
    qsort(point_by_surname, size, sizeof(Employee *), cmpSurname); // Sort by Surname

    // Displaying results:
    printf("Employees sorted by ID:\n");
    print_employees(point_by_id, size); // Print sorted by ID

    printf("\nEmployees sorted by Surname:\n");
    print_employees(point_by_surname, size); // Print sorted by surname

    return 0;
}

// Comparison function for sorting by ID
int cmpID(const void *a, const void *b) {
    Employee *employee_a = *(Employee **)a; // Casting Employee** to a (which was void**) and dereferencing (so we get pointer to Employee)
    Employee *employee_b = *(Employee **)b;
    return (employee_a->ID) - (employee_b->ID); /*-> used to point to certain element of Employee
                                                  We are getting the actual employee through employee_a and then getting ID
                                                  The return will either be +ve, -ve or 0. qsort will swap according to result
                                                */
}

// Comparison function for sorting by Surname
int cmpSurname(const void *a, const void *b) {
    Employee *employee_a = *(Employee **)a; // Same as above, but this time sorting by surname
    Employee *employee_b = *(Employee **)b;
    return strcmp(employee_a->surname, employee_b->surname); // strcmp compares the surnames alphabetically
}

// Function to print the employee list
void print_employees(Employee **employees, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s %s, Salary: %.2f\n",
               employees[i]->ID, employees[i]->name, employees[i]->surname, employees[i]->salary);
    }
}