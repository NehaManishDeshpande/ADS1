//minimum spanning tree 
//prim's algorithm

#include<stdio.h>
#define MAX 999

int closeVertex(int weight[], int visited[], int v){
    int min = MAX, i, index;
    for(i = 0; i < v; i++){
        if(visited[i] == 0 && weight[i] < min){
            min = weight[i];
            index = i;
        }
    }
    return index;
}

void displayMST(int parent[], int weight[], int v){
    for(int i = 0; i < v; i++){
        printf("\n%d = Parent: %d & Weight: %d", i, parent[i], weight[i]);
    }
}


void primAlgo(int G[10][10], int v){
    int i, j, parent[v], visited[v], weight[v];
    for(i = 0; i < v; i++){
        visited[i] = 0;
        weight[i] = MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(i = 0; i < v-1; i++){
        int u  = closeVertex(weight, visited, v);
        visited[u] = 1;
        for(j = 0; j < v; j++){
            if(visited[j] == 0 && weight[j] > G[u][j]){
                weight[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    displayMST(parent,weight, v);
}

int main(){
/*      (3)      (5)
     0--------1------5----------
     |       /|     /          |(6)
 (2) |      / |    /(2)        |
     |  (9)/  |(2)/       (7)__6
     |    /   |  /          /  |
     |   /    | /   (5)    /   |(8)
     2---     3-----------4    |
     |___(8)__|___________|    |
              |________________|
*/
    int A[10][10] = {
        {MAX,     3,   2, MAX, MAX, MAX, MAX},
        {3,     MAX,   9,   2, MAX,   4, MAX},
        {2,       9, MAX, MAX,   8, MAX, MAX},
        {MAX,     2, MAX, MAX,   5,   2,   8},
        {MAX,   MAX,   8,   5, MAX, MAX,   7},
        {MAX,     5, MAX,   2, MAX, MAX,   6},
        {MAX,   MAX, MAX,   8,   7,   6, MAX}
    };

    int n = 7;
    
    // int A[10][10] = {
    //     {MAX,     5,   2, MAX, MAX},
    //     {5,     MAX, MAX, MAX,   8},
    //     {2,     MAX, MAX,   6,   5},
    //     {MAX,   MAX,   6, MAX,   3},
    //     {MAX,     8,   5,   3, MAX}
    // };

    // int n = 5;
    primAlgo(A, n);
}