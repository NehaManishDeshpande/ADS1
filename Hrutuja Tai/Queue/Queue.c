//Queue using array 


#include<stdio.h>
#define MAX 5

typedef struct Queue{
    int data[MAX];
    int head, tail;
}queue;

void initialize(queue *q){
    q->head = -1;
    q->tail = -1;
}


void enqueue(int data, queue *q){
    if(q->tail == (MAX - 1)){
        printf("\nQueue is FULL !!");
    }
    else{
        if(q->head == -1){
             q->head = 0; 
        }
        (q->tail)++;
        q->data[q->tail] = data;
    }
}

void  dequeue(queue *q){
    int x = q->data[q->head];
    q->head = q->head + 1;
    printf("\nDeleted: %d", x);
    if(q->head > q->tail){
        q->head = q->tail = -1;
    }
}

void peek(queue *q){
    int x = q->data[q->head];
    printf("\nHead is : %d", x);
}

int isEmpty(queue *q){
    if(q->head == -1){
        return 1;
    }
    return 0;
}

int isFull(queue *q){
    if(q->tail == (MAX-1)){
        return 1;
    }
    return 0;
}

void display(queue *q){
    queue* p = q;
    if(p->tail == -1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nDisplaying Queue: ");
        int head = 0;
        while(head != p->tail + 1){
            printf("%d-> ", p->data[head]);
            head ++;
        }
        printf("NULL");
    }
}

void main(){
    queue q;
    initialize(&q);

    if(isFull(&q) == 0){
        enqueue(10, &q);
        display(&q);
    }else{printf("\nQueue is Full !!");}

    if(isFull(&q) == 0){
        enqueue(20, &q);
        enqueue(30, &q);
        enqueue(40, &q);
        display(&q);
    }else{printf("\nQueue id FULL!!");}

    if(isFull(&q) == 0){
        enqueue(50, &q);
        display(&q);
    }else{printf("\nQueue is Full !!");}

    if(isFull(&q) == 0){
        enqueue(60, &q);
        display(&q);
    }else{printf("\nQueue is Full !!");}

    peek(&q);

    if(isEmpty(&q) == 0){
        dequeue(&q);
        display(&q);
    }else{printf("\nQueue is Empty !!");}

    if(isEmpty(&q) == 0){
        dequeue(&q);
        display(&q);
    }else{printf("\nQueue is Empty !!");}

    if(isEmpty(&q) == 0){
        dequeue(&q);
        display(&q);
    }else{printf("\nQueue is Empty !!");}

    if(isEmpty(&q) == 0){
        dequeue(&q);
        display(&q);
    }else{printf("\nQueue is Empty !!");}

    if(isEmpty(&q) == 0){
        dequeue(&q);
        display(&q);
    }else{printf("\nQueue is Empty !!");}
}