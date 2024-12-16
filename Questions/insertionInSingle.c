#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *p;
};
void add_at_last(struct node *head,int a){              // Where a=67 when we are calling the function.
struct node * ptr,*temp;
ptr=head;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->p=NULL;

while(ptr->p!=NULL){
    ptr=ptr->p;

}
ptr->p=temp;
}
void print_data(struct node *head){
    if (head==NULL)
    printf("The list is empty.");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->p;
    }
}


int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->p=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=55;
    current->p=NULL;
    head->p=current;

    current=malloc(sizeof(struct node));
    current->data=65;
    current->p=NULL;
    head->p->p=current;    
    add_at_last(head,67);
    print_data(head);
}