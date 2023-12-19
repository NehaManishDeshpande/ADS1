#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

class Graph {
    int vertices;
    int **adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void dfsMatrix(int start, bool visited[]) {
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[start][i] == 1 && !visited[i]) {
                dfsMatrix(i, visited);
            }
        }
    }

    void dfsList(int start, bool visited[]) {
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < adjList[start].size(); ++i) {
            int neighbor = adjList[start][i];
            if (!visited[neighbor]) {
                dfsList(neighbor, visited);
            }
        }
    }

    void bfsMatrix(int start) {
        bool visited[vertices];
        memset(visited, false, sizeof(visited));
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < vertices; ++i) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void bfsList(int start) {
        bool visited[vertices];
        memset(visited, false, sizeof(visited));
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < adjList[node].size(); ++i) {
                int neighbor = adjList[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices, choice, startVertex, src, dest;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    bool visitedMatrix[vertices] = {false};
    bool visitedList[vertices] = {false};

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Depth-First Search (DFS) using Matrix\n";
        cout << "3. Depth-First Search (DFS) using List\n";
        cout << "4. Breadth-First Search (BFS) using Matrix\n";
        cout << "5. Breadth-First Search (BFS) using List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices of the edge: ";
                cin >> src >> dest;
                graph.addEdge(src, dest);
                break;
            case 2:
                cout << "Enter the starting vertex for DFS using Matrix: ";
                cin >> startVertex;
                cout << "DFS using Matrix: ";
                memset(visitedMatrix, false, sizeof(visitedMatrix));
                graph.dfsMatrix(startVertex, visitedMatrix);
                break;
            case 3:
                cout << "Enter the starting vertex for DFS using List: ";
                cin >> startVertex;
                cout << "DFS using List: ";
                memset(visitedList, false, sizeof(visitedList));
                graph.dfsList(startVertex, visitedList);
                break;
            case 4:
                cout << "Enter the starting vertex for BFS using Matrix: ";
                cin >> startVertex;
                cout << "BFS using Matrix: ";
                graph.bfsMatrix(startVertex);
                break;
            case 5:
                cout << "Enter the starting vertex for BFS using List: ";
                cin >> startVertex;
                cout << "BFS using List: ";
                graph.bfsList(startVertex);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}