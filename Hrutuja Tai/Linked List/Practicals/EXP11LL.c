// AP to append one doubly linked list to a) the start of the Second list b)
// the end of the second list.

#include<stdio.h>
#include<malloc.h>
#include<math.h>

typedef struct DoublyLinkedList{
    int data;
    struct DoublyLinkedList *next, *prev;
}DLL;

DLL *create(){
    DLL *temp = (DLL*)malloc(sizeof(DLL*));
    return temp;
}

DLL *Insert(DLL *head, int n){
    DLL *p = (DLL*)malloc(sizeof(DLL*));
    int num;
    p = head;
    printf("\nEnter the size of the Linked List:");
    scanf("%d", &n);
    printf("\nEnter the data:");
    scanf(" %d", &num);
    p->data = num;
    p->next = NULL;
    p->prev = NULL;
    n-=1;
    while(n!=0){
        p->next = (DLL*)malloc(sizeof(DLL*));
        p = p->next;
        printf("\nEnter the data:");
        scanf("%d", &num);
        p->data = num;
        p->prev = p;
        p->next = NULL;
        n-=1;
    }
    return (head);
}


void Display(DLL *head){
    DLL *p = head;
    while (p!=NULL){
        printf("%d <-> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

void append(DLL *head1, DLL *head2){
    DLL *p1 = head1, *p2 = head2, *prev;
    while(p1!=NULL){
        printf("%d <-> ", p1->data);
        p1 = p1->next;
    }
    while ( p2 != NULL ){
        printf("%d <-> ", p2->data);
        p2 = p2->next;
    }
    printf("NULL");
}


void main(){
    DLL *head1, *head2;
    head1 = create();
    head2 = create();
    int n;
    printf("\nEnter first Doubly Linked List:\n");
    head1 = Insert(head1, n);
    Display(head1);
    printf("\n\nEnter second Doubly Linked List:\n");
    head2 = Insert(head2, n);
    Display(head2);

    //at start of second list
    printf("\n\nAppending the First Doubly Linked List at start of Second Doubly Linked List:\n");
    append(head1, head2);

    // at end of second list
    printf("\n\nAppending the First Doubly Linked List at end of Second Doubly Linked List:\n");
    append(head2, head1);
}