//delete a node at a position

#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create();
node *insert(int n, node*);
void printLL(node*);
node *deleteKey(int Key, node*);
// void deleteKey(node **head, int Key);

void main(){
    node *head = (node*)malloc(sizeof(node*));
    head = create(head);
    int n;
    head = insert( n, head); //here is the size of linked list
    printLL(head);
    head = deleteKey(n, head); //here n is the pos to delete
    printLL(head);
}

node *create(){
     node *head= (node*)malloc(sizeof(node*));
     return head;
}

node *insert(int n, node *head){
    //here n is the size of the linkes list
    printf("\nEnter the size of Linked List:");
    scanf("%d", &n);
    printf("\nEnter the 1st element:");
    int num;
    scanf("%d", &num);
    node *p= (node*)malloc(sizeof(node*));
    head->data=num;
    head->next=NULL;
    p=head;
    for(int i=1; i<n; i++){
        p->next=(node*)malloc(sizeof(node*));
        p=p->next;
        printf("\nEnter Data Elements: ");
        scanf("%d", &num);
        p->data=num;
        p->next=NULL;
    }
    return head;
}

void printLL(node *head){
    node *p= (node*)malloc(sizeof(node*));
    p=head;
    while(p!=NULL){
        printf("%d -> ", p->data);
        p=p->next;
    }
    printf("NULL");
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




/*
void deleteKey(struct node **head, int Key)
{
      //temp is used to freeing the memory
      struct node *temp;
      struct node *current  = *head;

      printf("\nEnter the Element to be Deleted: ");
      scanf("%d", &Key);

      //key found on the head node.
      //move to head node to the next and free the head.
      if((*head)->data == Key)
      {
          temp = *head;    //backup to free the memory
          *head = (*head)->next;
        //   free(temp);
      }
      

      else
      {
          
          while(current->next != NULL)
          {
              //if yes, we need to delete the current->next node
              if(current->next->data == Key)
              {
                  temp = current->next;
                  //node will be disconnected from the linked list.
                  current->next = current->next->next;
                //   free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->next;
          }
      }
    //   head = current;
    //   printLL(head);
}

*/