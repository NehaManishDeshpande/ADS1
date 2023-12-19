//binary tree using linked list for traversing


#include<stdio.h>
#include<malloc.h>

typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;




tree *create(int data){
    tree *leaf = (tree*)malloc(sizeof(tree*));
    leaf->data = data;
    leaf->left = NULL;
    leaf->right = NULL;

    return (leaf);
}

tree *insertLeft(tree *root, int data){
    root->left = create(data);
    return (root->left);
}

tree *insertRight(tree *root, int data){
    root->right = create(data);
    return (root->right);
}

void inOrder(tree *root){     //L-P-R
    int top = -1;
    tree *stack[50];
    while(root != NULL){
        stack[++top] = root;
        root = root->left;
    }

    while(top != -1){
        root = stack[top--];
        printf(" %d ", root->data);
        root =  root->right;
        while(root != NULL){
            stack[++top] = root;
            root = root->left;
        }
    }
}

void preOrder(tree *root){  //P-L-R
    int top = -1;
    tree *stack[50];
    while(root != NULL){
        printf(" %d ", root->data);
        stack[++top] = root;
        root = root->left;
    }

    while(top != -1){
        root = stack[top--];
        root = root->right;
        while(root != NULL){
            printf(" %d ", root->data);
            stack[++top] = root;
            root = root->left;
        }
    }
}

void postOrder(tree *root){    //L-R-P
    int top = -1;
    tree *stack[50];
    tree *previous = NULL;
    do{
        while(root != NULL){
            stack[++top] = root;
            root = root->left;
        }

        while(root == NULL && top != -1){
            root = stack[top];
            if(root->right == NULL || root->right == previous){
                printf(" %d ", root->data);
                stack[top--];
                previous = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }
    }
    while(top != -1);
}


void main(){

/*
    10
      \
       6
      /  \
    15    4
     \
      19
    /   \
   86    100
    \       \
     47      45
      \        \
       88       89
               /
              70
*/
    tree *head = create(0);
    tree *root = create(10);
    insertRight(root, 6);
    insertLeft(root->right, 15);
    insertRight(root->right, 4);
    insertRight(root->right->left, 19);
    insertLeft(root->right->left->right, 86);
    insertRight(root->right->left->right, 100);
    insertRight(root->right->left->right->left, 47);
    insertRight(root->right->left->right->left->right, 88);
    insertRight(root->right->left->right->right, 45);
    insertRight(root->right->left->right->right->right, 89);
    insertLeft(root->right->left->right->right->right->right, 70);


    printf("\nInorder Traversal is: ");
    inOrder(root);
    printf("\nPreorder Traversal is: ");
    preOrder(root);
    printf("\nPostorder Traversal is: ");
    postOrder(root);
}