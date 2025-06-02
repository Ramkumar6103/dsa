#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<int,int>> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                    que.push({i,j});
                }
            }
        }
        // up, right, down, left
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!que.empty()){
            auto [x,y] = que.front();
            que.pop();
            for(auto [dx,dy] : directions){
                int nx = dx + x;
                int ny = dy + y;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == -1){
                    dis[nx][ny] = dis[x][y] + 1;
                    que.push({nx,ny});
                }
            }
        }
        return dis;
    }
};

// Main function to test the solution
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1},
        {1, 1, 1},
        {1, 1, 0}
    };

    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);

    // Print the result
    cout << "Updated Matrix:" << endl;
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
