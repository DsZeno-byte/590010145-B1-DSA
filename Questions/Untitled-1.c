# include<stdio.h>
# include<stdlib.h>

struct node{
    int data;
    struct node *next;

};

int counting(struct node *head){
    int count=0;

    if(head==NULL)
        printf("The list is empty");
    struct node  * ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n The list contain %d nodes",&count);
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    
}