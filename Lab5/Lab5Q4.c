int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *(start++); /* add value to total and immediately point to the next location*/
    }
    return total;
}

//for testing purposes:
int main() {
    // Test case 1: A simple array of integers
    int arr1[] = {1, 2, 3, 4, 5};
    int *start1 = arr1; 
    int *end1 = arr1 + 5;  // end points to one past the last element
    int result1 = sum(start1, end1);
    printf("Test 1 - Sum of arr1: %d (Expected: 15)\n", result1);

    // Test case 2: An empty array
    int arr2[] = {};
    int *start2 = arr2;
    int *end2 = arr2;  // start and end are the same, so sum should be 0
    int result2 = sum(start2, end2);
    printf("Test 2 - Sum of arr2 (empty array): %d (Expected: 0)\n", result2);

    // Test case 3: Array with a single element
    int arr3[] = {10};
    int *start3 = arr3;
    int *end3 = arr3 + 1;  // only one element to sum
    int result3 = sum(start3, end3);
    printf("Test 3 - Sum of arr3 (single element): %d (Expected: 10)\n", result3);

    // Test case 4: Array with negative and positive integers
    int arr4[] = {-1, -2, 3, 4};
    int *start4 = arr4;
    int *end4 = arr4 + 4;
    int result4 = sum(start4, end4);
    printf("Test 4 - Sum of arr4: %d (Expected: 4)\n", result4);

    return 0;
}