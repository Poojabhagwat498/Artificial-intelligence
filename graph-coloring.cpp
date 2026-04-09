#include <iostream>
using namespace std;

#define V 4   // Number of vertices

// Function to check if it's safe to assign color
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool solveGraphColoring(int graph[V][V], int m, int color[], int v) {

    // If all vertices are assigned
    if (v == V)
        return true;

    // Try all colors
    for (int c = 1; c <= m; c++) {

        // Branch & Bound (constraint check)
        if (isSafe(v, graph, color, c)) {

            color[v] = c;  // assign color

            // Recur
            if (solveGraphColoring(graph, m, color, v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }

    return false;
}

// Print solution
void printSolution(int color[]) {
    cout << "Vertex : Color\n";
    for (int i = 0; i < V; i++) {
        cout << "  " << i << "    :   " << color[i] << endl;
    }
}

// Driver Code
int main() {

    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    int color[V] = {0};

    if (solveGraphColoring(graph, m, color, 0)) {
        printSolution(color);
    } else {
        cout << "No solution exists!";
    }

    return 0;
}