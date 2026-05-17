#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define the 3 available colors
const vector<string> COLOR_NAMES = {"Green", "Red", "Yellow"};
const int NUM_COLORS = 3;

class GraphColoring {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;
    vector<int> colors; // Stores color assigned to each vertex (-1 means unassigned)

    // Check if it's safe to color vertex 'v' with color 'c'
    bool isSafe(int v, int c) {
        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] && colors[i] == c) {
                return false;
            }
        }
        return true;
    }

    // Bounding Function: Estimates the minimum remaining colors needed.
    // If current used colors + remaining estimate > NUM_COLORS, we bound (prune).
    bool underColorLimit(int current_vertex) {
        int colors_used = 0;
        vector<bool> unique_colors(NUM_COLORS, false);

        for (int i = 0; i < V; i++) {
            if (colors[i] != -1) {
                unique_colors[colors[i]] = true;
            }
        }

        for (bool used : unique_colors) {
            if (used) colors_used++;
        }

        // Simple bound: If we've already used more colors than allowed, prune.
        if (colors_used > NUM_COLORS) return false;

        return true;
    }

    // Backtracking utility function enhanced with Branch and Bound
    bool graphColoringUtil(int v) {
        // Base Case: If all vertices are assigned a color, we found a solution
        if (v == V) return true;

        // Try different colors for vertex v
        for (int c = 0; c < NUM_COLORS; c++) {
            if (isSafe(v, c)) {
                colors[v] = c;

                // Branch and Bound check: Proceed only if the current path is promising
                if (underColorLimit(v)) {
                    if (graphColoringUtil(v + 1)) {
                        return true;
                    }
                }

                // Backtrack if the assignment doesn't lead to a solution
                colors[v] = -1; 
            }
        }

        return false;
    }

public:
    GraphColoring(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        colors.resize(V, -1);
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    void solve() {
        if (!graphColoringUtil(0)) {
            cout << "No solution exists using Green, Red, and Yellow." << endl;
            return;
        }

        // Print the solution
        cout << "Graph successfully colored using the 3 colors:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " ---> " << COLOR_NAMES[colors[i]] << endl;
        }
    }
};

int main() {
    // Creating a sample graph with 4 vertices (a diamond shape with a diagonal)
    int V = 4;
    GraphColoring graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    graph.solve();

    return 0;
}