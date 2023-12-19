//addend node to in the existing linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create();
node *insert (int n, node*);
void printLl(node*);
node *endInsert(int n, node*);

void main(){
    node *head;
    int n;
    printf("enter the size of linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printLl(head);
    printf("\nenter data to be entered at end:\n");
    int num;
    scanf("%d",&num);
    head = endInsert (num, head);
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

//add at end position so  the time complexity is  O(1) as we will 
//only point the previous node to the newly added node 
node *endInsert(int n, node* head){
    node *p=(node*)malloc(sizeof(node*));
    p -> data = n;
    p -> next = NULL;
    node *q;
    q = head;
    while (q -> next!=NULL){
        q = q -> next;
    }
    q -> next = p;

    return(head);
}