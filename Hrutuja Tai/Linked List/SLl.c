//Linked LIst
//all action of insertion, deletion and reverse
//sub action of at end , at pos, and at start

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create();
node *insert (int n, node*);
void printLl(node*);
node *endInsert(int n, node*);
void actions(node *head, int n);
void end();
node *headInsert(int n, node*);
node *posInsert(int n, node*);
node *posKeyInsert(int n, node*);
void deleteKey(int Key, node*);
node *delete(int pos, node*);
node *reverse(node* head);

void main(){
    node *head;
    int n;
    printf("\nCreating the Linked List\n");
    head = create();
    head = insert (n, head);
    printf("\nCreated  Linked List is:\n");
    printLl(head);
    actions(head,n);
    char s;
    printf("\nWant to perform another action: y(1) / n(0).\n");
    scanf("%d ", &s);
    switch (s)
    {
    case 1: actions(head, n); 
        break;
    
    case 0: end();
        break;
    
    default: printf("\nIrrelevant option\n");
        break;
    }
}

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}

node *insert(int n, node *head){
    printf("enter the size of linked List:\n");
    scanf("%d" ,&n);
    int x;
    printf("\nEnter 1st element:\n");
    scanf("%d", &x);
    head -> data = x;
    head -> next = NULL;

    node *p = head;

    for(int i =1; i<n; i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter data:\n");
        scanf("%d", &x);
        p -> data = x;
        p -> next = NULL;
    }
    return (head);
}

void printLl(node *head){
    node *p;
    node *a;
    p=head;
    a=head;
    printf("\n\nThe Linked List is:\n");
    while (p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

void actions(node *head, int n){
    int option;
    printf("\n----Section the operations----");
    printf("\n1. Insertion At Beginning.\n2. Insertion At Position.\n3. Insertion After a Key.\n4. Insertion at the end.\n5. Deleting a node.\n6. Deleting node having a key.\n7. Reversing the Linked List.");
    scanf("%d", option);
    switch (option)
    {
    case 1: headInsert(n, head);
        break;

    case 2: posInsert(n, head);
        break;

    case 3: posKeyInsert(n, head);
        break;

    case 4: endInsert(n, head);
        break;

    case 5: delete(n, head);
        break;

    case 6: deleteKey(n, head);
        break;

    case 7: reverse(head);
        break;
    
    default: printf("\nError\n");
        break;
    }
}


node *endInsert(int n, node* head){
    printf("\nEnter the data to insert at end:\n");
    scanf("%d ", &n);
    node *p=(node*)malloc(sizeof(node*));
    p -> data = n;
    p -> next = NULL;
    node *q;
    q = head;
    while (q -> next!=NULL){
        q = q -> next;
    }
    q -> next = p;
    printLl(head);
    return head;
}

node *headInsert(int n, node* head){
    printf("\nEnter the data to insert at head:\n");
    scanf("%d ", &n);
    node *p=(node*)malloc(sizeof(node*));
    p -> data = n;
    p -> next = head;
    head = p;
    printLl(head);
    return(head);
}

node *posInsert(int n, node* head){
    printf("\nEnter the Position at which data is to be entered:\n");
    scanf("%d ", &n);
    node *p=(node*)malloc(sizeof(node*));
    int num;
    printf("\nEnter the data to insert at position %d:\n", n);
    scanf("%d", &num);
    p -> data = num;
    p -> next = NULL;
    node *q;
    q = head;
    for(int i=1; i<n-1; i++){
         q = q -> next;
    }

    if(q != NULL){
        p -> next = q -> next;
        q -> next = p;
    }
    printLl(head);
    return head;
}

node *posKeyInsert(int key, node* head){
    printf("\nEnter the key after which data is to be inserted:\n");
    scanf("%d ", &key);
    node *p=(node*)malloc(sizeof(node*));
    int num;
    printf("\nEnter the data to insert after key %d:\n", key);
    scanf("%d", &num);
    p -> data = num;
    p -> next = NULL;
    node *q;
    
    if(key == -1){
        p->next=head;
        head=p;
    }

    else{
        q = head;
        while(q->data!=key && q!=NULL){
            q=q->next;
        }
        if(q!=NULL){
            p->next=q->next;
            q->next=p;
        }
    }
    printLl(head);
    return head;
}

void deleteKey(int Key, node *head){
    node *p, *q;
    printf("\nEnter the Element to be Deleted: ");
    scanf("%d", &Key);
    p=head;
    //for head
    if(head->data==Key){
        q=head;
        head = head->next;
        free(q);
    }

    else{
         while(p!=NULL){
        if(p->next->data == Key){
            q = p->next;
            p->next = p->next->next;
            // free(q);
            break;
        }
        else{
           p = p->next;
        }
    }
    }
    printLl(head);
}

node *delete(int pos, node *head){
    node *p, *q;
    printf("\nEnter thr Position to be Deleted: ");
    scanf("%d", &pos);
    p= (node*)malloc(sizeof(node*));
    p=head;
    q=head;
    for(int i=1; i<pos; i++){
        p = p->next;
    }
    for(int i=1; i<pos-1; i++){
        q = q->next;
    }

    q->next = p->next;
    printLl(head);
    return head;
}

node *reverse(node* head){
    node *p=NULL;
    node *next=NULL;
    while (head != NULL){
        next = head->next; //save next
        head->next = p;  //update next
        //one position ahead
        p = head;
        head = next;
    }
    head = p;
    printLl(head);
    return head;
}