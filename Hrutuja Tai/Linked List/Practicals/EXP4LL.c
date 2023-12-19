// Write an Append() function that takes two lists, 'a' and 'b', appends 'b'
// onto the end of 'a', and then sets 'b' to NULL (since it is now trailing off
// the end of 'a')



#include<stdio.h>
#include<malloc.h>

typedef struct Polynomial{
    int data;
    struct Polynomial *next;
}poly;

poly *create(){
    poly *temp = (poly*)malloc(sizeof(poly*));
    return temp;
}

poly *Insert(poly *head, int n){
    poly *p = head;
    printf("\nEnter lenght of the Linked list:");
    scanf("%d", &n);
    int data;
    printf("\nEnter the Data:");
    scanf("%d", &data);
    p->data = data;
    p->next = NULL;
    n-=1;
    while(n!=0){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;
        printf("\nEnter the Data:");
        scanf("%d", &data);
        p->data = data;
        p->next = NULL;
        n-=1;    
    }
    return (head);
}

void Display(poly *head){
    poly *p = head;
    while(p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

poly *Append(poly *poly1 , poly *poly2){
    poly *p1 = poly1, *p2 = poly2, *head=NULL;
    head = p1;

    while(p1->next!=NULL){
        p1 = p1->next;
    }
    while(p2!= NULL){
        p1->next = (poly*)malloc(sizeof(poly*));
        p1 = p1->next;
        p1->data = p2->data;
        p1->next = p2;
        p2 = p2->next;
    }
    p1->next = NULL;
    return (head);
}


void main(){
    poly *head1, *head2;
    int n;
    printf("\nEnter the first List");
    head1 = create();
    head1 = Insert(head1, n);
    printf("\nEnter the second List");
    head2 = create();
    head2 = Insert(head2, n);
    printf("\nList1: ");
    Display(head1);
    printf("\nList 2: ");
    Display(head2);

    poly *append = Append(head1, head2);
    printf("\nConcatenation of Lists: ");
    Display(append);
}
