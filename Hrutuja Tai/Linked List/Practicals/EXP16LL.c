// Write a RemoveDuplicates() function which takes a list sorted in
// increasing order and deletes any duplicate nodes from the list. Ideally,
// the list should only be traversed once.


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


void removeDuplicate(node *head){
    if(head == NULL || head->next == NULL) {
        return;
    }

    node *p = head;
    while (p != NULL && p->next != NULL)
    {
        if(p->data == p->next->data){
            node *temp = p->next;
            p->next = p->next->next;
        } else {
            p = p->next; 
        }
    }

    printLl(head); 
}


void main(){
    node *head;
    int n;
    printf("enter the size of linked List in Sorted Manner:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printf("\nLinked List: ");
    printLl(head);
    printf("\nRemoved Duplicate Linked List: ");
    removeDuplicate(head);
}