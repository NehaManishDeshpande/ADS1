// Write a Program to create a Binary Tree and perform following
// Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal
// c. Display Height of a tree d. Find Maximum

#include <stdio.h>
#include <malloc.h>

typedef struct Tree{
    int data;
    struct Tree *right, *left;
}tree;

tree *create(int data , tree *root){
    root = (tree*)malloc(sizeof(tree));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void Inorder(tree *root){
    if(root == NULL){
        printf("\nNO NODES");
        return;
    }
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
        while (root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }
    }
}


void Preorder(tree *root){
    if(root == NULL){
        printf("\nNO NODE");
        return;
    }

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

int findMaximum(tree *root){
    int max = 0;
    tree *stack[50];
    int top = -1;
    while (root != NULL)
    {
        stack[++top] = root;
        root = root->left;
    }
    while(top != -1){
        root = stack[top--];
        root= root->right;
        while(root != NULL){
            if(root->data > max){
                max = root->data;
            }
            stack[++top] = root;
            root = root->left;
        }
    }
    return max;
}

int displayHeight(tree *root){
    typedef struct height{
        tree *node;
        int height;
    }Stack;
    Stack stack[50];
    int top = -1;
    stack[++top] =(Stack){root, 1};
    int maxHeight = 1;
    while(top > 0){
        Stack current = stack[top--];
        tree *temp = current.node;
        int height = current.height;
        if(height > maxHeight){
            maxHeight = height;
        }
        if(temp->left != NULL){
            stack[++top] = (Stack){temp->left, height+1};
        }
        else if(temp->right != NULL){
            stack[++top] = (Stack){temp->right, height+1};
        }
    }
    return maxHeight;
}

void main(){
    tree *root = create(34, root);
    root->left = create(24, root->left);
    root->right = create(46, root->left);
    root->left->right = create(54, root->left->right);
    root->right->left = create(92,root->right->left);
    root->left->right->left = create(47, root->left->right->left);
    root->left->right->right = create(12,root->left->right->right);
    root->right->left->right = create(99, root->right->left->right);

    //Inorder
    printf("\nInorder Traversal: ");
    Inorder(root);

    //Preorder
    printf("\nPreorder Traversal: ");
    Preorder(root);

    //find maximum
    printf("\nMaximum node is of value: %d ", findMaximum(root));

    //Display height
    printf("\nTotal height of the tree : %d ", displayHeight(root)+1);

    
}