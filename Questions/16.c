#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *p;
};
void data(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("The list is empty.");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;

        printf("%d\n", ptr->data);
        ptr = ptr->p;
    }
    printf("Ther Are %d Nodes int the list", count);

    return 0;
};

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->p = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 55;
    current->p = NULL;
    head->p = current;

    current = malloc(sizeof(struct node));
    current->data = 65;
    current->p = NULL;
    head->p->p = current;

    current = malloc(sizeof(struct node));
    current->data = 75;
    current->p = NULL;
    head->p->p->p = current;
    data(head);
}