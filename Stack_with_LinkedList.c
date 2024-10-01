#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// new node Creation
struct Node *newNode(int data)
{
    struct Node *stackNode = malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Empty stack checking
int is_Empty(struct Node *root)
{
    return !root;
}

// Code for Push the element
void push(struct Node **root, int data)
{
    struct Node *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

// Pop the element
int pop(struct Node **root)
{
    if (is_Empty(*root))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Peek  the element
int peek(struct Node *root)
{
    if (is_Empty(root))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return root->data;
}

int main()
{
    struct Node *root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));

    return 0;
}
