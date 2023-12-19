//Queue with singly linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

void enqueue(int n){
    queue *q = (queue*)malloc(sizeof(queue*));
    q->data = n;
    
    if(head == NULL){
        head = q;
        tail = q;
        head->next = NULL;
        tail->next = NULL;
    }
    else{
        tail->next = q;
        tail = q;
        tail->next = NULL;
    }

    printf("\nQueue data Inserted %d", n);
}


void dequeue(){
    queue *q = (queue*)malloc(sizeof(queue*));
    q = head;
    if(head = NULL){
       printf("\nQueue is Empty");
    }else{
        printf("\nhead deleted : %d ", q->data);
        q = q->next;
        head = q;
        // free(head);
    }
}

void peek(){
    queue *q = (queue*)malloc(sizeof(queue*));

    if(head == NULL){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nHead is: %d ", head ->data);
    }
}


void display(){
    queue *p = head;
    printf("\nDisplaying Queue: ");
    while(p != NULL){
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("Null");
}

void main(){
    queue *q;
    printf("\nEnqueueing Data");
    enqueue(50);
    enqueue(100);
    enqueue(150);
    enqueue(200);
    enqueue(250);
    enqueue(300);
    enqueue(350);
    enqueue(400);
    enqueue(450);
    enqueue(500);
    display();
    peek();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();
}