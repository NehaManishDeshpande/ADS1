//evaluation
//1. s, &s    //pointer address passed so changed globally
//2. *s, s       //pointer to pointer no change but segmentation fault
//3. *s, &s    //incomaptible
//4. s, s     //just the value passed so not changed globally

//create static stack

#include<stdio.h>
#define MAX 5

// typedef struct stack{
//     int data[MAX];
//     int top;
// }stack;


// void initialize(stack *s){
//     s->top = -1;
// }

void main(){
    // stack s;
    // s.top = 2;
    // initialize(&s);
    int x=0;
    printf("\n%d", x+=1); //++x == x+=1
    
}