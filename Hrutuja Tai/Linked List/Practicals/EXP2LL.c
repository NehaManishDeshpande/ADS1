//WAP to perform addition o f two polynomials using singly linked list.

#include<stdio.h>
#include<malloc.h>

typedef struct Polynomial{
    int cof, expo;
    struct Polynomial *next;
}poly;

poly *create(){
    poly *temp = (poly*)malloc(sizeof(poly*));
    return temp;
}

poly *Insert(poly *head, int n){
    poly *p = head;
    printf("\nEnter the highest degree of Polynomial:");
    scanf("%d", &n);
    int cof;
    printf("\nEnter the Coefficient:");
    scanf("%d", &cof);
    p->cof = cof;
    p->expo = n;
    p->next = NULL;
    n-=1;
    while(n!=0){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;
        printf("\nEnter the Coefficient:");
        scanf("%d", &cof);
        p->cof = cof;
        p->expo = n;
        p->next = NULL;
        n-=1;    
    }
    p->next = (poly*)malloc(sizeof(poly*));
    p = p->next;
    printf("\nEnter the Constant:");
    scanf("%d", &cof);
    p->cof = cof;
    p->expo = 0;
    p->next = NULL;
    
    return (head);
}

void Display(poly *head){
    poly *p = head;
    while(p!=NULL){
        if(p->expo!=0 && p->cof != 0){
            printf("%d x^%d", p->cof, p->expo);
        }
        else if(p->expo==0 && p->cof != 0){
            printf("%d",p->cof);
        }

        if(p->next!=NULL && p->expo!=0){
            printf(" + ");
        }
        p = p->next;
    }
}

poly *Addition(poly *poly1 , poly *poly2){
    poly *p1 = poly1, *p2 = poly2, *add=NULL, *p;
    if(p1 != NULL && p2 == NULL){
        add = p1;
        p = add;
    }
    else if(p1 == NULL && p2 != NULL){
        add = p2;
        p = add;
    }
    else{
        while(p1 != NULL && p2 != NULL){
            if(add == NULL){
                add = (poly*)malloc(sizeof(poly*));
                p = add;
            }
            else {
                p->next = (poly*)malloc(sizeof(poly*));
                p = p->next;
            }


            if(p1->expo > p2->expo){
                p->cof = p1->cof;
                p->expo = p1->expo;
                p1 = p1->next;
            }
            else if(p1->expo < p2->expo){
                p->cof = p2->cof;
                p->expo = p2->expo;
                p2 = p2->next;
            }
            else if(p1->expo == p2->expo){
                p->cof = p1->cof + p2->cof;
                p->expo = p1->expo;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
    }    

    while (p1!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;
        p->cof = p1->cof;
        p->expo = p1->expo;
        p1 = p1->next;
    }

    while (p2!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;
        p->cof = p2->cof;
        p->expo = p2->expo;
        p2 = p2->next;
    }

    p->next = NULL;
    return (add);
}


void main(){
    poly *head1, *head2;
    int n;
    printf("\nEnter the first Polynomial");
    head1 = create();
    head1 = Insert(head1, n);
    printf("\nEnter the second Polynomial");
    head2 = create();
    head2 = Insert(head2, n);
    printf("\nPolynomial 1: ");
    Display(head1);
    printf("\nPolynomial 2: ");
    Display(head2);

    poly *add = Addition(head1, head2);
    printf("\nAddition of polynomials: ");
    Display(add);
}
