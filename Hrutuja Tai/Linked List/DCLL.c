//Doubly circular linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *create();
node *insert (int n, node*);
void printDCLl(node*);

void main(){
    node *head;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDCLl(head);
}

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}

node *insert(int n, node *head){
    int x;
    node *p = head;
    printf("\nEnter 1st element:\n");
    scanf("%d", &x);
    head -> data = x;
    head -> next = NULL;
    head -> prev = NULL;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = head;
        p -> next = head;
    }
    p->next=head;
    head->prev=p;
    return (head);
}

void printDCLl(node *head){
    node *p;
    node *a, *b;
    p=head;
    a=b=head;
    do{
        printf("%d -> ", p->data);
        p = p->next;
    }
    while (p!=head);

    printf("\nNext Address of each node:\n");
    do{
       printf("%6p -> ", a->next);
        a = a->next; 
    }
    while (a!=head);

    printf("\nPrevious Address of each node:\n");
    do{
        printf("%6p -> ", b->prev);
        b = b->next;
    }
    while (b!=head);
}