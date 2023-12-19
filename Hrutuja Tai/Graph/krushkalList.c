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

void kruskals(graph *A[],int n){
    int weight=0;
	int parent[n];
    graph *p;
    for(int u = 0; u<n; u++){
        parent[u] = -1;
    }
	int ne=0,i,j, k= 0, y=0;
	int a,b,u,v,min;
	while(ne < n){
		min=MAX;
		for(i=0; i<n; i++){
            p = A[i];
			while(p!=NULL){
				if(p->weight < min){
					min = p->weight;
					a = u = i;
					b = v = p->vertex;
				}
                p = p->next;
			}
		}

		u=findParent(u,parent);
		v=findParent(v,parent);
		int x=ancestor(a,b,parent);
		
		if(x){
			printf("%d: Edge:(%d - %d): %d \n",k++,a, b, min);
            weight+=min;
		}
		graph *r, *s;
        r = A[a];
        s = A[b];
        while(r->vertex != b){
            r = r->next;
        }
        while(s->vertex != a){
            s =s->next;
        }
        r->weight = s->weight = MAX;
		ne++;
	}

    printf("\nParent List: ");
    for(i=0;i<n;i++){
			printf("%d  ",parent[i]);
	}

    printf("\nOverall Weight: %d", weight);
}

void main(){
	int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    init(A, n);
    create(A);

    
	kruskals(A,n);
}