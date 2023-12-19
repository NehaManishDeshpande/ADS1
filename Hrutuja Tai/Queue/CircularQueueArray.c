//circular Queue using array

#include<stdio.h>
#define MAX 5

typedef struct CircularQueueArray{
    int data[MAX];
    int head, tail;
}queue;

void initialize(queue *q){
    q->head = -1;
    q->tail = -1;
}


void enqueue(queue *q, int data){
    if(q->head == 0 && q->tail == (MAX - 1)){ //if queue is full
        printf("\nQueue is Full!!");
    }
    else if(q->head == -1){           //insert element at start
        q->head = 0;
        q->tail = 0;
        q->data[q->tail] = data;
    }
    else if(q->tail == (MAX-1) && q->head != 0){    //to keep the circular queue and add at new data at head
        q->tail = 0;
        q->data[q->tail] = data;
    }
    else{                          //for the remaining data
        (q->tail)++;
        q->data[q->tail] = data;
    }
}


void  dequeue(queue *q){
   
    if(q->head == q->tail == -1){
        printf("\nQueue is Empty!");
    }

    int x = q->data[q->head];

    if(q->head == q->tail ){
        q->head = -1;
        q->tail = -1;
    }
    else if(q->head == (MAX-1)){
        q->head = 0;
    }
    else{
        q->head = q->head + 1;
    }
    printf("\nDeleted: %d", x);
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
    if(q->tail == -1){
        printf("\nQueue is EMPTY !!");
    }
    else if(q->tail >= q->head){
        printf("\nCircular Queue:");
        int x;
        for(x = q->head; x <= q->tail; x++){
            printf("%d -> ", q->data[x]);
        }
    }
    else{        //if head is greater than tail
        printf("\nCircular Queue:");
        int x;
        for(x = q->head; x < MAX; x++){
            printf("%d -> ", q->data[x]);
        }   
        for(x = 0; x <= q->tail; x++){
            printf("%d -> ", q->data[x]);
        } 
    }
}


void main(){
    queue q;
    initialize(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);
    peek(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 60);
    display(&q);

    dequeue(&q);

    enqueue(&q, 70);
    display(&q);

    dequeue(&q);

    enqueue(&q, 80);
    display(&q);

    enqueue(&q, 90);
    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);
}