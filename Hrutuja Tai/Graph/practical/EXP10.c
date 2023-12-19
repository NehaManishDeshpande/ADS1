// Write a Program to implement Dijkstra’s algorithm to find shortest
// distance between two nodes of a user defined graph. Use Adjacency List
// to represent a graph.

#include <stdio.h>
#include <malloc.h>
#define MAX 999

typedef struct Graph{
    int vertex, weight;
    struct Graph *next;
}graph;

graph *G[10];

int closeVertex(int distance[], int visited[], int v){
    int min= MAX, index = -1;
    for(int i = 0; i < v; i++){
        if(visited[i]== 0 && distance[i] < min){
            min = distance[i];
            index = i;
        }
    }
    return index;
}


void dijkstra(graph *G[], int n, int src){
    int distance[20], visited[20];
    for(int i = 0; i< n ; i++){
        distance[i] = MAX;
        visited[i] = 0;
    }
    distance[src] = 0;
    for(int i = 0; i < n-1; i++){
        int u = closeVertex(distance, visited, n);
        visited[u] = 1;
        graph *p = G[u];

        while(p != NULL){
            if(visited[p->vertex] != 1  && distance[u] + p->weight < distance[p->vertex]){
                distance[p->vertex] = distance[u] + p->weight;
            }
            p = p->next;
        }
    }

    printf("\nSrc: %d", src);
    printf("\nDistance from Source:");
    for(int i = 0; i<n; i++){
        printf("\n%d : %d", i, distance[i] );
    }
}

void init(graph *G[], int n){
    for(int i = 0; i < n ; i++){
        G[i] = NULL;
    }
}

void insertGraph(graph *G[]){
    int i, j, w;
    graph *p;
    char ch;
    
    do{
        printf("\nEnter Vertexes : ");
        scanf("%d %d", &i, &j);
        printf("\nEnter the weight between the vertex %d & %d: ", i,j);
        scanf("%d", &w);
        getchar();

        graph *new = (graph*)malloc(sizeof(graph*));
        new->vertex = j;
        new->weight = w;
        new->next = NULL;
        
        p = G[i];
        if(p == NULL){
            G[i] = new;
        }
        else{
            while(p->next != NULL){
                p = p->next;
            }
            p->next = new;
        }

        printf("\nEnter more vertexes: y / n: ");    
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');

}


void main(){
    int n;
    printf("\nEnter total number of vertexes : ");
    scanf("%d", &n);

    init(G, n);
    insertGraph(G);

    dijkstra(G, n, 0);
}