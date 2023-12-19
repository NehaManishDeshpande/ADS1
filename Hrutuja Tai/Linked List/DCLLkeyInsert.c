//Doubly circular linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *create();
node *insert (int n, node*);
void printDCLl(node*);
node *Last(node*);
node *keyInsertDCll(int n , node*);

void main(){
    node *head, *last;
    int n;
    printf("enter the size of doubly  circular linked List:\n");
    scanf("%d" ,&n);
    head = create();
    head = insert (n, head);
    printDCLl(head);
    last=Last(head);
    head = keyInsertDCll(n, last);
    printDCLl(head);
}

node *Last(node *head){
    node *p=head;
    do{
        p=p->next;
    }
    while(p->next!=head);
    return (p);
}

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}

node *insert(int n, node *head){
    int x;
    node *p = head;
    printf("\nEnter 1st element:\n");
    scanf("%d", &x);
    head -> data = x;
    head -> next = head;
    head -> prev =p;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> prev = p;
        p -> next = head;
    }
    p->next=head;
    return (head);
}

void printDCLl(node *head){
    node *p;
    node *a, *b;
    p=head;
    a=b=head;
    do{
        printf("%d -> ", p->data);
        p = p->next;
    }
    while (p!=head);
}


node *keyInsertDCll(int n, node* last){
    printf("\nEnter the key after which data is to be entered in the DCLL:");
    scanf("%d", &n);
    int num;
    printf("\nEnter the data  to be entered in the DCLL:");
    scanf("%d", &num);
    node *q=(node*)malloc(sizeof(node*));
    q->data=num;
    q->prev = q->next =NULL;

    if(n==-1){                //insert at head (-1 for head)
        q->next=last->next;
        q->prev=last;
        last->next->prev=q;
        last->next=q;
        q = last->next; //q as head
        return (q);
    }

    else{                 //insert at other position
        node *p=last->next;  //p as head
        while(p->data!=n && p->next!= last->next){
            p=p->next;
        }
        if(p == last){
            q->next=last->next;
            q->prev=last;
            last->next->prev=q;
            last->next=q;
            last=q;
            return (last->next);
        }
        else{
            q->next = p->next;
            q->prev = p;
            p->next = q;
            p->next->prev=q;
            return (last->next);
        }
    }
}