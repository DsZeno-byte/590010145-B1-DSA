#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to demonstrate the search process
void test_linear_search() {
    // Example array
    int arr[] = {12, 34, 7, 56, 89, 23, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test cases
    int targets[] = {56, 7, 100}; // Example target values
    int num_tests = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < num_tests; i++) {
        int target = targets[i];
        printf("Searching for %d...\n", target);

        int index = linear_search(arr, size, target);

        if (index != -1) {
            printf("Target %d found at index %d.\n", target, index);
        } else {
            printf("Target %d not found in the array.\n", target);
        }
        printf("\n");
    }
}

// Main function
int main() {
    test_linear_search();
    return 0;
}
