//Given a list, split it into two sublists — one for the front half, and one
// for the back half. If the number of elements is odd, the extra element
// should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11}
// should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for all
// the cases is harder than it looks. You should check your solution against
// a few cases (length = 2, length = 3, length=4) to make sure that the list
// gets split correctly near the short­list boundary conditions. If it works
// right for length=4, it probably works right for length=1000. You will
// probably need special case code to deal with the (length <2) cases.



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

void FrontBackSplit(LL *head, int size){
    int count=size;
    LL *p = head;
    int n, n_copy;

    if(count%2 == 0){
        n = (count/2);
    }else{
        n = (count/2)+1;
    }
    
    printf("\nn value %d",n);
    n_copy = n;
    printf("\n");

    // while(p!=NULL){
        printf("{");
        while(n!=0){
            printf(" %d", p->data);
            p = p->next;
            n-=1;
            if(n!=0){
            printf(",");
            }
        }
        printf("}");

        printf("\tand\t");
        n = count - n_copy;

        printf("{");
        while(n!=0){
            printf(" %d", p->data);
            if(p == NULL){
                break;
            }
            p = p->next;
            n-=1;
            if(n!=0){
            printf(",");
            }
        }
        printf("}");

    // }
}

void main(){
    LL *head;
    head = create();
    int n;
    printf("\nEnter the size of the Linked List:");
    scanf("%d", &n);
    head = Insert(head, n);
    Display(head);
    FrontBackSplit(head, n);
}