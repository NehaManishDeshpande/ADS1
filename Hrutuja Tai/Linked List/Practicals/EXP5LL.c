//WAP to perform Multiplication o f two polynomials using singly linked list


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

void addMul(poly *h1){
    poly  *poly1 = h1, *poly2 ;
    while(poly1!=NULL ){
        poly2 = poly1;
        while(poly2->next!=NULL){

            if(poly1->expo == poly2->next->expo){   //add with condition
                poly1->cof = poly1->cof + poly2->next->cof;
                poly1->expo = poly1->expo;
                poly2->next =poly2->next->next;
            }
            else{
                poly2 = poly2->next;
            }
        }
        poly1 = poly1->next;
    }
}



poly *Multiplication(poly *h1, poly *h2){
    poly *mul=NULL, *p, *poly1=h1, *poly2=h2;
    if(poly1 != NULL && poly2 == NULL){
        mul = poly1;
        p = mul;
    }
    else if(poly1 == NULL && poly2 != NULL){
        mul = poly2;
        p = mul;
    }
    else{
        while(poly1 != NULL){
            while(poly2 !=NULL){
                if(mul == NULL){
                    mul = (poly*)malloc(sizeof(poly*));
                    p = mul;
                }
                else{
                    p->next = (poly*)malloc(sizeof(poly*));
                    p = p->next;
                }
                
                //multiplication begins
                p->cof = poly1->cof * poly2->cof;
                p->expo = poly1->expo + poly2->expo;

                poly2 = poly2->next;
            }

            poly1 = poly1->next;
            poly2 = h2;
        }
        p->next =NULL;
    }
    addMul(mul);
    return (mul);
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

    poly *mul = Multiplication(head1, head2);
    printf("\nMultiplication of polynomials: ");
    Display(mul);
}
