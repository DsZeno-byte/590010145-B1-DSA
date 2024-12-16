#include <stdio.h>

void inOrderTraversal(int arr[], int index, int size)
{
    if (index >= size)
        return;

    inOrderTraversal(arr, 2 * index + 1, size);

    printf("%d ", arr[index]);

    inOrderTraversal(arr, 2 * index + 2, size);
}

int main()
{

    int tree[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(tree) / sizeof(tree[0]);

    printf("In-order Binary Tree: ");
    inOrderTraversal(tree, 0, size);

    return 0;
}
