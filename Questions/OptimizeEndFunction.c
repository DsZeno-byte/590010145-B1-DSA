#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * add_atEnd(struct node *ptr,int num){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    ptr->next=temp;
    return temp;

}

int main(){
    struct node * head=malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    struct node *ptr=head;
    ptr=add_atEnd(ptr,55);
    ptr=add_atEnd(ptr,65);
    ptr=add_atEnd(ptr,10);
    ptr=add_atEnd(ptr,20);
    ptr=add_atEnd(ptr,30);
    ptr=add_atEnd(ptr,40);
    ptr=add_atEnd(ptr,50);

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }return 0;
}
