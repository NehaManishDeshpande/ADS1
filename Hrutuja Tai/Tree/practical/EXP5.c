// Write a Program to create a Binary Tree and perform following
// Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal
// c. Display Number of Leaf Nodes d. Mirror Image

#include <stdio.h>
#include <malloc.h>

typedef struct Tree{
    int data;
    struct Tree *left, *right;
}tree;

tree *create(int data, tree *root){
    root = (tree*)malloc(sizeof(tree));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void Inorder(tree *root){
    tree *stack[50];
    int top = -1;

    while(root != NULL){
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

void Preorder(tree *root){
    tree *stack[50];
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

int countLeafNodes(tree *root){
    int count = 0;
    if(root == NULL){
        return 0;
    }
    tree *stack[50];
    int top = -1;
    stack[++top] = root;
    while(top > -1){
        tree *temp = stack[top--];
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


tree *mirrorImage(tree *root){
    tree *temp;
    tree *queue[50];
    int front = 0, rear = -1;
    queue[+rear] = root;
    while(front <= rear){
        tree *node = queue[front++];
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        if(node->left != NULL){
            queue[++rear] = node->left;
        }
        if(node->right != NULL){
            queue[++rear] = node->right;
        }
    }
    return  root;
}

void main(){
    tree *root = create(34, root);
    root->left = create(24, root->left);
    root->right = create(46, root->left);
    root->left->right = create(54, root->left->right);
    root->right->left = create(92,root->right->left);
    root->left->right->left = create(47, root->left->right->left);
    root->left->right->right = create(12,root->left->right->right);

    //inorder
    printf("\nInorder Traversal: ");
    Inorder(root);

    //Preorder
    printf("\nPreorder Traversal: ");
    Preorder(root);

    //number of lef nodes
    printf("\nTotal number of Leaf nodes: %d", countLeafNodes(root));

    //mirror image
    root = mirrorImage(root);
    printf("\nInorder traversal after mirroring: ");
    Inorder(root);
}