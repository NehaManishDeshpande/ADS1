// Write a Program to implement AVL tree and perform different rotations
// on it.

#include <stdio.h>
#include <malloc.h>

typedef struct AVL{
    int data, height;
    struct AVL *left, *right;
}avl;

int height(avl *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int max(int a, int b){
    if(a > b ){
        return a;
    }
    else{
        return b;
    }
}

int getBalance(avl *root){
    if(root == NULL){
        return 0;
    }
    return (height(root->left) - height(root->right));
}

avl *leftRotate(avl *root){
    avl *temp = root->right;
    avl *node = temp->left;

    temp->left = root;
    root->right = node;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

avl *rightRotate(avl *root){
    avl *temp = root->left;
    avl *node = temp->right;

    temp->right = root;
    root->left = node;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

avl *Insert(int data, avl *root){
    if(root == NULL){
        root = (avl*)malloc(sizeof(avl));
        root->data = data;
        root->left = root->right = NULL;
        root->height = 1;
        return root;
    }else if(data < root->data){
        root->left = Insert(data, root->left);
    }else if(data > root->data){
        root->right = Insert(data, root->right);
    }else {
        printf("\nduplicate key not allowed");
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    //rr
    if(balance > 1 && data < root->left->data){
        return(rightRotate(root));
    }
    //ll
    if(balance < -1 && data > root->right->data){
        return(leftRotate(root));
    }
    //lr
    if(balance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return(rightRotate(root));
    }
    //rl
    if(balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return(leftRotate(root));
    }
    return root;
}


void inOrder(avl *root){
    int top = -1;
    avl *stack[50];
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

void preOrder(avl *root){  //P-L-R
    int top = -1;
    avl *stack[50];
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

void postOrder(avl *root){    //L-R-P
    int top = -1;
    avl *stack[50];
    avl *previous = NULL;
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

//delete same as bst
avl *deleteAVL(int key, avl *root){
    avl *temp;

    if(root == NULL){
        return root;
    }
    if(key < root->data){  //deleting left node
        root->left = deleteAVL(key, root->left);
    }
    else if(key > root->data){    //deleting node at right
        root->right = deleteAVL(key, root->right);
    }
    else{                    //different possibilities for deleting
        if(root->right == NULL && root->left == NULL){     //no child
            return NULL;
        }
        else if(root->right == NULL && root->left != NULL){              //1 child
            temp = root->left;
            return (temp);
        }
        else if(root->left == NULL && root->right != NULL){               //1 child
            temp = root->right;
            return (temp);
        }
        else{                                     //2  child
            temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteAVL(temp->data, root->right);
        }
    }
    return (root);
}


//same as bst
void currentLevel(avl *root, int level){
    if(root == NULL){
        return ;
    }
    if(level == 1){
        printf(" %d ", root->data);
    }
    else if(level > 1){
        currentLevel(root->left, level-1);
        currentLevel(root->right, level-1);
    }
}

//same as bst
void levelDisplay(avl *root){
    int level = 1;
    int h = height(root) + 1;
    while (level != h){
        currentLevel(root, level);
        printf("\n");
        level++;
    }
}



void main(){
/* Normal Binary search tree
         10
        /  \
       6    15
      /       \
     4         19
                 \
                  86
                /    \
               47    100
              / \    /
             45 70 88
                    \
                    89
                    

balanced binary search tree
                     19
                    /  \
                  10    86
                /  \   /   \
               6   15 47   89
              /      / \   / \
             4     45  70 88  100

in:   4 6 10 15 19 45 47 70  86 88 89 100
pre: 19 10 6  4 15 86 47 45  70 86 88 100
post: 4 6 15 10 45 70 47 88 100 89 86 19
[level]:
19
10  86
6  15  47  89
4  45  70  88  100 
*/


    avl *root = NULL;
    root = Insert(10, root);
    root = Insert(6, root);
    root = Insert(15, root);
    root = Insert(4, root);
    root = Insert(19, root);
    root = Insert(86, root);
    root = Insert(100, root);
    root = Insert(47, root);
    root = Insert(88, root);
    root = Insert(45, root);
    root = Insert(89, root);
    root = Insert(70, root);



    
    //contents of the node
    printf("\nInorder Traversal: ");
    inOrder(root);
    printf("\nPreorder Traversal: ");
    preOrder(root);
    printf("\nPostorder Traversal: ");
    postOrder(root);

    printf("\nLevel Wise Display:\n");
    levelDisplay(root);
}