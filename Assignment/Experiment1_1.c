#include <stdio.h>

// Function to find the largest element in the array
int find_largest(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest element in the array
int find_smallest(int arr[], int n) {
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

// Function to sort the array in ascending order
void sort_array(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the sum of the array elements
int calculate_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find largest and smallest elements
    int largest = find_largest(arr, n);
    int smallest = find_smallest(arr, n);

    // Sort the array
    sort_array(arr, n);

    // Calculate sum and average
    int sum = calculate_sum(arr, n);
    float average = (float)sum / n;

    // Output results
    printf("\nResults:\n");
    printf("Original Array: ");
    print_array(arr, n);
    printf("Largest Element: %d\n", largest);
    printf("Smallest Element: %d\n", smallest);
    printf("Sorted Array: ");
    print_array(arr, n);
    printf("Sum of Elements: %d\n", sum);
    printf("Average of Elements: %.2f\n", average);

    return 0;
}
