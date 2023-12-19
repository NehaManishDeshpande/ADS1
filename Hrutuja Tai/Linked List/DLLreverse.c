#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *create();
node *insert (int n, node*);
void printDLl(node*);
node *DLLreverse(node *head);

void main(){
    node *head;
    int n;
    printf("enter the size of doubly linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDLl(head);
    printf("\nReversed linked List is:\n");
    head = DLLreverse(head);
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
}

node *DLLreverse(node *head){
    node *p=NULL;
    node *next=NULL;
    node *prev=NULL;
    while (head != NULL){
        next = head->next; //save next
        prev = head->prev; //save the previous
        head->prev = head->next;//update previous
        head->next = p;  //update next
        //one position ahead
        p = head;
        head = next;
    }
    head = p;
    return head;
}
