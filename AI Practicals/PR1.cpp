#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Graph {
public:
    map<int, vector<int>> adj;

    // Adds an edge to an undirected graph      ...cd "AI Practicals"         g++ PR1.cpp -o PR1            .\PR1
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Recursive: Uses the system stack to explore deep branches
    void dfsRecursive(int node, set<int>& visited) {
        visited.insert(node);
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // BFS: Uses a queue to explore level by level
    void bfs(int startNode) {
        set<int> visited;
        queue<int> q;

        visited.insert(startNode);
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    // Defining graph edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS Recursive (Starting from 0): ";
    set<int> visited;
    g.dfsRecursive(0, visited);
    cout << endl;

    cout << "BFS (Starting from 0): ";
    g.bfs(0);
    cout << endl;

    return 0;
}
