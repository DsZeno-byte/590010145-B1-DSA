#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int sum = 0;
    float average;

    // 1. Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 2. Allocate memory dynamically using malloc
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Input n elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 4. Calculate the sum and average of the elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    average = (float)sum / n;

    // Display the results
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);

    // 5. Release the memory using free
    free(arr);

    return 0;
}
