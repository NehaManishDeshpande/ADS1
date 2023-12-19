//circular queue using linked list

#include<stdio.h>
#include<malloc.h>


typedef struct CircularQueue{
    int data;
    struct CircularQueue *next;
}cQueue;

cQueue *head = NULL;
cQueue *tail = NULL;

void enqueue(int data){
    cQueue *temp = (cQueue*)malloc(sizeof(cQueue*));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL && tail == NULL){
        head = tail = temp;
        tail->next = head;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }

    printf("\nNode Inserted %d", data);
}

void dequeue(){
    if(head == NULL && tail == NULL){
        printf("\nQueue is Empty");
    }
    else if(head == tail){
        printf("\nNode Deleted %d", head->data);
        head = tail = NULL;
    }
    else{
        printf("\nNode Deleted %d", head->data);
        head = head->next;
        tail->next = head;
    }
}


void peek(){
    printf("\nHead is %d", head->data);
}



void display(){
    cQueue *temp = head;
    printf("\nPrinting Circular Queue: ");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
}


void main(){
    enqueue(50);
    enqueue(150);
    enqueue(250);
    enqueue(350);
    enqueue(450);
    enqueue(550);
    enqueue(650);

    display();

    peek();

    dequeue();
    peek();
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    peek();
    display();
}