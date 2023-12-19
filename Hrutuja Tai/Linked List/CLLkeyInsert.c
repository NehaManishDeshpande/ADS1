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
    last = posInsertCLL(n, last);
    head=last->next;
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
    printf("\nEnter the key after which data is to be entered in the CLL:");
    scanf("%d", &n);
    int num;
    printf("\nEnter the data  to be entered in the DLL:");
    scanf("%d", &num);
    node *q = (node*)malloc(sizeof(node*));
    q->data=num;
    q->next=NULL;

    if(n == -1){
        q->next=last->next;
        last->next=q;
        node *head=q;
        return (last);
    }
    else if(last->data == n){
        q->next=last->next;
        last->next=q;
        last = q;
        return (last);
    }
    else{
        node *p=last->next;
        do{
            p=p->next;
        }
        while(p->data!=n && p!=last->next);
        q->next = p->next;
        p->next = q;
        return (last);
    }
    
}