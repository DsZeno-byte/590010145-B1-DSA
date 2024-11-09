//Queue Implementation Using Arrays
#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
int isFull()
{
    return (rear == SIZE - 1);
}
int isEmpty()
{
    return (front == -1 || front > rear);
}
void enqueue(int element)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue %d\n", element);
    }else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued %d\n", element);
    }
}
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        printf("Dequeued %d\n", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void peek()
{
    if (isEmpty()){
        printf("Queue is empty. No elements to peek.\n");
    }
    else{
        printf("Front element: %d\n", queue[front]);
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }else{
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    enqueue(12);
    enqueue(24);
    enqueue(36);
    enqueue(48);
    enqueue(60);
    display();

    dequeue();
    display();

    enqueue(72);
    display();

    peek();

    return 0;
}
