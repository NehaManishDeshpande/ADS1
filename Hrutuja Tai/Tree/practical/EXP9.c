// Write a Program to create a Binary Search Tree and perform following
// nonrecursive operations on it. a. Preorder Traversal b. Inorder Traversal
// c. Display Number of Leaf Nodes d. Mirror Image


#include <stdio.h>
#include <malloc.h>

typedef struct BST{
    int data;
    struct BST *left, *right;
}bst;

bst *create(int data){
    bst *root = (bst*)malloc(sizeof(bst));
    root->data = data;
    root->left = root->right = NULL;
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

void Inorder(bst *root){
    bst *stack[50];
    int top= -1;
    while (root != NULL)
    {
        stack[++top] = root;
        root = root->left;
    }
    while(top != -1){
        root = stack[top--];
        printf(" %d ", root->data);
        root = root->right;
        while(root != NULL){
            stack[++top] = root;
            root = root->left;
        }
    }
    
}

int countLeafNodes(bst *root){
    int count = 0;
    bst *stack[50];
    int top = -1;
    stack[++top] = root;
    while(top > -1){
        bst *temp = stack[top--];
        if(temp->right == NULL && temp->left == NULL){
            count++;
        }
        if(temp->right != NULL){
            stack[++top] = temp->right;
        }
        if(temp->left != NULL){
            stack[++top] = temp->left;
        }
    }
    return count;
}

bst *mirrorImage(bst *root){
    bst *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while(front <= rear){
        bst *temp = queue[front++];
        bst *p = temp->left;
        temp->left = temp->right;
        temp->right = p;
        if(temp->left != NULL){
            queue[++rear] = temp->left;
        }
        if(temp->right != NULL){
            queue[++rear] = temp->right;
        }
    }
    return root;
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

    //Inorder
    printf("\nIn-Order Traversal: ");
    Inorder(root);

    //display height
    printf("\nNumber of leaf nodes in bst : %d", countLeafNodes(root));

    //mirror image
    root = mirrorImage(root);
    printf("\nMirror image: ");
    Inorder(root);
}