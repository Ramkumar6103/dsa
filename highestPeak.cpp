#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> que;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1)); // -1 for unvisited
        
        // Push all water cells first
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) { // Water cells
                    que.push({i, j});
                    vis[i][j] = 0; // Water cells have height 0
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop(); // Properly pop the queue
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && vis[nx][ny] == -1) {
                    vis[nx][ny] = vis[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
        return vis;
    }
};

// Utility function to print the 2D vector
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> isWater = {
        {0, 1},
        {0, 0}
    };

    Solution sol;
    vector<vector<int>> result = sol.highestPeak(isWater);

    cout << "Resultant Grid:\n";
    printGrid(result);

    return 0;
}
