      #include <iostream>
#include <vector>

using namespace std;

class NQueens {
    int n;
    vector<int> board; // board[row] = col stores the column position for each row

public:
    NQueens(int size) : n(size), board(size, -1) {}

    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            int prevCol = board[i];
            // Check column and both diagonals
            if (prevCol == col || abs(prevCol - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function
    bool solve(int row) {
        // Base case: All queens are placed
        if (row == n) return true;

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row] = col; // Place queen

                // Recur to place the rest
                if (solve(row + 1)) return true;

                // Backtrack: remove queen (implicitly handled by overwriting)
                board[row] = -1;
            }
        }
        return false;
    }

    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) cout << " Q ";
                else cout << " . ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4; // Change this for a larger board
    NQueens game(n);

    if (game.solve(0)) {
        cout << "Solution for " << n << "-Queens:" << endl;
        game.printBoard();
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
