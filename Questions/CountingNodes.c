#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *p;
};

int count(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("The List is Empty");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->p;
    }
    printf("\nList contain %d nodes",count);
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->p = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 20;
    current->p = NULL;
    head->p = current;

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->p = NULL;

    head->p->p = current;

    printf("%d", head->data);
    printf("\n%d", head->p->data);
    printf("\n%d", current->data);

    count(head);

    return 0;
}