#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adjList;
    int **adjMatrix;
    int *visited;

public:
    Graph(int V) : adjList(V) {
        size = V;
        visited = new int[V];

        // Initialize visited array
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }

        // Initialize adjacency matrix
        adjMatrix = new int *[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    void addEdge(int s, int d) {
        adjList[s].push_back(d);
        adjList[d].push_back(s);

        // Update adjacency matrix
        adjMatrix[s][d] = 1;
        adjMatrix[d][s] = 1;
    }

    void printAdjList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " -> ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int source) {
        visited[source] = 1;
        cout << source << " ";

        for (auto it : adjList[source]) {
            if (visited[it] == 0) {
                dfs(it);
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < size; i++) {
            visited[i] = 0;
        }
    }
};

int main() {
    int choice, source, dest, vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Print Adjacency List\n";
        cout << "3. Print Adjacency Matrix\n";
        cout << "4. Perform DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices: ";
                cin >> source >> dest;
                g.addEdge(source, dest);
                break;
            case 2:
                g.printAdjList();
                break;
            case 3:
                g.printAdjMatrix();
                break;
            case 4:
                cout << "Enter the starting vertex for DFS: ";
                cin >> source;
                cout << "DFS Traversal: ";
                g.resetVisited();
                g.dfs(source);
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
