#include <stdio.h>

#define MAX 9999

void BFS(int G[10][10], int v, int n) {
    int visited[10];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int queue[10];
    int head = 0, tail = 0;

    visited[v] = 1;
    queue[tail++] = v;
    while(head != tail) {
        v = queue[head++];
        printf(" %d ", v);
        for(int i = 0; i < n; i++) {
            if(G[v][i] != MAX && visited[i] == 0) {
                queue[tail++] = i;
                visited[i] = 1;
            }
        }
    }
}


void DFStraversal(int G[10][10], int u, int n) {
    int visited[10]; 
    int stack[10];
    int top = -1;

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    stack[++top] = u; // Push the starting vertex onto the stack
    visited[u] = 1;
    
    do{
        u = stack[top--];
        printf(" %d ", u);
        for(int i= 0 ; i < n; i++){
            if(G[u][i] != MAX && !visited[i]){
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    while(top != -1);
}


void main() {
/*     (5)
       0--------1
       |         \
    (2)|          \(8)
       | (5)------ 4
       |  /       /
       | /       /(3)
       2--------3
          (6)
BFS: 0 1 2 3 4
DFS: 0 1 4 3 2   ||    0 2 3 4 1   ||   0 2 4 3 1  

2nd:

    0-------1
     \     /|\
      \   / | \
       \ /  |  \
        4   2---3 
        |_______|
BFS: 0 1 2 3 4
DFS: 0 4 3 2 1
*/

    // int A[10][10] = {
    //     {0,     1, MAX, MAX,   1},
    //     {1,     0,   1,   1,   1},
    //     {MAX,   1,   0,   1, MAX},
    //     {MAX,   1,   1,   0,   1},
    //     {1,     1, MAX,   1,   0}
    // };

    int A[10][10] = {
        {MAX,     5,   2, MAX, MAX},
        {5,     MAX, MAX, MAX,   8},
        {2,     MAX, MAX,   6,   5},
        {MAX,   MAX,   6, MAX,   3},
        {MAX,     8,   5,   3, MAX}
    };

    int n = 5;
    // int n, A[10][10], e, i, j;
    // printf("\nEnter the number of vertex:");
    // scanf("%d", &n);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         A[i][j] = MAX;
    //     }
    // }
    // printf("\nEnter number of edges: ");
    // scanf("%d", &e);
    // for(int k = 0; k < e; k++){
    //     printf("\nEnter vertex number:");
    //     scanf("%d %d", &i, &j);
    //     printf("\nEnter Weight between %d and  %d: ", i, j);
    //     scanf("%d", &A[i][j]);
    //     A[i][j] = A[j][i];
    // }

    printf("BFS Traversal: ");
    BFS(A, 0, n);

    printf("\nDFS Traversal: ");
    DFStraversal(A, 0, n);

}
