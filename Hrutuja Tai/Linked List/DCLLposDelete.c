//deleted from doubly circular linked list

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
node *Last(node*);
node *posDeleteDCll(node*);

void main(){
    node *head, *last;
    int n;
    printf("enter the size of doubly  circular linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDCLl(head);
    last=Last(head);
    head = posDeleteDCll(last);
    // head=last->next;
    printDCLl(head);
}

node *Last(node *head){
    node *p=head;
    do{
        p=p->next;
    }
    while(p->next!=head);
    // printf("\n\nLast node is:%d\n\n", p->data);
    return (p);
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
    head -> next = head;
    head -> prev =p;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = p;
        p -> next = head;
    }
    p->next=head;
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
}


node *posDeleteDCll(node* last){
    int n;
    node *p, *q;
    printf("\nEnter the position of the data to be deleted from DCLL:");
    scanf("%d", &n);
    p=q=last->next; //initialize p and q at head

    if(n==1){
        q=q->next;
        q->prev=last;
        last->next=q;
        return (q);
    }
    else{
        for(int i=1; i<n; i++){
        p = p->next;
        }
        for(int i=1; i<n-1; i++){
        q = q->next;
        }
        q->next = p->next;
        p->next->prev=q;
        return (last->next);
    }
}