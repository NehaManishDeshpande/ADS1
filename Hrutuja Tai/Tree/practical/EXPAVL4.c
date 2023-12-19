// Write a Program to create Inorder Threaded Binary Tree and Traverse it
// in Postorder and Preorder way.


#include <stdio.h>
#include <malloc.h>

typedef struct InorderTBT{
    struct InorderTBT *left;
    int lbit, data, rbit;
    struct INorderTBT *right;
}tbt;

tbt *create (int data){
    tbt  *temp = (tbt*)malloc(sizeof(tbt));
    temp->data = data;
    temp->lbit = temp->rbit = 0;
    temp->left = temp->right = NULL;
    return temp;
}

tbt *insert (int data, tbt *head){
    tbt *ptr = head;
    tbt *parent = NULL;

    //take the parent
    while (ptr != NULL){
        parent = ptr;

        if(data < ptr->data){
            if(ptr->lbit == 1){
                ptr = ptr->left;
            }
            else{
                break;
            }
        }
        else if(data > ptr->data){
            if(ptr->rbit == 1){
                ptr = ptr->right;
            }
            else{
                break;
            }
        }
    }

    tbt *temp = create(data);
    
    //insert the links
    if(data < parent->data){
        temp->left = parent->left;
        temp->right = parent;
        parent->left = temp;
        parent->lbit = 1;
    }
    else if(data > parent->data){
        temp->left = parent;
        temp->right = parent->right;
        parent>right =temp;
        parent->rbit = 1;
    }

    return temp;
}

