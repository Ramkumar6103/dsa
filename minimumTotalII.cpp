#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // DP table
        vector<vector<int>> dp = triangle;

        // Start from 2nd row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    // Left edge
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j == i) {
                    // Right edge
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else {
                    // Middle
                    dp[i][j] = triangle[i][j] + 
                               min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }

        // Answer is min in last row
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Minimum Path Sum: " 
         << sol.minimumTotal(triangle) << endl;

    return 0;
}
