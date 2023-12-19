//delete node from linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create();
node *insert (int n, node*);
void printCLl(node*);
node *CLLreverse(node *head);


void main(){
    node *head, *last;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printCLl(head);
    printf("\nReversed circular linked List is:\n");
    head= CLLreverse(head);
    printCLl(head);
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
    head -> next = head;

    node *p = head;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> next = head;
    }
    return (head);
}

void printCLl(node *head){
    node *p;
    p=head;
    printf("\nNodes of circular Linked List:\n");
    do{
        printf("%d -> ", p->data);
        p = p->next;
    }
    while (p!=head);
}

node *CLLreverse(node *head) {
    node *p=NULL;
    node *next=NULL;
    node *c=head;
    do{
        next = c->next; //save the next (head ka next)
        c->next = p; //point to last
        p=c;//one step ahead(p is head)
        c = next; //(last is next means 2nd node)
    }
    while(c!= head); //condition of a loop to call
       
    head = p;
    return (head);
}