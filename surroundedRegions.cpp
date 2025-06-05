#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> que;

        // Step 1: Push all boundary 'O' cells into the queue
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') { que.push({i, 0}); }
            if (board[i][m - 1] == 'O') { que.push({i, m - 1}); }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') { que.push({0, j}); }
            if (board[n - 1][j] == 'O') { que.push({n - 1, j}); }
        }

        // Step 2: Perform BFS to mark safe 'O' cells as 'T'
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            board[x][y] = 'T';  // Temporarily mark safe 'O'

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                    que.push({nx, ny});
                }
            }
        }

        // Step 3: Convert remaining 'O' to 'X', and restore 'T' to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';  // Surrounded region converted
                if (board[i][j] == 'T') board[i][j] = 'O';  // Restore edge-connected region
            }
        }
    }
};

// Utility function to print the 2D board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:\n";
    printBoard(board);

    Solution sol;
    sol.solve(board);

    cout << "\nProcessed Board:\n";
    printBoard(board);

    return 0;
}
