// Write a Program to create a Binary Search Tree and perform deletion of
// a node from it. Also display the tree in nonrecursive postorder way.

#include <stdio.h>
#include <malloc.h>

typedef struct BST{
    int data;
    struct BST *left, *right;
}bst;

bst  *create(int data){
    bst *root = (bst*)malloc(sizeof(bst));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

bst *Insert(int data, bst *root){
    bst *parent = NULL;
    bst *current = root;
    while(current != NULL){
        parent= current;
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
    }else if(data > parent->data){
        parent->right = temp;
    }
    
    return root;
}

void PostOrder(bst *root){
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


bst *Delete(int data, bst *root){
    bst *previous = NULL;
    bst *p= root;
    while (p != NULL && data != p->data)
    {
        if(data < p->data){
            previous = p;
            p = p->left;
        }else if(data > p->data){
            previous = p;
            p = p->right;
        }
    }

    if(p == NULL){
        printf("\nNo Such Node with data %d", data);
        return root;
    }
    if(p->right == NULL && p->left == NULL){
        if(previous == NULL){
            root = NULL;
        }else if(previous->left == p){
            previous->left = NULL;
        }else{
            previous->right = NULL;
        }
        free(p);
    }else if(p->right == NULL && p->left != NULL){
        if(previous == NULL){
            root = p->left;
        }else if(previous->left == p){
            previous->left = p->left;
        }else{
            previous->right = p->left;
        }
        free(p);
    }else if(p->right != NULL && p->left == NULL){
        if(previous == NULL){
            root = p->right;
        }else if(previous->left == p){
            previous->left = p->right;
        }else{
            previous->right = p->right;
        }
        free(p);
    }else{
        bst *par = p->right;
        previous = p;
        while(par->left != NULL){
            previous = par;
            par = par->left;
        }
        p->data = par->data;
        if(previous == p){
            previous->right = par->right;
        }else{
            previous->left = par->right;
        }
        free(par);
    }
    printf("\nDeleted Successfully");
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

    //postorder
    printf("\nPost-Order Traversal: ");
    PostOrder(root);

    //delete the node
    int n;
    printf("\nEnter the node with dta to be deleted: ");
    scanf("%d", &n);
    root = Delete(n, root);
    printf("\nPost-Order Traversal after Deletion: ");
    PostOrder(root);
}