//key delete dcll

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
node *keyDeleteDCll(node*);

void main(){
    node *head, *last;
    int n;
    printf("enter the size of doubly  circular linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDCLl(head);
    // last=Last(head);
    head = keyDeleteDCll(head);
    printDCLl(head);
}

node *Last(node *head){
    node *p=head;
    do{
        p=p->next;
    }
    while(p->next!=head);
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
    head -> next = NULL;
    head -> prev = NULL;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = head;
        p -> next = head;
    }
    p->next=head;
    head->prev=p;
    return (head);
}

void printDCLl(node *head){
    node *p;
    node *a, *b;
    p=head;
    a=b=head;
    printf("\nThe final Doubly Circular Linked List is:\n");
    do{
        printf("%d -> ", p->data);
        p = p->next;
    }
    while (p!=head);
}

node *keyDeleteDCll(node *head){
    int n;
    printf("\nEnter the key of node to be deleted from DCLL:\n");
    scanf("%d", &n);
    node *p, *q;
    p=head; //p pointing ot head
    q=head->prev; //q pointing to last

    if(head->data == n){
        head=head->next;
        head->prev=q;
        q->next = head;
        return (head);
    }
    else if(q->next->data == n){
        q->next = head;
        head->prev = q;
        return(head);
    }
    else {
        q = head;  //q pointing to head
        node *temp=q->next; //temp pointing to q->next node
        node *p=q->prev; //p pointing to q ka previous node
        while(q->data!=n && q!=head->prev){
            q=q->next;
            temp=temp->next;
            p=p->next;
        }

        p->next = temp;
        temp->prev = p;
        return(head); 
          
    }
}