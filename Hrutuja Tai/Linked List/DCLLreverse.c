//Doubly circular linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;


node *Last(node *head){
    node *p=head;
    do{
        p = p->next;
    }
    while (p->next!=head);
    return(p);
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
    node *q;
    printf("\nEnter 1st element:\n");
    scanf("%d", &x);
    head -> data = x;
    head -> next = NULL;
    head -> prev = NULL;

    for(int i =1; i<n; i++){
        q = p;
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = q;
        p -> next = head;
    }
    p->next=head;
    head->prev=p;
    return (head);
}

void printDCLl(node *head){
    node *p;
    p=head;
    printf("\nThe Doubly Circular Linked List is:\n");
    do{
        printf("%d -> ", p->data);
        p = p->next;
    }
    while (p!=head);
}

node* reverse(node *head){
    node *current = head;
    do{
        node *p = current->prev;
        current->prev = current->next;
        current->next = p;
        current = current->prev;
    }
    while(current!= head);
    head = current->next;
}

void main(){
    node *head;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDCLl(head);
    printf("\nReversed Doubly Circular linked list is:\n");
    node *last =Last(head);
    head = reverse(head);
    printDCLl(head);
}