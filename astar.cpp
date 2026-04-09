#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Goal state
vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}};

// Node structure
struct Node {
    vector<vector<int>> mat;
    int x, y;       // blank tile position
    int g, h;       // cost + heuristic
    Node* parent;

    int f() const {
        return g + h;
    }
};

// Compare function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f() > b->f();
    }
};

// Heuristic: Manhattan Distance
int calculateH(vector<vector<int>> &mat) {
    int dist = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j] != 0){
                int val = mat[i][j] - 1;
                dist += abs(i - val/3) + abs(j - val%3);
            }
        }
    }
    return dist;
}

// Convert matrix to string (for visited set)
string matToString(vector<vector<int>> &mat) {
    string s="";
    for(auto &row: mat)
        for(auto &val: row)
            s += to_string(val);
    return s;
}

// Print path
void printPath(Node* node) {
    if(node == NULL) return;
    printPath(node->parent);

    for(auto &row : node->mat){
        for(auto &val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << "------" << endl;
}

// A* Algorithm
void solve(vector<vector<int>> start, int x, int y) {

    priority_queue<Node*, vector<Node*>, Compare> pq;
    set<string> visited;

    Node* root = new Node{start, x, y, 0, calculateH(start), NULL};
    pq.push(root);

    while(!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        if(current->mat == goal) {
            cout << "Solution Found:\n";
            printPath(current);
            return;
        }

        visited.insert(matToString(current->mat));

        // Possible moves
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i=0;i<4;i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if(newX>=0 && newX<3 && newY>=0 && newY<3) {
                vector<vector<int>> newMat = current->mat;
                swap(newMat[current->x][current->y], newMat[newX][newY]);

                if(visited.count(matToString(newMat)) == 0) {
                    Node* child = new Node{
                        newMat,
                        newX,
                        newY,
                        current->g + 1,
                        calculateH(newMat),
                        current
                    };
                    pq.push(child);
                }
            }
        }
    }

    cout << "No Solution Found!";
}

// Driver Code
int main() {
    vector<vector<int>> start = {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    solve(start, 1, 1); // blank at (1,1)

    return 0;
}