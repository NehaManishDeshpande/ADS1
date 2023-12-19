#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct HashTable {
    int tableSize;
    vector<Node*> table;
};

Node* addSortedNode(int data, Node* currentHead) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;

    if (currentHead == nullptr || data < currentHead->data) {
        newnode->next = currentHead;
        return newnode;
    }

    Node* temp = currentHead;
    Node* prev = nullptr;
    while (temp != nullptr && data > temp->data) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;

    return currentHead;
}

void printList(Node* currentHead) {
    if (currentHead == nullptr) {
        cout << "X";
        return;
    }

    Node* temp = currentHead;
    while (temp != nullptr) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "X";
}

HashTable* createTable(int size) {
    HashTable* ht = new HashTable;
    ht->tableSize = size;
    ht->table.resize(size, nullptr);
    return ht;
}

void insertNodeinTable(int data, HashTable* ht) {
    int modData = data % 10;
    int index = modData;
    ht->table[index] = addSortedNode(data, ht->table[index]);
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < ht->tableSize; i++) {
        cout << i << "==>";
        printList(ht->table[i]);
        cout << endl;
    }
}

int main() {
    HashTable* ht = createTable(10);
    insertNodeinTable(10, ht);
    insertNodeinTable(11, ht);
    insertNodeinTable(17, ht);
    insertNodeinTable(20, ht);
    insertNodeinTable(25, ht);
    insertNodeinTable(35, ht);
    insertNodeinTable(45, ht);
    printHashTable(ht);

    return 0;
}
