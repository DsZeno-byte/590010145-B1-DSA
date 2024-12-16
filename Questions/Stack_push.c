# include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;


int main(){
push(1);
push(2);
push(3);
push(4);
}
void push(int data){

    if(top==MAX-1){
        printf("Statck Overflow");
        return;
    }
    top+=1;     // top=top+1
    stack_arr[top]=data;
    printf(stack_arr);
}