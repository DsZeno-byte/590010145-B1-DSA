// Stack Implementation using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){

    if (top == MAX - 1)
    {

        printf("Stack Overflow!\n");
    }else{
        top++;
        stack[top] = value;
        printf("Inserted %d\n", value);
    }
}
// Removing the element 
int pop(){
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }else{
        int value = stack[top];
        top--;
        return value;
    }
}
int peek(){
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }else{
        return stack[top];
    }
}
// Printing the Stack 
void display(){
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    display();
    printf("Popped: %d\n", pop());
    display();
    printf("Top element: %d\n", peek());
    return 0;
}
