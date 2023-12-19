//insert in given doubly linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *create();
node *insert (int n, node*);
void printDLl(node*);
node *keyInsertDll(int n, node* head);

void main(){
    node *head;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDLl(head);
    head = keyInsertDll(n, head);
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
    printf("\nEnter 1st element:");
    scanf("%d", &x);
    head -> data = x;
    head -> next = NULL;
    head -> prev =NULL;

    node *p = head;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("\nEnter data:");
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
    printf("\nThe final Doubly Linked list is:\n");
    while (p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

node *keyInsertDll(int n, node* head){
    printf("\nEnter the key after which data is to be entered in the DLL:");
    scanf("%d", &n);
    int num;
    printf("\nEnter the data  to be entered in the DLL:");
    scanf("%d", &num);
    node *q=(node*)malloc(sizeof(node*));
    q->data=num;
    q->prev = q->next =NULL;

    if(n==-1){                //insert at head
        q->next=head;
        head = q;
    }

    else{                 //insrt at other position
        node *p=head;
        while(p->data!=n && p!=NULL){
            p=p->next;
        }
        if(p!=NULL){
            q->next = p->next;
            q->prev = p;
            p->next = q;
        }
    }
    return head;
}