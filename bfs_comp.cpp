#include <iostream>
#include <vector>
#include <queue>
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

    void bfs(int source) {
        visited[source] = 1;
        queue<int> q;
        q.push(source);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (auto it : adjList[current]) {
                if (visited[it] == 0) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        cout << endl;
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
        cout << "3. Perform BFS Traversal\n";
        cout << "4. Exit\n";
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
                cout << "Enter the starting vertex for BFS: ";
                cin >> source;
                g.resetVisited();
                g.bfs(source);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
