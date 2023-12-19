// Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Mirror Image • Find • Post order
// (nonrecursive)

#include <stdio.h>
#include <malloc.h>

typedef struct BST{
    int data;
    struct BST *left, *right;
}bst;

// bst *create(int data){
//     bst *root = (bst*)malloc(sizeof(bst));
//     root->data = data;
//     root->left = root->right = NULL;
//     return root;
// }

// bst *Insert(int data, bst *root){
//     if(root == NULL){
//         return create(data);
//     }

//     bst *previous = NULL;
//     bst *current = root;

//     while (current != NULL)
//     {
//         previous = current;
//         if(data < current->data){
//             current = current->left;
//         }else if(data > current->data){
//             current = current->right;
//         }else{
//             return root;
//         }
//     }

//     bst *newNode = create(data);
//     if(data < previous->data){
//         previous->left = newNode;
//     }else {
//         previous->right = newNode;
//     }
    
//     return root;
// }


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

bst *mirrorImage(bst *root){
    bst *temp;
    if(root == NULL){
        return root;
    }
    bst *queue[50];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while(front <= rear){
        bst *p = queue[front++];
        temp = p->left;
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


void find(int data, bst *root){
    while (root != NULL && data != root->data)
    {
        if(data < root->data){
            root = root->left;
        }
        else if(data > root->data){
            root = root->right;
        }
    }
    
    if(root != NULL){
        printf("\nNode FOUND: \n");
        printf("left: %d; data: %d; right: %d", root->left, root->data, root->right);
    }else{
        printf("\nNODE NOT FOUND: %d", data);
    }
}


void postOrder(bst *node){
    bst *root = node;
    bst *stack[50];
    int top = -1;
    bst *previous = NULL;

    do{
        while(root != NULL){
            stack[++top] = root;
            root = root->left;
        }

        while(root == NULL && top != -1){
            root = stack[top];
            if(root->right == NULL || root->right == previous){
                printf(" %d ", root->data);
                top--;
                previous = root;
                root = NULL;
            }
            else{
                root = root->right;
                break;
            }
        }    
    }
    while(top != -1);
}




void main(){
    bst *root = create(49);
    root = Insert(39, root);
    root = Insert(59,root);
    root = Insert(45, root);
    root = Insert(33, root);
    root = Insert(51, root);

    //PostOder
    printf("\nPost Order Traversal: ");
    postOrder(root);

    //find
    find(46, root);
    find(45, root);

    //mirror
    root = mirrorImage(root);
    printf("\nPostorder After Mirror: ");
    postOrder(root);
}