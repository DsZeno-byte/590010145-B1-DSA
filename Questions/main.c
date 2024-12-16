#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *p;
};
int count(struct node *head){
    int count=0;
    if(head==NULL)
    printf("The List is empty");

    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->p;
    }
    printf("\nThere are %d NODES in the list ");
}

int main(){
    struct node* head=malloc(sizeof(struct node));
    head->data=45;
    head->p=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=55;
    current->p=NULL;
    head->p=current;

    current=malloc(sizeof(struct node));
    current->data=56;
    current->p=NULL;
    head->p->p=current;

    printf("%d",head->data);
    printf("->%d",head->p->data);
    printf("->%d",current->data);

    count(head);

    


}
