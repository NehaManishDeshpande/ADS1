// Write a Program to create Inorder Threaded Binary Tree and Traverse it
// in Inorder and Postorder way

// Write a Program to create Inorder Threaded Binary Tree and Traverse it
// in Inorder and Preorder way.

#include <stdio.h>
#include <malloc.h>

typedef struct TBT{
    int data, rbit, lbit;
    struct TBT *left, *right;
}tbt;

tbt *create(int data, tbt *root){
    root = (tbt*)malloc(sizeof(tbt));
    root->data = data;
    root->lbit = root->rbit = 0;
    root->left = root->right = NULL;
    return root;
}

tbt *inorderSuccessor(tbt *p){
    if(p->rbit == 0){
        return (p->right);
    }
    p = p->right;

    while(p->lbit == 1){
        p = p->left;
    }
    return (p);
}

void InorderTbt(tbt *root){
    while(root->lbit == 1){
        root = root->left;
    }
    while(root != NULL){
        printf(" %d ", root->data);
        root = inorderSuccessor(root);
    }
}

int main(){
    tbt *root  = create(10, root);
    root->lbit =root->rbit = 1;
    root->left = create(6, root->left);
    root->left->rbit = 1;
    root->right = create(5, root->right);
    root->right->lbit = 1;
    root->left->right = create(8, root->left->right);
    root->left->right->left = root->left->right;
    root->left->right->right = root;
    root->right->left = create(12, root->right->left);
    root->right->left->left = root;
    root->right->left->right = root->right;

    //inorder trversal
    printf("\nInorder TBT traveral: ");
    InorderTbt(root);

    //inorder trversal
    printf("\nPostorder TBT traversal not possible ");

    return (0);
}