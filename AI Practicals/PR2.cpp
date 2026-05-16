#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    double g, h, f;
    Node* parent;

    Node(int x, int y, double g = 0, double h = 0, Node* p = nullptr) 
        : x(x), y(y), g(g), h(h), f(g + h), parent(p) {}
};

// Comparator for the priority queue (Min-heap based on f-cost)
struct CompareF {
    bool operator()(Node* a, Node* b) { return a->f > b->f; }
};

// Heuristic: Manhattan Distance
double heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Node*, vector<Node*>, CompareF> openList;
    vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

    openList.push(new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second)));

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->x == goal.first && current->y == goal.second) {
            cout << "Path found: ";
            while (current) {
                cout << "(" << current->x << "," << current->y << ") ";
                current = current->parent;
            }
            return;
        }

        closedList[current->x][current->y] = true;

        // Directions: Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0 && !closedList[nx][ny]) {
                double gNew = current->g + 1;
                double hNew = heuristic(nx, ny, goal.first, goal.second);
                openList.push(new Node(nx, ny, gNew, hNew, current));
            }
        }
    }
    cout << "No path found." << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };
    aStar(grid, {0, 0}, {3, 2});
    return 0;
}
