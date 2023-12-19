#include <iostream>
#include <vector>
using namespace std;

class Graph{
   public:
   int size;
   vector<vector<int>> adjList;
   int *visited;
   Graph(int V): adjList(V){
    size=V;   
    visited=new int[V];
    for (int i = 0; i < V; i++)
    {
        /* code */
        visited[i]=0;
    }
    
   }
   void dfs(int source){
    visited[source]=1;
    cout << source << endl;
    for(auto it: adjList[source]){
        if(visited[it]==0){
            dfs(it);
        }
    }
   }
   void addEdge(int s,int d){
    adjList[s].push_back(d);
    adjList[d].push_back(s);

   }
};
int main(int argc, const char** argv) {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    g.dfs(0);
    return 0;
}