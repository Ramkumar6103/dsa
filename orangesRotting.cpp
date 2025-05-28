#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> que;
        //vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    que.push({{i,j},0});
                    //vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!que.empty()){
            int r = que.front().first.first;
            int c = que.front().first.second;
            int t = que.front().second;
            que.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                    que.push({{nrow,ncol},t+1});
                    grid[nrow][ncol] = 2;
                } 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return tm;
    }
};

// Main function to test the solution
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);
    
    cout << "Time taken to rot all oranges: " << result << endl;
    
    return 0;
}
