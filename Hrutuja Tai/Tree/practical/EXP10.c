// Write a Program to create a Binary Search Tree and perform following
// nonrecursive operations on it. a. Preorder Traversal b. Postorder
// Traversal c. Display total Number of Nodes d. Display Leaf nodes

#include <stdio.h>
#include <malloc.h>

typedef struct BST{
    int data;
    struct BST *left, *right;
}bst;

int count = 0;

bst *create(int data){
    bst *root = (bst*)malloc(sizeof(bst));
    root->data = data;
    root->left = root->right = NULL;
    count++;
    return root;
}

bst *Insert(int data, bst *root){
    bst *parent = NULL;
    bst *current = root;
    while(current != NULL){
        parent = current;
        if(data < current->data){
            current = current->left;
        }
        else if(data > current->data){
            current = current->right;
        }else{
            return root;
        }
    }
    bst *temp = create(data);
    if(data < parent->data){
        parent->left = temp;
    }
    else if(data > parent->data){
        parent->right = temp;
    }

    return root;
}

void Preorder(bst *root){
    bst *stack[50];
    int top = -1;
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

void Postorder(bst *root){
    bst *stack[50];
    int top = -1;
    bst *previous = NULL;
    do{
        while(root != NULL){
            stack[++top] = root;
            root = root->left;
        } 

        while (root == NULL && top != -1)
        {
            root = stack[top];
            if(root->right == NULL || root->right == previous)
            {
                printf(" %d ", root->data);
                top--;
                previous = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }          
    }while(top != -1);
}

void DisplayLeaf(bst *root){
    bst *stack[50];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        bst *temp = stack[top--];
        if(temp->right == NULL && temp->left == NULL){
            printf(" %d ",temp->data);
        }
        if(temp->right != NULL){
            stack[++top] = temp->right;
        }
        if(temp->left != NULL){
            stack[++top] = temp->left;
        }
    }
}

void main(){
     bst *root = create(24);
    root = Insert(22, root);
    root = Insert(14, root);
    root = Insert(23, root);
    root = Insert(98, root);
    root = Insert(87, root);
    root = Insert(21, root);
    root = Insert(95, root);
    root = Insert(45, root);

    //Preorder
    printf("\nPre-Order Traversal: ");
    Preorder(root);

    //Postorder
    printf("\nPost-Order Traversal: ");
    Postorder(root);

    //number of total nodes
    printf("\nTotal number of Nodes in BST: %d", count);

    //display leaf nodes
    printf("\nLeaf Nodes: ");
    DisplayLeaf(root);
}