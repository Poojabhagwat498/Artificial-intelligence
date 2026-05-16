#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges by weight (The "Greedy" choice)
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// DSU Class to manage connected components and detect cycles
class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    // 1. Sort edges greedily by weight
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;

    cout << "Edges in the Minimum Spanning Tree:" << endl;

    for (Edge& e : edges) {
        // 2. If adding the edge doesn't form a cycle, include it
        if (dsu.find(e.src) != dsu.find(e.dest)) {
            dsu.unite(e.src, e.dest);
            mst.push_back(e);
            totalWeight += e.weight;
            cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
        }
    }
    cout << "Total Minimum Weight: " << totalWeight << endl;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(V, edges);

    return 0;
}
