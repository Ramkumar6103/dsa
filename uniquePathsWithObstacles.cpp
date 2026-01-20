#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1));

        // If start or end is blocked
        if (Grid[0][0] == 1 || Grid[n-1][m-1] == 1) 
            return 0;

        dp[0][0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(Grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){
                    continue;
                }
                else{
                    int top = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = top + left; 
                }
            }
        }
        return dp[n-1][m-1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of unique paths: "
         << sol.uniquePathsWithObstacles(grid) << endl;

    return 0;
}
