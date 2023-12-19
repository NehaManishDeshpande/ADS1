//dijkstra's algorithm (DIrected Graph)
#include<stdio.h>
#define MAX 999

int closeVertex(int weight[], int visited[], int v){
    int min = MAX, i, index;
    for(i = 0; i < v; i++){
        if(visited[i] == 0 && weight[i] <= min){
            min = weight[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int G[10][10], int src, int v){
    int visited[10], distance[10];
    for(int i = 0; i < v; i++){
        visited[i] = 0;
        distance[i] = MAX;
    }
    distance[src] = 0;
    for(int i = 0; i < v-1; i++){

        int u = closeVertex(distance, visited, v);
        visited[u] = 1;

        for(int j = 0; j< v; j++){

            if(visited[j] != 1 && G[u][j] && distance[u] != MAX && G[u][j] + distance[u] < distance[j]){
                distance[j] = G[u][j] + distance[u];
            }
        }
    }
    for(int k = 0; k < v; k++){
        printf("\n%d = %d",k, distance[k]);
    }
}

int main(){
    // int A[10][10] = {
    //     {MAX,     3,   2, MAX, MAX, MAX, MAX},
    //     {3,     MAX,   9,   2, MAX,   4, MAX},
    //     {2,       9, MAX, MAX,   8, MAX, MAX},
    //     {MAX,     2, MAX, MAX,   5,   2,   8},
    //     {MAX,   MAX,   8,   5, MAX, MAX,   7},
    //     {MAX,     5, MAX,   2, MAX, MAX,   6},
    //     {MAX,   MAX, MAX,   8,   7,   6, MAX}
    // };

    // int n = 7;
    
    // int A[10][10] = {
    //     {MAX,     5,   2, MAX, MAX},
    //     {5,     MAX, MAX, MAX,   8},
    //     {2,     MAX, MAX,   6,   5},
    //     {MAX,   MAX,   6, MAX,   3},
    //     {MAX,     8,   5,   3, MAX}
    // };
    // int n = 5;

    int A[10][10] = {
        {MAX,     4,   2, MAX, MAX},
        {MAX,   MAX, MAX,   1, MAX},
        {MAX,     1, MAX,   4,   2},
        {MAX,   MAX, MAX, MAX,   1},
        {MAX,   MAX, MAX, MAX, MAX}
    };
    int n = 5;

    // int A[10][10] = {   { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    // int n = 9;
    Dijkstra(A, 0, n);
}