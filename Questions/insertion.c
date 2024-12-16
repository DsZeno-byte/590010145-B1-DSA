#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void add_atEnd(struct node *head,int num){
    struct node *ptr,*temp;
    ptr=head;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}


void count(struct node * head){
    int count=0;
    if(head==NULL)
    printf("The List is Empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\nList Contain %d Nodes ",count);
}
int main(){
    struct node * head=malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    struct node *p=malloc(sizeof(struct node));
    p->data=55;
    p->next=NULL;
    head->next=p;
    add_atEnd(head,67);
    count(head);
}