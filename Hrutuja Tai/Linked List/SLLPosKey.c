//add node at specific position  after a specific key in the existing linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create();
node *insert (int n, node*);
void printLl(node*);
node *posKeyInsert(int n, node*);

void main(){
    node *head;
    int n;
    printf("enter the size of linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printLl(head);
    printf("\nenter  the Key:\n");
    int num;
    scanf("%d",&num);
    head = posKeyInsert (num, head);
    printLl(head);
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

    node *p = head;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> next = NULL;
    }
    return (head);
}

void printLl(node *head){
    node *p;
    node *a;
    p=head;
    a=head;
    while (p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

//add the node at specific position int the linked list  where n is the position
node *posKeyInsert(int key, node* head){
    node *p=(node*)malloc(sizeof(node*));
    int num;
    printf("\nEnter the data to insert after key %d:\n", key);
    scanf("%d", &num);
    p -> data = num;
    p -> next = NULL;
    node *q;
    
    if(key == -1){
        p->next=head;
        head=p;
    }

    else{
        q = head;
        while(q->data!=key && q!=NULL){
            q=q->next;
        }
        if(q!=NULL){
            p->next=q->next;
            q->next=p;
        }
    }
    return head;
}