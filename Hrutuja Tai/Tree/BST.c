// WAP to perform following operations on BST.
// g. Display Leaf Nodes.

#include<stdio.h>
#include<malloc.h>

typedef struct BST{
    int data;
    struct BST *left, *right;
}bst;


int countNodes = 0;

bst *newNode(int data){
    bst *root = (bst*)malloc(sizeof(bst*));;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    countNodes++;
    return (root);
}


bst *insert(int data, bst *root){
    

    if(root == NULL){
        return newNode(data);
    }
    
    if(data < root->data){
        root->left = insert(data, root->left);
    }
    else if(data > root->data){
        root->right = insert(data, root->right);
    }

    return(root);
}

void inOrder(bst *root){
    int top = -1;
    bst *stack[50];
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

void preOrder(bst *root){  //P-L-R
    int top = -1;
    bst *stack[50];
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

void postOrder(bst *root){    //L-R-P
    int top = -1;
    bst *stack[50];
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


bst *delete(bst *root, int key){
    bst *temp;
    

    if(root == NULL){
        return root;
    }
    if(key < root->data){  //deleting left node
        root->left = delete(root->left, key);
    }
    else if(key > root->data){    //deleting node at right
        root->right = delete(root->right, key);
    }
    else{                    //different possibilities for deleting
        if(root->right == NULL && root->left == NULL){     //no child
            return NULL;
        }
        else if(root->right == NULL && root->left != NULL){              //1 child
            temp = root->left;
            countNodes--;
            return (temp);
        }
        else if(root->left == NULL && root->right != NULL){               //1 child
            temp = root->right;
            countNodes--;
            return (temp);
        }
        else{                                     //2  child
            temp = root->right;
            countNodes--;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return (root);
}


bst *mirrorImage(bst *root){                     
    if(root == NULL){
        return  root;
    }
    else{               // top to bottom approach
        bst *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirrorImage(root->left);
        mirrorImage(root->right);
    }                                          
    return root;
}


void displayLeaf(bst *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        printf(" %d ", root->data);
    }
    else{
        displayLeaf(root->left);
        displayLeaf(root->right);
    }
}

int displayHeight(bst *root){
    if(root == NULL){
        return 0;
    }
    else{
        int heightLeft = displayHeight(root->left);
        int heightRight = displayHeight(root->right);

        if(heightLeft > heightRight){
            return (heightLeft +1);
        }
        else{
            return (heightRight +1);
        }
    }
}

void currentLevel(bst *root, int level){
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

void levelDisplay(bst *root){
    int level = 1;
    int h = displayHeight(root) + 1;
    while (level != h){
        currentLevel(root, level);
        printf("\n");
        level++;
    }
}

void main(){
/*
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
                    
*/


    bst *root = NULL;
    root = insert(10, root);
    insert(6, root);
    insert(15, root);
    insert(4, root);
    insert(19, root);
    insert(86, root);
    insert(100, root);
    insert(47, root);
    insert(88, root);
    insert(45, root);
    insert(89, root);
    insert(70, root);

    
    //contents of the node
    printf("\nInorder Traversal: ");
    inOrder(root);
    printf("\nPreorder Traversal: ");
    preOrder(root);
    printf("\nPostorder Traversal: ");
    postOrder(root);


    //number of nodes
    printf("\nTotal number of nodes are: %d", countNodes);

    // //insert new node
    // printf("\nEnter the Elements to be entered in the tree: ");
    int n;
    // scanf("%d", &n);
    // root = insert(n, root);


    // // contents of the node
    // printf("\nInorder Traversal: ");
    // inOrder(root);

     //level wise 
    printf("\nLevel Wise display:\n");
    levelDisplay(root);

    // deleting node
    printf("\nEnter the node to be deleted: ");
    scanf("%d", &n);
    root = delete(root, n);
    //displaying
    printf("\nInorder Traversal: ");
    inOrder(root);

    //level wise 
    printf("\nLevel Wise display:\n");
    levelDisplay(root);

    //height of the bst
    printf("\nThe height of the BSt is: %d", displayHeight(root) - 1);

    //display leaf nodes
    printf("\nDisplaying leaf nodes:");
    displayLeaf(root);

    //mirror image
    bst *mirror = mirrorImage(root);
    //displaying
    printf("\nMirror Traversal : ");
    inOrder(mirror);
}
