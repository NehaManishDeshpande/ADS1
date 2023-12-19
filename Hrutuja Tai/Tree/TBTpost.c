#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int lthread;  // 1 if left pointer is a thread, 0 otherwise
    int rthread;  // 1 if right pointer is a thread, 0 otherwise
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->lthread = 1;
    node->rthread = 1;
    return node;
}

// Function to insert a new node in threaded binary tree
void insert(struct Node* root, int data) {
    struct Node* prev, *cur;
    cur = root;
    while (cur) {
        prev = cur;
        if (data < cur->data) {
            if (cur->lthread == 0) {
                cur = cur->left;
            }
            else {
                break;
            }
        }
        else {
            if (cur->rthread == 0) {
                cur = cur->right;
            }
            else {
                break;
            }
        }
    }
    struct Node* node = newNode(data);
    if (data < prev->data) {
        node->left = prev->left;
        node->right = prev;
        prev->lthread = 0;
        prev->left = node;
    }
    else {
        node->right = prev->right;
        node->left = prev;
        prev->rthread = 0;
        prev->right = node;
    }
}

// Function to traverse the threaded binary tree in postorder
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* prev = NULL;
    while (root) {
        if (root->rthread == 1) {
            if (root->lthread == 1) {
                printf("%d ", root->data);
                prev = root;
                root = root->left;
            }
            else if (prev == root->left) {
                printf("%d ", root->data);
                prev = root;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else {
            struct Node* successor = root->right;
            while (successor->lthread == 0) {
                successor = successor->left;
            }
            if (prev == successor) {
                printf("%d ", root->data);
                if (successor == root->right) {
                    break;
                }
                else {
                    prev = root;
                    root = successor->right;
                }
            }
            else {
                root = successor;
            }
        }
    }
}

int main() {
    struct Node* root = newNode(4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    printf("Postorder traversal of threaded binary tree: ");
    postorder(root);

    return 0;
}
