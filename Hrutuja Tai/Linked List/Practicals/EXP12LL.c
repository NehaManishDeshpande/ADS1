// Implement Push and POP operations of STACK on Doubly linked lists


#include<stdio.h>
#include<malloc.h>

typedef struct stack{
    int data;
    struct stack *next, *prev;
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
    int n, num;
    // printf("\nEnter the number data to be pushed into stack\n");
    // scanf("%d", &n);
    // while(n--){
    //     printf("\nEnter the data to push into stack Pushing Data in stack:");
    //     scanf("%d", &num);
    //     push(num);
    // }
    push(2);
    push(4);
    push(6);
    push(8);
    push(10);
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

    push(10);
    printf("\nItems Remaining in Stack are:\n");
    display();
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    x=pop();
    printf("%d ->>POPPED\n\n",x);
    printf("\nItems Remaining in Stack are:\n");
    display();

}