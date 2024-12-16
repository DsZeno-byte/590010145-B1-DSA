#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *p;
};
void print_data(struct node *head){
    if(head==NULL)
        printf("The list is empty");
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d clear",ptr->data);
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

    // printf("%d",head->data);
    // printf("->%d",head->p->data);
    // printf("->%d\n\n\n\n\n\n\n",current->data);
    
    print_data(head);
}