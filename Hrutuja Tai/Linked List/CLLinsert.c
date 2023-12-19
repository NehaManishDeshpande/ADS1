//Circular Linked List

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create();
node *insert (int n, node*);
void printCLl(node*);
node *posInsertCLL(int n, node *head);
node *headInsert(int n, node*head);
node *endInsert(int n, node *head);
node *posInsert(int n, node *head);
node *Last(node*);

void main(){
    node *head, *last;
    int n;
    printf("enter the size of circular linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printCLl(head);
    last=Last(head);
    head = posInsertCLL(n, last);
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

node *Last(node* head){
    node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    return (p);
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


node *posInsertCLL(int n, node *last){
    printf("\nEnter the Position at which data is to be entered in the DLL:\n1. At Head\n2. At end\n3. At middle\n");
    scanf("\n%d", &n);
    node *head;
    switch(n){
        case 1: last=headInsert(n, last);
               break;
        case 2: last=endInsert(n, last);
               break;
        case 3: last=posInsert(n, last);
               break;
        default: printf("\nIrrelevant Option.");
               break;
    }
    head=last->next;
    return (head);
}

node *headInsert(int n, node *last){
    int num;
    printf("\nEnter the data  to be entered in the DLL:");
    scanf("%d", &num);
    node *p = (node*)malloc(sizeof(node*));
    p->data=num;
    p->next=last->next;
    last->next=p;
    // head=p;
    // node *q=head;
    // while(q->next!=head){
    //     q=q->next;
    // }
    // q->next=head;
    node *head=p;
    return (last);
}

node *endInsert(int n, node *last){
    int num;
    printf("\nEnter the data  to be entered in the DLL:");
    scanf("%d", &num);
    node *p = (node*)malloc(sizeof(node*));
    p->data=num;
    p->next=last->next;
    last->next=p;
    last=p;
    // node *head=last;
    return (last);
}

node *posInsert(int n, node *last){
    printf("\nEnter the Position at which data is to be entered in the DLL:\n");
    scanf("%d", &n);
    int num;
    printf("\nEnter the data  to be entered in the DLL:");
    scanf("%d", &num);
    node *q = (node*)malloc(sizeof(node*));
    q->data=num;
    q->next=NULL;
    node *p=last;
    p=p->next;
    for(int i=1; i<n-1; i++){
        p=p->next;
    }
    q->next = p->next;
    p->next = q;
    // node *head =last->next;
    return (last);
}