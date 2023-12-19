// WAP to store at most 10 digit integer in a Singly linked list and perform
// arithmetic operations on it.


#include<stdio.h>
#include<malloc.h>
#include<math.h>

typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}LL;

LL *create(){
    LL *temp = (LL*)malloc(sizeof(LL*));
    return temp;
}

LL *Insert(LL *head, int n){
    LL *p = (LL*)malloc(sizeof(LL*));
    int num;
    p = head;
    printf("\nEnter the data:");
    scanf(" %d", &num);
    p->data = num;
    p->next = NULL;
    n-=1;
    while(n!=0){
        p->next = (LL*)malloc(sizeof(LL*));
        p = p->next;
        printf("\nEnter the data:");
        scanf("%d", &num);
        p->data = num;
        p->next = NULL;
        n-=1;
    }
    return (head);
}

void Display(LL *head){
    LL *p = (LL*)malloc(sizeof(LL*));
    p = head;
    while (p!=NULL){
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

int add(LL *head){
    int sum=0;
    while(head!=NULL){
        sum = sum + head->data;
        head = head->next;
    }
    return sum;
}

int multiplication(LL *head){
    int mul=1;
    while(head!=NULL){
        mul = mul * head->data;
        head = head->next;
    }
    return mul;
}

void main(){
    LL *head;
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