// Write a Program to implement Kruskal’s algorithm to find minimum
// spanning tree of a user defined graph. Use Adjacency List to represent a
// graph.


//  Krushkals algorithm

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




void main(){
	int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    init(A, n);
    create(A);
    
	kruskals(A,n);
}