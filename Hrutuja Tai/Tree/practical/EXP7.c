// You have to maintain information for a shop owner. For each of the
// products sold in his/hers shop the following information is kept: a
// unique code, a name, a price, amount in stock, date received, expiration
// date. For keeping track of its stock, the clerk would use a computer
// program based on a search tree data structure. Write a program to help
// this person, by implementing the following operations: • Insert an item
// with all its associated data. • Find an item by its code, and support
// updating of the item found. • List valid items in lexicographic order of
// their names.


#include <stdio.h>
#include <malloc.h>

typedef struct List{
    int UNiqueCode, price, amountInStock;
    char name[10];
    char DateReceived[10];
    char ExpiryDate[10];
}list;

typedef struct Tree{
    list *node;
    struct Tree *left, *right;
}tree;

list *createList(int code, char name[10], int price, int amount, char date[10], char expiry[10]){
    list *node = (list*)malloc(sizeof(list));
    node->UNiqueCode = code;
    node->name = name;
    node->price =price;
    node->amountInStock = amount;
    node->DateReceived = date;
    node->ExpiryDate = expiry;
    return node;
}

tree *create(list *node){
    tree *root = (tree*)malloc(sizeof(tree));
    root->node = node;
    root->left = root->right = NULL;
    return root;
}

tree *Insert(list *node, tree *root){
    if(root == NULL){
        return create(node);
    }
    tree *parent = NULL;
    tree *current = root;
    while(current != NULL){
        parent = current;
        if(node->UNiqueCode < current->node->UNiqueCode){
            current = current->left;
        }
        if(node->UNiqueCode > current->node->UNiqueCode){
            current = current->right;
        }
    }

    tree *newNode = create(node);
    if(newNode->node->UNiqueCode < parent->node->UNiqueCode){
        parent->left = newNode;
    }
    else if(newNode->node->UNiqueCode > parent->node->UNiqueCode){
        parent->right = newNode;
    }

    return root;
}

tree *changeItem(list *node, tree *root){
    char ch;
    int n;
    printf("\nDO you wan tot edi the item content y/ n");
    scanf("%c", &ch);
    if(ch == 'Y' || ch = 'y'){
        printf("Which part of te item to change:\n2.Name\n3.Price\n4.Expiry Date\n5.Receiving Date\n6.Amount in Stock\nEnter the choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 2:
            char name[10];
            printf("\nEnter the Name : ");
            scanf("%s", name);
            node->name = name;
            break;

        case 3:
            int price;
            printf("\nEnter the Price : ");
            scanf("%d", &price);
            node->price = price;
            break;

        case 4:
            char name[10];
            printf("\nEnter the Name : ");
            scanf("%s", name);
            node->name = name;
            break;

        case 5:
            char expD[10];
            printf("\nEnter the Expiry Date : ");
            scanf("%s", expD);
            node->ExpiryDate = expD;
            break;

        case 6:
            int amount;
            printf("\nEnter the Amount in stock : ");
            scanf("%d", amount);
            node->amountInStock = amount;
            break;
        
        default:
            printf("\nInvalid Option");
            break;
        }
    }
    return root;
}

void findByCode(int code, tree *root){
    if(root == NULL){
        printf("\nNO NODE");
        return;
    }
    while(root != NULL && code != root->node->UNiqueCode){
        if(code < root->node->UNiqueCode){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(root != NULL){
        printf("\nItem Unique Code      | %d", root->node->UNiqueCode);
        printf("\nItem Name             | %s", root->node->name);
        printf("\nItem Price            | %d", root->node->price);
        printf("\nItem Amount in stock  | %d", root->node->price);
        printf("\nItem Receiving Date   | %s", root->node->DateReceived);
        printf("\nItem Expiry Date      | %s", root->node->ExpiryDate);
    }
    else{
        printf("\nNO SUCH ITEM WITH %d CODE", code);
    }

    changeItem(root->node, root);
}

int isValid(Product* product) {
    __DATE__
}


void listValidItems(tree* root) {
    if (root == NULL) {
        return;
    }
    char name[10];
    name = root->node->name;

    listValidItems(root->left);

    if (isValid(root->data)) {
        printf("%d %s %.2f %d %s %s\n", root->data->code, root->data->name,
               root->data->price, root->data->stock, root->data->received_date,
               root->data->expiration_date);
    }

    listValidItems(root->right);
}
