#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *create();
node *insert (int n, node*);
void printDLl(node*);

void main(){
    node *head;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDLl(head);
}

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}

node *insert(int n, node *head){
    int x;
    printf("\nEnter 1st element:\n");
    scanf("%d", &x);
    head -> data = x;
    head -> next = NULL;
    head -> prev =NULL;

    node *p = head;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = p;
        p -> next = NULL;
    }
    return (head);
}

void printDLl(node *head){
    node *p;
    node *a, *b;
    p=head;
    a=b=head;
    while (p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");

    printf("\nNext Address of each node:\n");
    while (a!=NULL){
        printf("%6p -> ", a->next);
        a = a->next;
    }
    printf("END");

    printf("\nPrevious Address of each node:\n");
    while (b!=NULL){
        printf("%6p -> ", b->prev);
        b = b->next;
    }
    printf("END");
}

