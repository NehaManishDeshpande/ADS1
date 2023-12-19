// WAP to create doubly linked list and perform following operations on it.
// 5 8 Lists A) Insert (all cases) 2. Delete (all cases)

#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *create(){
    node *temp;
    temp=(node*) malloc(sizeof(node*));
    node *head = temp;
    return ( head );
}

node *insert(int n, node *head){
    int x;
    printf("enter the size of linked List:\n");
    scanf("%d" ,&n);
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
    node *p=head;
    printf("\nLinked list:\n");
    while (p!=NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

node *headInsert(int n, node* head){
    node *p=(node*)malloc(sizeof(node*));
    printf("\nEnter the data to be inserted at head:\n");
    scanf("%d" ,&n);
    p -> data = n;
    p -> next = head;
    head = p;

    return(head);
}

node *endInsert(int n, node* head){
    node *p=(node*)malloc(sizeof(node*));
    printf("\nEnter the data to be inserted at end:\n");
    scanf("%d" ,&n);
    p -> data = n;
    p -> next = NULL;
    node *q;
    q = head;
    while (q -> next!=NULL){
        q = q -> next;
    }
    q -> next = p;

    return(head);
}

node *posKeyInsert(int key, node* head){
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
    return head;
}

node *posInsert(int n, node* head){
    node *p=(node*)malloc(sizeof(node*));
    int num;
    printf("\nEnter the position At which data is to inserted\n");
    scanf("%d" ,&n);
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
    return head;
}

node *delete(int pos, node *head){
    node *p, *q;
    printf("\nEnter the Position to be Deleted: ");
    scanf("%d", &pos);
    p= (node*)malloc(sizeof(node*));
    p=head;
    q=head;
    if(pos==1){
        head=head->next;
        // free(head);
    }
    else{
        for(int i=1; i<pos; i++){
        p = p->next;
        }
        for(int i=1; i<pos-1; i++){
        q = q->next;
        }
        q->next = p->next;
    }
    // free(p);
    return head;
}


node *deleteKey(int Key, node *head){
    node *p, *q;
    printf("\nEnter the Element to be Deleted: ");
    scanf("%d", &Key);
    p=head;
    //for head
    if(head->data==Key){
        head = head->next;
        // free(head);
    }

    else{
         while(p!=NULL){
        if(p->next->data == Key){
            // q = p->next;
            p->next = p->next->next;
            // free(q);
            break;
        }
        else{
           p = p->next;
         }
       }
    }
    return head;
}



void main(){
    node *head;
    int n;
    head = create();
    head = insert (n, head);
    printLl(head); 
    printf("\nSelect the choice:\n1.Insert\n2.Delete\n");
    scanf("%d", &n);
    if(n == 1){
        printf("\nSelect the choice:\n1.Insert at head\n2.Insert at end\n3.Insert at Position\n4.Insert after a key\n");
        scanf("%d", &n);
        switch(n){
            case 1: head = headInsert(n, head);
                   break;
            case 2: head = endInsert(n, head);
                   break;
            
            case 3: head = posInsert(n, head);
                   break;
            
            case 4: head = posKeyInsert(n, head);
                   break;

            default: printf("\nInvalid Choice\n");
                   break;
        }
        printLl(head);
    }
    else if(n == 2){
        printf("\nSelect the choice:\n1.Delete the node by position\n2.Delete a key");
        scanf("%d", &n);
        switch(n){
            case 1: head = delete(n, head);
                   break;
            case 2: head = deleteKey(n, head);
                   break;

            default: printf("\nInvalid Choice\n");
                   break;
        }
    }
}