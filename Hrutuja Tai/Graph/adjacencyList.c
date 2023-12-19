//create graph and traverse it through adjacency list

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

void printGraph(graph*A[], int n){
    for(int i=0; i<n; i++){
        printf("\nAdjacency list of vertex %d ", i);
        graph *ptr = A[i];
        while(ptr != NULL){
            printf("-> %d(%d) ",ptr->vertex, ptr->weight);
            ptr = ptr->next;
        }
    }
}

void BFS(graph *A[], int v, int n){
    graph *p;

    int queue[n];
    int head = 0, tail = 0;

    int visited[n];
    for(int i= 0; i < n; i++){
        visited[i]=0; // corrected from visited[0]=0
    }
    visited[v] = 1;

    queue[tail++] = v;             //enqueing

    p = A[v];
    while(head != tail){
        v = queue[head++];         //dequeueing
        printf(" %d ", v);
        p = A[v];
        while(p != NULL){
            if(visited[p->vertex] == 0){
                queue[tail++] = p->vertex;
                visited[p->vertex] = 1;
            }
            p = p->next;
        }
    }
}

void DFS(graph* A[], int v, int n) {
    graph* p;
    int stack[n];
    int top = -1;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    stack[++top] = v;
    visited[v] = 1;
    printf(" %d ", v);
    do {
        p = A[v];
        while (p != NULL) {
            if (visited[p->vertex] == 0) {
                stack[++top] = p->vertex;
                printf(" %d ", p->vertex);
                visited[p->vertex] = 1;
                v = p->vertex;
                break;
            } else {
                p = p->next;
            }
        }
        if (p == NULL) {
            if (top != -1) {
                v = stack[top--];
            }
        }
    } while (top != -1);
}


void main(){
/*     (5)
    0--------1
    |         \
 (2)|          \(8)
    | (5)------ 4
    |  /       /
    | /       /(3)
    2--------3
       (6)

BFS: 0 1 2 4 3 ||  0 2 1 3 4
DFS: 0 1 4 3 2 ||  0 2 3 4 1
*/
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    init(A, n);
    create(A);

    printGraph(A,n);
    printf("\nBFS Traversal: ");
    BFS(A, 0, n);
    printf("\nDFS Traversal: ");
    DFS(A, 0, n);
}