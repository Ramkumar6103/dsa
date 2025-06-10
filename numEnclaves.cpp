#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> que;

        // Push all boundary land cells into queue and mark as visited
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                que.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1) {
                que.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                que.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1) {
                que.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        // BFS from boundary cells
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                   grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }

        // Count all unvisited land cells
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

// ----------- MAIN FUNCTION FOR TESTING ----------
int main() {
    Solution sol;

    // Example grid input
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of Enclaves: " << result << endl;

    return 0;
}
