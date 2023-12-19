#include <stdio.h>
#include <stdlib.h>

// Node to represent an edge in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure with an array of adjacency lists
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'V' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Allocate memory for an array of adjacency lists
    graph->adjacencyList = (struct Node*)malloc(vertices * sizeof(struct Node));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from destination to source as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d: ", i);

        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

// Driver program for testing
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}