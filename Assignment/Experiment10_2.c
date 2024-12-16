#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void build_max_heap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to perform heap sort
void heap_sort(int arr[], int n) {
    // Step 1: Build a max heap
    build_max_heap(arr, n);

    // Step 2: Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Testing the heap sort algorithm
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    printf("\nBuilding max heap:\n");
    build_max_heap(arr, n);
    print_array(arr, n);

    printf("\nPerforming heap sort:\n");
    heap_sort(arr, n);

    printf("\nSorted array:\n");
    print_array(arr, n);

    return 0;
}
