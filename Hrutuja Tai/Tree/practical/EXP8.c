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
#include <stdlib.h>
#include <string.h>

// Define the structure for each product
typedef struct Product {
    int code;
    char name[50];
    float price;
    int stock;
    char date_received[20];
    char expiration_date[20];
    struct Product *left;
    struct Product *right;
} Product;

// Function to create a new product node
Product* createProduct(int code, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->code = code;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->stock = stock;
    strcpy(newProduct->date_received, date_received);
    strcpy(newProduct->expiration_date, expiration_date);
    newProduct->left = NULL;
    newProduct->right = NULL;
    return newProduct;
}

// Function to insert a product into the search tree
Product* insertProduct(Product* root, int code, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    if (root == NULL) {
        return createProduct(code, name, price, stock, date_received, expiration_date);
    }
    if (code < root->code) {
        root->left = insertProduct(root->left, code, name, price, stock, date_received, expiration_date);
    }
    else if (code > root->code) {
        root->right = insertProduct(root->right, code, name, price, stock, date_received, expiration_date);
    }
    else {
        printf("Error: Product with code %d already exists.\n", code);
    }
    return root;
}

// Function to search for a product in the search tree by its code
Product* searchProduct(Product* root, int code) {
    if (root == NULL || root->code == code) {
        return root;
    }
    if (code < root->code) {
        return searchProduct(root->left, code);
    }
    else {
        return searchProduct(root->right, code);
    }
}

// Function to update a product's information
void updateProduct(Product* product, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    strcpy(product->name, name);
    product->price = price;
    product->stock = stock;
    strcpy(product->date_received, date_received);
    strcpy(product->expiration_date, expiration_date);
    printf("Product with code %d updated successfully.\n", product->code);
}

char* getCurrentDate(){
    return "05/05/2023";
}

void showProduct(Product *root){

    printf("\nItem Unique Code      | %d", root->code);
    printf("\nItem Name             | %s", root->name);
    printf("\nItem Price            | %.2f", root->price);
    printf("\nItem Amount in stock  | %d", root->stock);
    printf("\nItem Receiving Date   | %s", root->date_received);
    printf("\nItem Expiry Date      | %s", root->expiration_date);
    printf("\n");
}


// Function to traverse the search tree in-order and print the products in lexicographic order of their names
void listProducts(Product* root) {
    if (root == NULL) {
        return;
    }
    
    listProducts(root->left);

    // while (root->expiration_date >= getCurrentDate()) {
        printf("%d %s %.2f %d %s %s\n", root->code, root->name, root->price, root->stock, root->date_received, root->expiration_date);
        // showProduct(root);
    // }
    
    listProducts(root->right);
}



void main(){
    Product* root = createProduct(2345, "D", 23.34, 23, "23/2/2022", "23/2/2023");
    root = insertProduct(root, 2346, "C", 19.34, 28, "23/4/2022", "23/5/2023");
    root = insertProduct(root, 2347, "A", 58.6, 15, "20/5/2022", "23/6/2023");
    root = insertProduct(root, 2348, "B", 50.00, 14, "23/5/2022", "23/5/2025");
    root = insertProduct(root, 2349, "E", 87.34, 87, "18/1/2022", "18/2/2024");
    root = insertProduct(root, 2350, "F", 88.00, 34, "31/5/2022", "31/5/2026");

    //find item by its code
    int n = 2346;
    printf("\nItem to Find with code : %d\n", n);
    Product *itemFound = searchProduct(root,n);
    if (itemFound != NULL) {
        showProduct(itemFound);
    } else {
        printf("Product not found.\n");
    }

    // //update item
    // char ch;
    // int n;
    // printf("\n\nDO you want to update the item content y/ n: ");
    // scanf("%c", &ch);
    // if(ch == 'Y' || ch == 'y'){
    //     updateProduct(temp,  "B", 15, 14, "23/5/2022", "23/5/2025");
    // }

    //list
    printf("\n\nListing valid items in Lexical order\n");
    listProducts(root);
}