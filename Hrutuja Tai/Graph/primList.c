//prims algorithmusing adjacency list

//minimum spanning tree 
//prim's algorithm

#include<stdio.h>
#include<malloc.h>
#define MAX 999

typedef struct graph{
    int vertex, weight;
    struct graph *next;
}graph;

graph *A[10];

void init(graph *A[], int n){
    int i;
    for(i = 0; i<n; i++){
        A[i] = NULL;
    }
}

void create(graph *A[]){
    int v1, v2, weight;
    graph* p;
    char ch;

    do {
        printf("\nEnter the edge: ");
        scanf("%d %d", &v1, &v2);

        printf("\nEnter the weight %d %d: ", v1, v2);
        scanf("%d", &weight);

        graph* new_node = (graph*)malloc(sizeof(graph));
        new_node->vertex = v2;
        new_node->weight = weight;
        new_node->next = NULL;

        p = A[v1];
        if (p == NULL) {
            A[v1] = new_node;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new_node;
        }

        new_node = (graph*)malloc(sizeof(graph));
        new_node->vertex = v1;
        new_node->weight = weight;
        new_node->next = NULL;

        p = A[v2];
        if (p == NULL) {
            A[v2] = new_node;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new_node;
        }

        printf("\nMore Edges (Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
}


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



void primAlgo(graph *A[], int v){
    int i, j, parent[v], visited[v], weight[v];
    graph *p;
    for(i = 0; i < v; i++){
        parent[i] = -1;
        visited[i] = 0;
        weight[i] = MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(i = 0; i < v-1; i++){
        int u = closeVertex(weight, visited, v);
        p = A[u];
        visited[u] = 1;
        while(p!= NULL){
            if(visited[p->vertex] == 0 && weight[p->vertex] > p->weight){
                weight[p->vertex] = p->weight;
                parent[p->vertex] = u;
            }
            p = p->next;
        }
    }

    displayMST(parent,weight, v);
}

int main(){
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    init(A, n);
    create(A);

    primAlgo(A, n);
}