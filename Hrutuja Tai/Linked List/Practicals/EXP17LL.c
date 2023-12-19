// Write a SortedInsert() function which given a list that is sorted in
// increasing order, and a single node, inserts the node into the correct
// sorted position in the list. While Push() allocates a new node to add to
// the list, SortedInsert() takes an existing node, and just rearranges
// pointers to insert it into the list.


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


node *SortedInsert(int n, node *head){
    node *p = head;
    node *temp = (node*)malloc(sizeof(node *));
    temp->data = n;
    temp->next= NULL;
    if(head == NULL || head->data > n){
        temp->next = head;
        head = temp;
    }

    while(p->next != NULL && p->next->data < n){
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;

    return head;
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
    printf("\nEnter the Element Linked List: ");
    scanf("%d", &n);
    head = SortedInsert(n, head);
    printLl(head);
}