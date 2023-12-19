// Write a Program to implement Prim’s algorithm to find minimum
// spanning tree of a user defined graph. Use Adjacency Matrix to
// represent a graph

#include <stdio.h>
#define MAX 999


void displayPath(int parent[], int weight[], int n){
    
    int spanningCost = 0;

    for(int i = 0; i<n; i++){
        printf("\n%d -> %d (%d)", i,parent[i], weight[i]);
        spanningCost += weight[i];
    }

    printf("\nTotal Spanning Cost: %d", spanningCost);
}

int closeVertex(int visited[], int weight[], int n){
    int min = MAX, index;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && weight[i] < min){
            min = weight[i];
            index = i;
        }
    }
    return index;
}


void Prim(int G[20][20], int n, int src){
    int visited[n], weight[n], parent[n];

    for(int i = 0; i < n ;i++){
        visited[i] = 0;
        weight[i] = MAX;
        parent[i] = -1;
    }
    weight[src] = 0;

    for(int i = 0 ; i < n-1; i++){
        int u = closeVertex(visited,weight, n);
        visited[u] = 1;
        for(int j = 0; j < n; j++){
            if(visited[j] == 0 && weight[j] < G[u][j]){
                weight[j] = G[u][j];
                parent[u] = j;
            }
        }
    }

    displayPath(parent, weight, n);
}

void main(){
    int n;
    int G[n][n] ;
    printf("\nEnter total no of vertex in the Graph: ");
    scanf("%d", &n);
    int i, j;
    for(int k = 0 ;k < n; k++){
        printf("\nEnter the Vertex: ");
        scanf("%d %d", &i, &j);
        printf("\nEnter the edge for vertex %d %d: ", i, j);
        scanf("%d", &G[i][j]);
        G[j][i] = G[i][j];
        
    }

    Prim(G, n, 0);
}