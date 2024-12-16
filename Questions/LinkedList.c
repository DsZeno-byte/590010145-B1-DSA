#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * p;
};
void insert_at_End(struct node *head,int num){
    struct node *ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->p=NULL;

    while(ptr->p!=NULL){
        ptr=ptr->p;
    }
    ptr->p=temp;
}
void count(struct node *head){
    int count=0;
    if(head==NULL)
    printf("List is empty");
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        printf("%d ",ptr->data);
        ptr=ptr->p;
    }
    printf("\n This list contain %d Node",count);
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->p=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=55;
    current->p=NULL;
    head->p=current;

    current=malloc(sizeof(struct node));
    current->data=65;
    current->p=NULL;
    head->p->p=current;
    insert_at_End(head,67);
    count(head);
}