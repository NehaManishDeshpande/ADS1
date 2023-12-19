// WAP to merge two sorted Doubly linked lists and display ther result


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


DLL *merge(DLL *head1, DLL *head2){
    DLL *p = head1, *q = head2, *result=NULL, *temp;
    if(p!=NULL && q==NULL){
        result = p;
        temp = result;
    }
    else if(p==NULL && q!=NULL){
        result = q;
        temp = q;
    }
    else{
        while(p!=NULL && q!=NULL){
            if(result == NULL){
                result = (DLL*)malloc(sizeof(DLL*));
                result->prev = NULL;
                temp = result;
            }else{
                temp->next = (DLL*)malloc(sizeof(DLL*));
                temp = temp->next;
                temp->prev = temp;
            }
            
            if(p->data < q->data){
                temp->data = p->data;
                p = p->next;
            }else if(p->data > q->data){
                temp->data = q->data;
                q = q->next;
            }else if(p->data == q->data){
                temp->data = p->data;
                temp->next = (DLL*)malloc(sizeof(DLL*));
                temp = temp->next;
                temp->prev = temp;
                temp->data = q->data;
                p = p->next;
                q = q->next;
            }
        }

        while(p!=NULL){
            temp->next = (DLL*)malloc(sizeof(DLL*));
            temp = temp->next;
            temp->prev = temp;

            temp->data = p->data;
            p = p->next;
        }

        while(q!=NULL){
            temp->next = (DLL*)malloc(sizeof(DLL*));
            temp = temp->next;
            temp->prev = temp;

            temp->data = q->data;
            q = q->next;
        }
    }
    temp->next = NULL;
    return (result);
}

void main(){
    DLL *head1, *head2;
    head1 = create();
    head2 = create();
    int n;
    printf("\nEnter first sorted Doubly Linked List:\n");
    head1 = Insert(head1, n);
    Display(head1);
    printf("\nEnter second sorted Doubly Linked List:\n");
    head2 = Insert(head2, n);
    Display(head2);

    DLL *Merge = merge(head1, head2);
    printf("\nMerged Doubly Linked List:\n");
    Display(Merge);
}