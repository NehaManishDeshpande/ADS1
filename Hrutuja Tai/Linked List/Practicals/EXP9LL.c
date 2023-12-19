// WAP to store at most 10 digit integer in a Doubly linked list and
// perform arithmetic operations on it.


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
    DLL *p = (DLL*)malloc(sizeof(DLL*));
    p = head;
    while (p!=NULL){
        printf("%d <-> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

int add(DLL *head){
    int sum=0;
    while(head!=NULL){
        sum = sum + head->data;
        head = head->next;
    }
    return sum;
}

int multiplication(DLL *head){
    int mul=1;
    while(head!=NULL){
        mul = mul * head->data;
        head = head->next;
    }
    return mul;
}

void main(){
    DLL *head;
    head = create();
    int n;
    printf("\nEnter the size of the Linked List:");
    scanf("%d", &n);
    head = Insert(head, n);
    Display(head);
    int res = add(head);
    printf("\nSum of all the data of Linked List is: %d",res);
    res = multiplication(head);
    printf("\nProduct of all the data of Linked List is: %d",res);
}