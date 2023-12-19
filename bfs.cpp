#include <iostream>
#include <vector>

using namespace std;

class Queue {
public:
    int *queue;
    int front;
    int rear;
    int capacity;

    Queue(int n) {
        capacity = n;
        queue = new int[n];
        front = -1;
        rear = -1;
    }

    int enqueue(int n) {
        if (rear == capacity - 1) {
            return -1;
        }
        if (front == -1) {
            front++;
        }
        queue[++rear] = n;
        return 1;  // Return 1 to indicate successful enqueue
    }

    int dequeue() {
        if (front == -1) {
            return -1;
        }
        int n = queue[front++];
        return n;
    }

    int isEmpty() {
        return front == -1;
    }
};

class Graph {
public:
    int V;
    vector<vector<int>> adjList;
    int* visited;

    Graph(int V) : adjList(V) {
        this->V = V;

        visited = new int[V];
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }
    }

    void addEdge(int s, int d) {
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }

    void BFS(int source) {
        visited[source] = 1;
        //Queue q(V);
        int queue[V];
        int front, rear;
        front=rear=0;
        queue[rear++]=source;
        //q.enqueue(source);

        while (front!=rear) {
            int n = queue[front++];
            cout << n << endl;

            for (auto it : adjList[n]) {
                if (visited[it] == 0) {
                    visited[it] = 1;
                    queue[rear++]=it;
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.BFS(0);

    return 0;
}