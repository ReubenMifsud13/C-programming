#include <stdio.h>

#define TOTAL_ITEMS 5

char get_character();
int get_int();

int main(void) {
    char userChoice;
    int items = 0, code, qty;
    double total = 0;

    int codes[TOTAL_ITEMS] = {1111, 2222, 1313, 2424, 1536};
    char names[TOTAL_ITEMS][20] = {"Drone", "Deodorant", "Basketball", "Hat", "Guitar"};
    double prices[TOTAL_ITEMS] = {52.6, 15.99, 20.5, 5, 285.57};
    
    int shopping_list[5] = {0, 0, 0, 0, 0}; // Store the amount of each item bought

    do {
        printf("\n1. Add Items to shopping cart\n2. Show current total\n");
        printf("3. Check out\n4. Cancel session\nq. Quit\n");

        userChoice = get_character(); // Get user input

        switch (userChoice) {
            case '1':
                printf("Code   Name         Price\n");
                for (int i = 0; i < TOTAL_ITEMS; i++) {
                    printf("%d   %-10s   $%.2f\n", codes[i], names[i], prices[i]);
                }
                printf("Please enter the code of the item you wish to add to your shopping cart: ");
                code = get_int();

                // Find item by code
                int index = -1;
                for (int i = 0; i < TOTAL_ITEMS; i++) {
                    if (codes[i] == code) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Item not found!\n");
                } else {
                    printf("Enter quantity for %s: ", names[index]);
                    qty = get_int();
                    if (qty > 0) { // Valid quantity - update shopping cart
                        shopping_list[index] += qty;
                        total += prices[index] * qty;
                        items++;
                        printf("%d x %s added to cart.\n", qty, names[index]);
                    } else {
                        printf("Invalid quantity!\n");
                    }
                }
                break;
            
            case '2':
                printf("Current total = $%.2f\n", total);
                break;

            case '3':
                printf("Are you sure you want to check out? Enter 3 again to confirm: ");
                if (get_character() == '3') {
                    if (items == 0) {
                        printf("Your cart is empty.\n");
                    } else {
                        // Display itemized bill
                        printf("\nItemized bill:\n");
                        printf("%-14s%-14s%-10s\n","Item","Quantity","Price");
                        for (int i = 0; i < TOTAL_ITEMS; i++) {
                            if (shopping_list[i] > 0) {
                                printf("%-14s%-14d$%-10.2f\n", names[i], shopping_list[i], prices[i] * shopping_list[i]);
                            }
                        }
                        printf("\nTotal amount: $%.2f\n", total);
                        
                        // Reset session after checkout
                        total = 0;
                        items = 0;
                        for (int i = 0; i < TOTAL_ITEMS; i++) shopping_list[i] = 0;
                        printf("Thank you for shopping! Starting a new session.\n");
                    }
                } else {
                    printf("Checkout canceled.\n");
                }
                break;

            case '4':
                printf("Are you sure you want to cancel? Enter 4 again to confirm: ");
                if (get_character() == '4') {
                    // Clear previous data:
                    total = 0;
                    items = 0;
                    for (int i = 0; i < TOTAL_ITEMS; i++) shopping_list[i] = 0;
                    printf("Session canceled. Starting a new session.\n");
                } else {
                    printf("Cancel session aborted.\n");
                }
                break;

            case 'q': {
                printf("Are you sure you want to quit? Enter 'q' again to confirm: ");
                if (get_character() == 'q') {
                    printf("Exiting program. Goodbye!\n");
                    return 0;
                }
                break;
            }

            default:
                printf("Incorrect input - must enter 1 2 3 4 or q\n");
                break;
        }
    } while (1);

    return 0;
}

char get_character() {
    char input;
    scanf(" %c", &input); // The space before %c skips any leftover newline or whitespace
    while (getchar() != '\n'); // Clear any remaining characters in the input buffer
    return input;
}

int get_int(void){ //Validation of integer input

    int input;
    char ch;



    while (scanf("%d", &input) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input - Avoid infinite loops
            printf(" is not an integer.\nPlease enter an\ninteger value, such as 25, -178, or 3: ");
    }

    return input;

}