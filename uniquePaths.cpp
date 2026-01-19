#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    // Base case: First row and first column = 1 way
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;

    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m = 3;
    int n = 2;

    cout << "Number of unique paths: " << uniquePaths(m, n);

    return 0;
}
