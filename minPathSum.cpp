#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Tabulation technique
    int minPathSum(vector<vector<int>>& grid) { 
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        // Base case
        dp[0][0] = grid[0][0];

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i == 0 && j == 0) continue;

                int top = (i - 1 >= 0) ? dp[i - 1][j] : INT_MAX;
                int left = (j - 1 >= 0) ? dp[i][j - 1] : INT_MAX;

                int best = min(top, left);
                dp[i][j] = grid[i][j] + best;
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = sol.minPathSum(grid);

    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}
