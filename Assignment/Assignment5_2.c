// Queue Implementation Using Linked Lists
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory overflow. Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d\n", front->data);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty. No elements to peek.\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(9);
    enqueue(18);
    enqueue(27);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    peek();

    return 0;
}
