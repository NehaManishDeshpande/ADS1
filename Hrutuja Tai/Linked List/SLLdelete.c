//delete a node at a position

#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void main(){
    node *head = (node*)malloc(sizeof(node*));
    head = create(head);
    int n;
    head = insert( n, head); //here nis the size of linked list
    printLL(head);
    head = delete(n, head); //here n is the pos to delete
    printLL(head);
}

node *create(){
     node *head= (node*)malloc(sizeof(node*));
     return head;
}

node *insert(int n, node *head){
    //here n is the size of the linkes list
    printf("\nEnter the size of Linked List:");
    scanf("%d", &n);
    printf("\nEnter the 1st element:");
    int num;
    scanf("%d", &num);
    node *p= (node*)malloc(sizeof(node*));
    head->data=num;
    head->next=NULL;
    p=head;
    for(int i=1; i<n; i++){
        p->next=(node*)malloc(sizeof(node*));
        p=p->next;
        printf("\nEnter Data Elements: ");
        scanf("%d", &num);
        p->data=num;
        p->next=NULL;
    }
    return head;
}

void printLL(node *head){
    node *p= (node*)malloc(sizeof(node*));
    p=head;
    while(p!=NULL){
        printf("%d -> ", p->data);
        p=p->next;
    }
    printf("NULL");
}

node *delete(int pos, node *head){
    node *p, *q;
    printf("\nEnter the Position to be Deleted: ");
    scanf("%d", &pos);
    p= (node*)malloc(sizeof(node*));
    p=head;
    q=head;
    if(pos==1){
        head=head->next;
        // free(head);
    }
    else{
        for(int i=1; i<pos; i++){
        p = p->next;
        }
        for(int i=1; i<pos-1; i++){
        q = q->next;
        }
        q->next = p->next;
    }
    // free(p);
    return head;
}

void main(){
    node *head = (node*)malloc(sizeof(node*));
    head = create(head);
    int n;
    head = insert( n, head); //here nis the size of linked list
    printLL(head);
    head = delete(n, head); //here n is the pos to delete
    printLL(head);
}