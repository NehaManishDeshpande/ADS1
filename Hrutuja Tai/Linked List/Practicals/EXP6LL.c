// Consider a CopyList() function that takes a list and returns a complete
// copy of that list. One pointer can iterate over the original list in the usual
// way. Two other pointers can keep track of the new list: one head pointer,
// and one tail pointer which always points to the last node in the new list.



#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;


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

node *CopyList(node *headNode){
    node *p = headNode;
    node *head, *tail, *temp;
    head = (node*)malloc(sizeof(node*));
    head->data = p->data;
    head->next = p->next;
    p = p->next;
    temp = head;
    while(p!=NULL){
        temp->next = (node*)malloc(sizeof(node*));
        temp = temp->next;
        temp->data = p->data;
        temp->next = p->next;
        tail = temp;
        p = p->next;
    }
    temp->next = NULL;
    return (head);
}


void main(){
    node *head;
    int n;
    printf("\nEnter the size of linked List: ");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printf("\nOriginal Linked List:\n");
    printLl(head);
    printf("\nCopy of the Linked List:\n");
    head = CopyList (head);
    printLl(head);
}