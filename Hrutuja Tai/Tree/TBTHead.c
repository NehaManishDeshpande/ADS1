//tbt with head

#include<stdio.h>
#include<malloc.h>

typedef struct TBTHead{
    struct TBTHead *left;
    int lbit;
    int data;
    int rbit;
    struct TBTHead *right;
}tbt;

tbt *create(int data){
    tbt *temp = (tbt*)malloc(sizeof(tbt*));
    temp->data = data;
    temp->lbit = temp->rbit = 0;
    temp->left = temp->right = NULL;

    return temp;
}

tbt *insertRight(int data, tbt *root){
    root->right = create(data);
    return (root->right);
}


tbt *insertLeft(int data, tbt *root){
    root->left = create(data);
    return (root->left);
}


void preOrderTBT(tbt *root){
    tbt *head = root;
    root = root->left;

    while (root != head){
        printf(" %d ", root->data);
        if(root->lbit == 1){
            root = root->left;
        }
        else if (root->rbit == 1){
            root = root->right;
        }
        else{
            while(root != head && root->rbit == 0){
                root =root->right;
            }
            if(root != head){
                root = root->right;
            }
        }
    }
}


tbt *inorderSuccessor(tbt *p){
    if(p->rbit == 0){
        return (p->right);
    }
    p = p->right;
    while(p->lbit == 1){
        p = p->left;
    }
    return(p);
}


void inOrderTBT(tbt *p){     //L-P-R  inorder with stack
    tbt *head = p;
     p = p->left;

    while(p->lbit == 1){
        p = p->left;
    }
    
    while(p != head){
        printf(" %d ", p->data);
        p = inorderSuccessor(p);
    }
}

// tbt *preOrderSuccessor(tbt *root){
//     if(root->rbit == 0){
//         return root;
//     }
//     if
// }


// void postOrderTBT(tbt *p){
//     tbt *head = p;
//     p = p->left;

//     tbt *par = NULL;

//     while (p->lbit == 1)               //traversing to left most node
//     {
//         par = p;
//         p = p->left;
//     }
//     while(p->right != head){

//         printf(" %d ", p->data);
//         p = preOrderSuccessor(p->right);
//     }
// }


void main(){
/*         head
           /
         10
        /  \
       8    11
      / \     \
     5   2     9
              / \
             1   3

in:   5 8 2 10 11 1 9 3
pre:  10 8 5 2 11 9 1 3
post:  5 2 8 1  3 9 11 10

*/

      tbt *head;
      head = create(0);
      insertLeft(10, head);
      head->left->lbit = 1;
      head->left->rbit = 1;

      insertLeft(8, head->left);
      head->left->left->lbit = 1;
      head->left->left->rbit = 1;

      insertRight(11, head->left);
      head->left->right->rbit = 1;
      head->left->right->left = head->left;     //thread 10

      insertLeft(5, head->left->left);
      head->left->left->left->left = head;                      //thread head
      head->left->left->left->right = head->left->left;        //thread 8

      insertRight(2, head->left->left);
      head->left->left->right->left = head->left->left;   //thread 8
      head->left->left->right->right = head->left;   //thread 10

      insertRight(9, head->left->right);
      head->left->right->right->left = head->left->right;       //thread 11
      head->left->right->right->right = head;       //thread  head
      head->left->right->right->lbit = 1;
      head->left->right->right->rbit = 1;

      insertLeft(1, head->left->right->right);
      head->left->right->right->left->left = head->left->right;           //thread 11
      head->left->right->right->left->right = head->left->right->right;    //thread 9

      insertRight(3, head->left->right->right);
      head->left->right->right->right->left = head->left->right->right;    //thread 9
      head->left->right->right->right->right = head;                       //thread head
      
      
      printf("\nInOrder Traversal on TBT with Head: ");
      inOrderTBT(head);

      printf("\nPreOrderTraversal on TBT with head: ");
      preOrderTBT(head);

    //   printf("\nPostOrderTraversal on TBT with head: ");
    //   postOrderTBT(head);
}