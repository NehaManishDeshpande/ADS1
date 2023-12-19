// Write a Program to create a Binary Search Tree and display its mirror
// image with and without disturbing the original tree. Also display height
// of a tree using nonrecursion.


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

bst *Insert(int data,  bst *root){
    bst *parent = NULL;
    bst *current = root;
    while(current != NULL){
        parent = current;
        if(data < current->data){
            current = current->left;
        }else if(data > current->data){
            current = current->right;
        }else{
            return root;
        }
    }

    bst *temp = create(data);
    if(data < parent->data){
        parent->left = temp;
    }else{
        parent->right = temp;
    }

    return root;
}

int DisplayHeight(bst *root){
    int maxHeight = 0;
    typedef struct Stack{
        bst *node;
        int height;
    }Stack;

    Stack stack[50];
    int top  =-1;

    stack[++top] = (Stack){root, 1};
    while(top != -1){
        Stack current = stack[top--];
        bst *node = current.node;
        int height = current.height;
        if(height > maxHeight){
            maxHeight = height;
        }
        if(node->left != NULL){
            stack[++top] = (Stack){node->left, height + 1};
        }
        if(node->right != NULL){
            stack[++top] = (Stack){node->right, height + 1};
        }
    }

    return maxHeight;
}

bst *mirrorImage(bst *root){
    bst *node = root;
    bst *p = node;
    bst *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = p;
    while(front <= rear){
        p = queue[front++];
        bst *q = p->left;
        p->left = p->right;
        p->right = q;

        if(p->left != NULL){
            queue[++rear] = p->left;
        }
        if(p->right != NULL){
            queue[++rear] = p->right;
        }
    }
    return node;
}

void show(bst *root){
    bst *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while (front <= rear)
    {
        int size = rear-front+1;
        for(int i=0; i<size; i++){
            bst *p = queue[front++];
            printf(" %d ", p->data);
            if(p->left != NULL){
                queue[++rear] = p->left;
            }
            if(p->right != NULL){
                queue[++rear] = p->right;
            }    
        }
        printf("\n");
    }
}

void main(){
    bst *root = create(64);
    root = Insert(85, root);
    root = Insert(74, root);
    root = Insert(45, root);
    root = Insert(65, root);
    root = Insert(23, root);
    root = Insert(24, root);
    root = Insert(11, root);
    root = Insert(19, root);

    //display bst
    printf("\nBST contains:\n");
    show(root);

    //display height
    printf("\nHeight of the BST is: %d", DisplayHeight(root));

    //mirrorimage
    printf("\nBST nodes after Mirroring:\n");
    show(mirrorImage(root));
}