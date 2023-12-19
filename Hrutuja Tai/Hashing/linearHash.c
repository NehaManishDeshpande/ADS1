// 12. WAP to implement Hashing using Linear Probing with chaining without replacement.( Hash Function:   Key % table size)

#include<stdio.h>

#define TableSize 10

int data[TableSize];
int  chain[TableSize];

int hashFunction(int key){
    return key % TableSize;
}

int hashFunctionNext(int key){
    return (hashFunction(key) + 1) % 10;
}

void hashTable(int key){

    int index = hashFunction(key);
    if (data[index] == -1) {
        data[index] = key;
    }
    else {
        int i = hashFunctionNext(index);
        while (i != index && data[i] != -1) {
            i = hashFunctionNext(i);
        }
        
        if (chain[index] == -1) {
            chain[index] = i;
        }
        else {
            int j = chain[index];
            while (chain[j] != -1) {
                j = chain[j];
            }
            chain[j] = i;
        }
        data[i] = key;
    }
}


void displayTable(){
    printf("\nHash Table:");
    printf("\nIndex  |  Data   |  Chain");
    for(int i = 0; i<TableSize; i++){
        printf("\n %d        %d         %d", i, data[i], chain[i]);
    }
}



// void hashTable(int key[TableSize], int n){

//     for(int i = 0; i < TableSize; i++){
//         data[i] = -1;
//         chain[i] = -1;
//     }

//     for (int i = 0; i <= n; i++)
//     {
//         int index = hashFunction(key[i]);
//         if(data[index] == -1){
//             data[index] = key[i];
//         }
//         else{
//             while(data[index] != -1){
//                 index++;
//                 if(index == TableSize){
//                     index = 0;
//                 }
//             }
//             chain[index] = index;
//             data[index] = key[i];
//         }  
//         // displayTable();  
//     }
// }






void main(){

    for(int i = 0; i<TableSize; i++){
        data[i] = -1;
        chain[i] = -1;
    }

    int n;
    printf("\nEnter Table Size: ");
    scanf("%d", &n);

    // int n = 8;

    int table[n];
    // int table[10] = {15, 5, 28, 8, 19, 25, 16, 17};

    for( int i = 0; i<n ; i++){
        printf("\nEnter Data: ");
        scanf("%d", &table[i]);
        hashTable(table[i]);
    }
    

    displayTable();
}