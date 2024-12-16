#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;
void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}

void print()
{
    struct node *temp;
    temp = top;
    printf("The stack elements are:");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        /* code */
        printf("\n1. Push \n");
        printf("2. Print \n");
        printf("3. Exit \n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: /* constant-expression */
            /* code */
            printf("Enter the element to be push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            print();
            break;
        case 3:
            exit(1);

        default:
            printf("Invalid Choice \n ");
            break;
        }
    }
    return 0;
}