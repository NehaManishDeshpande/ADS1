// Write a Program to create a Binary Tree and perform following
// nonrecursive operations on it. a. Levelwise display b. Mirror image c.
// Display height of a tree

#include <stdio.h>
#include <malloc.h>

typedef struct BinaryTree{
    int data;
    struct BinaryTree *left, *right;
}tree;

tree *create(int data, tree *root){
    root = (tree*)malloc(sizeof(tree*));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void levelWiseDisplay(tree *root){
    if(root == NULL){
        return;
    }
    tree *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while(front <= rear){
        int size = rear - front + 1;
        for(int i = 0; i<size; i++){
            tree *temp = queue[front++];
            printf(" %d ", temp->data);
            if(temp->left != NULL){
                queue[++rear] = temp->left;
            }
            if(temp->right != NULL){
                queue[++rear] = temp->right;
            }    
        }
        printf("\n");
    }
}


tree *mirrorImage(tree *root){
    if(root == NULL){
        return root;
    }
    tree *queue[50];
    int front = 0, rear = -1;

    queue[++rear] = root;
    while(front<= rear){
        tree *p = queue[front++];
        tree *temp = p->left;
        p->left = p->right;
        p->right = temp;

        if(p->left != NULL){
            queue[++rear] = p->left;
        }
        if(p->right != NULL){
            queue[++rear] = p->right;
        }
    }
    return root;
}

int Height(tree *root){
    typedef struct stack{
        tree *node;
        int height;
    }Stack;

    Stack stack[50];
    int top = -1, Maxheight = 1;
    stack[++top] = (Stack){root, 1};

    while(top > 0){
        Stack current = stack[top--];
        tree *node = current.node;
        int height = current.height;

        if(height > Maxheight){
            Maxheight = height;
        }
        if(node->left != NULL){
            stack[++top] = (Stack){node->left, height+1};
        }else if(node->right != NULL){
            stack[++top] = (Stack){node->right, height+1};
        }
    }
    return Maxheight;
}

void main(){
    tree *root = create(25, root);
    root->left = create(16, root->left);
    root->right = create(12, root->right);
    root->left->left = create(20, root->left->left);
    root->right->right = create(26, root->right->right);

    //levelwiseDislay
    printf("\nLevel Wise Display:\n");
    levelWiseDisplay(root);

    //mirror Image
    printf("\nMirror Image:\n");
    root = mirrorImage(root);
    levelWiseDisplay(root);

    //display height
    printf("\nHeight of the binary tree: %d", Height(root) + 1);
}