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
node *Last(node* head);
node *posDeleted(int n, node *head);
node *headDelete( node*head);
node *endDelete(node *head);
node *posDelete(int n, node *head);

void main(){
    node *head, *last;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printCLl(head);
    last=Last( head);
    last= posDeleted(n, last);
    head=last->next;
    printCLl(head);
}

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}
node *Last(node* head){
    node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    return (p);
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

node *posDeleted(int n, node *last){
    printf("\nEnter the Position from which data is to be deleted from CLL :\n1. At Head\n2. At end\n3. At middle\n");
    scanf("\n%d", &n);
    node *head;
    switch(n){
        case 1: last=headDelete( last);
               break;
        case 2: last=endDelete( last);
               break;
        case 3: last=posDelete(n, last);
               break;
        default: printf("\nIrrelevant Option.");
               break;
    }

    return (head);
}

node *headDelete(node *last){
    node *p = last->next;
    p = p->next;
    last->next=p;
    return (last);
}

node *endDelete( node *last){
    node *p=last->next;
    while(p->next!=last){
        p=p->next;
    }
    p->next=last->next;
    last=p;
    return (last);
}

node *posDelete(int n, node *last){
    printf("\nEnter the Position from which data is to be deleted from CLL:\n");
    scanf("%d", &n);
    node *p=last->next;
    for(int i=1; i<n-1; i++){
        p=p->next;
    }
    p->next=p->next->next;
    return (last);
}