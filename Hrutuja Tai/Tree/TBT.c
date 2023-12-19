//inorder preorder postorder using TBT(Threaded Binary Tree)
// stackless traversals
// creating preorder postorder inorder

#include<stdio.h>
#include<malloc.h>

typedef struct TBT{
    int data;
    int lbit, rbit;
    struct TBT *left, *right;
}tbt;


tbt *create(int value){
    tbt *temp = (tbt*)malloc(sizeof(tbt*));
    temp->data = value;
    temp->lbit = 0;
    temp->rbit = 0;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

tbt *insert(tbt *p, int data)
{
    // Searching for a Node with given value
    tbt *ptr = p;
    tbt *par = NULL; // Parent of key to be inserted

    while (ptr != NULL)
    {
        par = ptr; // Update parent pointer
 
        // Moving on left subtree.
        if (data < ptr->data)
        {
            if (ptr->lbit == 1)
                ptr = ptr -> left;
            else
                break;
        }
 
        // Moving on right subtree.
        else
        {
            if (ptr->rbit == 1)
                ptr = ptr -> right;
            else
                break;
        }
    }
 
    // Create a new node
    tbt *tmp = (tbt*)malloc(sizeof(tbt*));
    tmp -> data = data;
    tmp -> lbit = 0;
    tmp -> rbit = 0;
 
    if (data < (par -> data))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lbit = 1;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rbit = 1;
        par -> right = tmp;
    }
 
    return p;
}


void preorderTBT(tbt *p){

    while (p != NULL){
        printf(" %d ", p->data);
        if(p->lbit == 1){
            p = p->left;
        }
        else if (p->rbit == 1){
            p = p->right;
        }
        else{
            while(p != NULL && p->rbit == 0){
                p = p->right;
            }
            if(p != NULL){
                p = p->right;
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

    while(p->lbit == 1){
        p = p->left;
    }
    while(p != NULL){
        printf(" %d ", p->data);
        p = inorderSuccessor(p);
        // p = p->right;
    }
}


void main(){
/*
    binary tree

         10
        /  \
       6    15
      /       \
     4         19
                 \
                  86
                /    \
               47    100
              / \    /
             45 70 88
                    \
                    89
    
    in: 4  6  10  15  19  45  47  70  86  88  89  100
    pre: 10  6  4  15  19  86  47  45  70  100  88  89
    post: 4   6  45  70  47  89  88  100  86  19  15  10 


*/
    tbt *root = create(10);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 19);
    root = insert(root, 86);
    root = insert(root, 100);
    root = insert(root, 47);
    root = insert(root, 88);
    root = insert(root, 45);
    root = insert(root, 89);
    root = insert(root, 70);



    printf("\nInorder TBT Traversal is: ");
    inOrderTBT(root);
    printf("\nPreorder Traversal is: ");
    preorderTBT(root);
}