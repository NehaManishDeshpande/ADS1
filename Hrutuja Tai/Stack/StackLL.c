//implement stack using linked list

#include<stdio.h>
#include<malloc.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack *top = NULL;

void push(int n){
    
    stack *temp = (stack*)malloc(sizeof(stack*));
    temp->data = n;

    if(top!=NULL){     //check if stack is empty or not
        temp->next = top;
    }
    else{
        temp->next = top;  
    }

    top = temp; //pin top to head
    printf("\nNODE INSERTED WITH DATA:%d\n", n);
}

int pop(){

    if(top == NULL){
        printf("\nStack UnderFlow");
    }
    else{
        stack *temp = top;
        int x = temp->data;
        top = temp->next;
        return (x);
    }
}

void display(){
    if(top == NULL){
        printf("\nStack UnderFlow");
    }
    else{
        stack *p = top;
        while (p != NULL){
            printf("%d ->", p->data);
            p = p->next;
        }
        printf(" StackEND\n\n");
    }
}

void main(){
    stack *s;
    printf("\nPushing Data in stack\n");
    push(10);
    push(40);
    push(50);
    printf("\n\n");
    printf("\nItems Remaining in Stack are:\n");
    display();
    printf("\nPoping Data out of stack\n");
    int x=pop();
    printf("%d ->>POPPED\n\n",x);
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    printf("\nItems Remaining in Stack are:\n");
    display();
}