// Write a Program to create a Binary Tree and perform following
// nonrecursive operations on it. a. Preorder Traversal b. Postorder
// Traversal c. Count total no. of nodes d. Display height of a tree.

#include <stdio.h>
#include <malloc.h>


typedef struct BinaryTree{
    int data;
    struct BinaryTree *left, *right;
}binaryTree;

int count = 0;

binaryTree *create(int data, binaryTree *root){
    binaryTree *temp = (binaryTree*)malloc(sizeof(binaryTree));
    temp->data = data;
    temp->left = temp->right = NULL;
    root = temp;
    count++;
    return root;
}

void preOrder(binaryTree *root){
    binaryTree *p = root;
    binaryTree *stack[50];
    int top = -1;
    
    //left most
    while(p!= NULL){
        printf(" %d ", p->data);
        stack[++top] = p;
        p = p->left;
    }

    //next
    while(top != -1){
        p = stack[top--];
        p = p->right;
        while(p!= NULL){
            printf(" %d ", p->data);
            stack[++top] = p;
            p = p->left;
        }    
    }
}

void postOrder(binaryTree *root){
    binaryTree *p = root;
    binaryTree *stack[50];
    binaryTree *previous = NULL;
    int top = -1;

    do{
        while (p != NULL){
            stack[++top] = p;
            p = p->left;
        }
    
        while(p == NULL && top != -1 ){
            p = stack[top];
            if(p->right == NULL ||  p->right == previous){
                printf(" %d ", p->data);
                top--;
                previous = p;
                p = NULL;
            }
            else{
                p = p->right;
                break;
            }
        }    
    }
    while(top != -1);
}


int height(binaryTree *root){
    typedef struct Stack{
        binaryTree *node;
        int height;
    }Stack;
    Stack stack[50];
    int top = -1;
    int maxHeight = 1;

    stack[++top] = (Stack){root, 1};

    while(top > 0){
        Stack current = stack[top--];
        binaryTree *node = current.node;
        int height = current.height;

        if(height > maxHeight){
            maxHeight = height;
        }
        if(node->left != NULL){
            stack[++top] = (Stack){node->left, height+1};
        }
        else if (node->right != NULL){
            stack[++top] = (Stack){node->right, height+1};
        }
    }
    return maxHeight;
}

void main(){
    binaryTree *root = create(10, root);
    root->left = create(6, root->left);
    root->right = create(5, root->right);
    root->left->right = create(8, root->left->right);
    root->right->left = create(12, root->right->left);

    //preOrder
    printf("\nPre-Order Traversal: ");
    preOrder(root);

    //postOrder
    printf("\nPost-Order Traversal: ");
    postOrder(root);

    //number of node
    printf("\nTotal number of nodes in the binary tree are : %d", count);

    //height
    printf("\nHeight of the binary tree : %d", height(root) + 1);
}