//Addition and displaying of two polynomials

#include<stdio.h>
#include<malloc.h>

typedef struct polynomial{
    int expo, cof;
    struct polynomial *next;
}poly;

void display(poly *head){       //displaying the algorithm
    while (head!=NULL){
        if(head->expo!=0 && head->cof !=0){
            printf("(%d x^%d)", head->cof, head->expo);
        }else if(head->expo ==0 && head->cof !=0){
             printf("(%d)", head->cof);
        }
        if(head->next!=NULL && head->cof!=0){
            printf(" + ");
        }
        head=head->next;
    }
}

poly *create(){               //creating the polynomial (linked list)
    poly *temp=(poly*)malloc(sizeof(poly*));
    return (temp);
}

poly *insert(int n, poly *head){   //insert nodes in the polynomial
    poly *p=head;
    int cof, expo;
    printf("\nEnter the highest degree of polynomial:");
    scanf("%d", &n);
    // n=n+1;

    printf("\nEnter the Coefficient:");
        scanf("%d", &cof);
        p->cof=cof;
        // printf("\nEnter the Exponential:");
        // scanf("%d", &expo);
        p->expo = n;
        p->next=NULL;

    // for(int i=2; i<n; i++){
    //     p->next=(poly*)malloc(sizeof(poly*));
    //     p=p->next;
    //     printf("\nEnter the Coefficient:");
    //     scanf("%d", &cof);
    //     p->cof=cof;
    //     printf("\nEnter the Exponential:");
    //     scanf("%d", &expo);
    //     p->expo = expo;
    //     p->next=NULL;
    // }

    n = n-1;
    while(n!=0){
        p->next=(poly*)malloc(sizeof(poly*));
        p=p->next;
        printf("\nEnter the Coefficient:");
        scanf("%d", &cof);
        p->cof=cof;
        p->expo = n;
        p->next=NULL;
        n-=1;
    }
    p->next=(poly*)malloc(sizeof(poly*));
    p=p->next;
    printf("\nEnter the constant:");
    scanf("%d",&cof);
    p->cof = cof;
    p->expo = 0;
    p->next = NULL; 

    return(head);
}


poly *addition(poly *h1, poly *h2){    
    poly *add=NULL, *p, *poly1 = h1, *poly2 = h2;

    if(poly1 != NULL && poly2 ==NULL){    // if h2 is empty add will be h1
        add = poly1;
        p = add;
    }
    else if(poly1 == NULL && poly2 != NULL){  //if h1 is empty add will be h2
        add = poly2;
        p = add;
    }
    else{
        while(poly1 != NULL && poly2 != NULL){
            if(add == NULL){
                add = (poly*)malloc(sizeof(poly*));
                p = add;
            }else{
                p->next = (poly*)malloc(sizeof(poly*));
                p = p->next;
            }

            //for addition
            if(poly1->expo > poly2->expo){  //check if exponential of poly 1 is greater than poly2
                p->cof = poly1->cof;
                p->expo = poly1->expo;
                poly1 = poly1->next;
            }
            else if(poly1->expo < poly2->expo){
                p->cof = poly2->cof;
                p->expo = poly2->expo;
                poly2 = poly2->next;
            }
            else if(poly1->expo == poly2->expo){
                p->cof = poly1->cof + poly2->cof;
                p->expo = poly1->expo;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    while(poly1!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;

        p->cof = poly1->cof;
        p->expo = poly1->expo;
        p->next = poly1->next;
        poly1 = poly1->next;
    }

    while(poly2!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;

        p->cof = poly2->cof;
        p->expo = poly2->expo;
        p->next = poly2->next;
        poly2 = poly2->next;
    }

    p->next = NULL;
    return (add);
}


poly *subtraction(poly *h1, poly *h2){    
    poly *sub=NULL, *p, *poly1 = h1, *poly2 = h2;

    if(poly1 != NULL && poly2 ==NULL){    // if h2 is empty add will be h1
        sub = poly1;
        p = sub;
    }
    else if(poly1 == NULL && poly2 != NULL){  //if h1 is empty add will be h2
        sub = poly2;
        p = sub;
    }
    else{
        while(poly1 != NULL && poly2 != NULL){
            if(sub == NULL){
                sub = (poly*)malloc(sizeof(poly*));
                p = sub;
            }else{
                p->next = (poly*)malloc(sizeof(poly*));
                p = p->next;
            }

            //for addition
            if(poly1->expo > poly2->expo){  //check if exponential of poly 1 is greater than poly2
                p->cof = poly1->cof;
                p->expo = poly1->expo;
                poly1 = poly1->next;
            }
            else if(poly1->expo < poly2->expo){
                p->cof = poly2->cof;
                p->expo = poly2->expo;
                poly2 = poly2->next;
            }
            else if(poly1->expo == poly2->expo){
                p->cof = poly1->cof - poly2->cof;
                p->expo = poly1->expo;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    while(poly1!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;

        p->cof = poly1->cof;
        p->expo = poly1->expo;
        p->next = poly1->next;
        poly1 = poly1->next;
    }

    while(poly2!=NULL){
        p->next = (poly*)malloc(sizeof(poly*));
        p = p->next;

        p->cof = poly2->cof;
        p->expo = poly2->expo;
        p->next = poly2->next;
        poly2 = poly2->next;
    }

    p->next = NULL;
    return (sub);
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


poly *multiplication(poly *h1, poly *h2){
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
    // mul = arrange(mul);
    return (mul);
}


void main(){
    poly *head1, *head2, *add;
    head1 = create();
    head2 = create();
    int n;
    printf("\nEnter 1st Polynomial:");
    head1 = insert(n, head1);
    printf("\nEnter 2nd Polynomial:");
    head2 = insert(n, head2);
    printf("\nPrinting Both Polynomials:\n");
    display(head1);
    printf("\n");
    display(head2);
    printf("\nPrinting Addition of Both Polynomials:\n");
    add = addition(head1, head2);
    display(add);
    printf("\nPrinting Subtraction of Both Polynomials:\n");
    poly *sub = subtraction(head1, head2);
    display(sub);
    printf("\nPrinting Multiplication of Both Polynomials:\n");
    poly *mul = multiplication(head1, head2);
    display(mul);
}