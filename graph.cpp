#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;     
    // Number of vertices
    list<int>* adj;         // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Add edge (undirected)
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // ================= DFS (Recursive) =================
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (auto i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // ================= BFS (Queue) =================
    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;

        visited[start] = true;
        queue.push_back(start);

        cout << "BFS Traversal: ";

        while (!queue.empty()) {
            int v = queue.front();
            cout << v << " ";
            queue.pop_front();

            for (auto i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
        cout << endl;
    }
};

// ================= DRIVER CODE =================
int main() {
    Graph g(6);  // 6 vertices: 0 to 5

    // Add edges (undirected)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Run DFS and BFS
    g.DFS(0);
    g.BFS(0);

    return 0;
}