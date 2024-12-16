#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *p;
};
int count(struct node *head){
    int count=0;
    if (head==NULL)
        printf("The list is emplty");
    struct node *ptr=NULL;
    ptr=head;
    while (ptr!=NULL){
        count++;
        ptr=ptr->p;
    }
    printf("\n The List Contain %d Number Of NODES",count);
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 12;
    head->p = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 13;
    current->p = NULL;
    head->p = current;

    current = malloc(sizeof(struct node));
    current->data = 14;
    current->p = NULL;
    head->p->p = current;

    current = malloc(sizeof(struct node));
    current->data = 15;
    current->p = NULL;
    head->p->p->p = current;

    printf("%d", head->data);
    printf("->%d", head->p->data);
    printf("->%d", head->p->p->data);
    printf("->%d", current->data);

    count(head);
    return 0;
}