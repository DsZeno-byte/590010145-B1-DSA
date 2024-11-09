// Stack Implementation using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    struct Node *stackNode = (struct Node *)malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
int isEmpty(struct Node *root)
{
    return !root;
}
void push(struct Node **root, int data){
    struct Node *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
int pop(struct Node **root)
{
    if (isEmpty(*root))
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
int peek(struct Node *root)
{
    if (isEmpty(root))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return root->data;
}
int main()
{
    struct Node *root = NULL;
    push(&root, 110);
    push(&root, 120);
    push(&root, 130);
    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));
    return 0;
}
