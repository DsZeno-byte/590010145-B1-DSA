#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    printf("\nStarting binary search...\n");
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid-point

        printf("Interval: [Left: %d, Right: %d, Mid: %d] -> Value at Mid: %d\n", 
                left, right, mid, arr[mid]);

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Discard the left half
        } else {
            right = mid - 1; // Discard the right half
        }
    }

    return -1; // Target not found
}

// Function to input an array
void input_array(int arr[], int size) {
    printf("Enter %d elements (sorted in ascending order):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function to test binary search
int main() {
    int size, target;

    // Prompt user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input the array
    input_array(arr, size);

    // Prompt user for the target value
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binary_search(arr, size, target);

    // Display the result
    if (result != -1) {
        printf("\nTarget %d found at index %d.\n", target, result);
    } else {
        printf("\nTarget %d not found in the array.\n", target);
    }

    return 0;
}
