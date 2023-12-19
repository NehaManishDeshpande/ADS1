// Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Delete • Find • Show

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


bst* Insert(int data, bst* root) {
    if (root == NULL) {
        return create(data);
    }
    
    bst* parent = NULL;
    bst* curr = root;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else if (data > curr->data) {
            curr = curr->right;
        } else {
            return root; // data already exists in the tree
        }
    }

    bst* newNode = create(data);
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}


bst *Delete(int data, bst *node){
    bst *root = node;
    if(root == NULL){
        return root;
    }
    bst *previous = NULL;
    while(data != root->data){
        if(data < root->data){
            previous = root;
            root = root->left;
        } else if(data > root->data){
            previous = root;
            root = root->right;
        }
    }

    if(root->right == NULL && root->left == NULL){
        if (previous == NULL) {
            node = NULL;
        } else if (previous->left == root) {
            previous->left = NULL;
        } else {
            previous->right = NULL;
        }
        free(root);
    } else if(root->right == NULL && root->left != NULL){
        if (previous == NULL) {
            node = root->left;
        } else if (previous->left == root) {
            previous->left = root->left;
        } else {
            previous->right = root->left;
        }
        free(root);
    } else if(root->right != NULL && root->left == NULL){
        if (previous == NULL) {
            node = root->right;
        } else if (previous->left == root) {
            previous->left = root->right;
        } else {
            previous->right = root->right;
        }
        free(root);
    } else {
        bst *par = root->right;
        previous = root;
        while(par->left != NULL){
            previous = par;
            par = par->left;
        }
        root->data = par->data;
        if (previous == root) {
            previous->right = par->right;
        } else {
            previous->left = par->right;
        }
        free(par);
    }
    return node;
}



void show(bst *root){
    if(root == NULL){
        return;
    }
    bst *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while(front <= rear){
        int size = rear - front + 1;
        for(int i = 0; i<size; i++){
            bst *temp = queue[front++];
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

void find(int data, bst *root){
    while (data != root->data)
    {
        if(data < root->data){
            root = root->left;
        }
        else if(data > root->data){
            root = root->right;
        }
    }
    printf("\nThe node Found:\n");
    printf("%d (%d) %d", root->left, root->data, root->right);
    
}

void main(){
    bst *root = create(25);
    root = Insert(24, root);
    root = Insert(23, root);
    root = Insert(14, root);
    root = Insert(36,root);
    root = Insert(29, root);

    //show the contents
    printf("\nShow: \n");
    show(root);

    //find
    find(23, root);

    // /Delete
    root = Delete(14, root);
    printf("\nShow after deleting: \n");
    show(root);
}