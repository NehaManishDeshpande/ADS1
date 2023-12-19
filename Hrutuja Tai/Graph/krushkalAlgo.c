//  Krushkals algorithm

#include<stdio.h>
#define MAX 999

int findParent(int i,int parent[]){
    while(parent[i]!=-1){
        i=parent[i];        
    }
    return i;
}

int ancestor(int u,int v,int parent[]){
    if(u!=v){
        parent[v]=u;
        return 1;
    }
    return 0;
    
}

void kruskals(int A[10][10],int n){
    int weight=0;
    int parent[n];
    for(int u = 0; u<n; u++){
        parent[u] = -1;
    }
    int ne=0,i,j, k= 0;
    int a,b,u,v,min;
    while(ne<n){
        
        min=MAX;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(A[i][j]<min){
                    min=A[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=findParent(u,parent);
        v=findParent(v,parent);
        int x=ancestor(a,b,parent);
        
        if(x){
            printf("%d: Edge:(%d - %d): %d \n",k++,a, b, min);
            weight+=min;
        }
        A[a][b]=A[b][a]=9999;
        ne++;
    }

    printf("\nParent List: ");
    for(i=0;i<n;i++){
            printf("%d  ",parent[i]);
    }

    printf("\nOverall Weight: %d", weight);
}

void main(){
    int n=5;
    int Adj[10][10] = {
        {MAX,   5,   2, MAX, MAX},
        {5,   MAX, MAX, MAX,   8},
        {2,   MAX, MAX,   6,   5},
        {MAX, MAX,   6, MAX,   3},
        {MAX,   8,   5,   3, MAX}
    };

    // int Adj[10][10] = {
    //     {MAX,   3,   2, MAX, MAX, MAX, MAX},
    //     {3,   MAX,   9,   2, MAX,   4, MAX},
    //     {2,     9, MAX, MAX,   8, MAX, MAX},
    //     {MAX,   2, MAX, MAX,   5,   2,   8},
    //     {MAX, MAX,   8,   5, MAX, MAX,   7},
    //     {MAX,   5, MAX,   2, MAX, MAX,   6},
    //     {MAX, MAX, MAX,   8,   7,   6, MAX}
    // };

    // int n = 7;

    
    kruskals(Adj,n);
}
