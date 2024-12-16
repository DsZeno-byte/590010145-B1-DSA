#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *p;
};
void counting(struct node *head){
    int count=0;
    if (head==NULL)
    printf("The List is Emplty");

    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        printf("%d ",ptr->data);
        ptr=ptr->p;
    }
    return (printf("\n The List contain %d nodes.",count)); 

}
int main(){
    struct node *head=malloc(sizeof(struct node ));
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

    counting(head);

}