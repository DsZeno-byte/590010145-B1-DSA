#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *array;
    int n, i;
    // Ask user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Dynamically allocate memory for n integers
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }
    // Get input from the user to fill the array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    // Display the array elements
    printf("You entered:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    // Free the allocated memory
    free(array);
    printf("Memory has been freed.\n");
    return 0;
}
