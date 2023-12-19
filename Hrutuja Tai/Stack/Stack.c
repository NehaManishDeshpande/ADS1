//create static stack

#include<stdio.h>
#define MAX 5

typedef struct stack{
    int data[MAX];
    int top;
}stack;

void initialize(stack *s){
    s->top = -1;
}

int Empty(stack *s){
    if (s->top == -1){
        return 1;
    }
    return 0;
}

int Full(stack *s){
    if (s->top == MAX-1){
        return 1;
    }
    return 0;
}

void push(int n, stack *s){
    s->top = s->top + 1;
    s->data[s->top] = n;
}

int pop(stack *s){
    int x = s->data[s->top];
    s->top = s->top - 1;
    return x;
}

void display(stack *s){
    for(int i= s->top; i>=0; i--){
        printf("%d ->", s->data[i]);
    }
}

void main(){
    stack s;
    initialize(&s);

    if(Full(&s)==0){
        push(10, &s);
    }else{printf("\nStack Full");}

    if(Full(&s)==0){
        push(20, &s);
    }else{printf("\nStack Full");}

    if(Full(&s)==0){
        push(30, &s);
    }else{printf("\nStack Full");}

    if(Full(&s)==0){
        push(40, &s);
    }else{printf("\nStack Full");}

    if(Full(&s)==0){
        push(50, &s);
    }else{printf("\nStack Full");}

    if(Full(&s)==0){
        push(60, &s);
    }else{printf("\nStack Full");}
    printf("\n");
    display(&s);
    int n=5;
    while(n!=3){
        int x=pop(&s);
        printf("\nPOPed Element: %d", x);
        n--;
    }
}