#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return n;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    int n = 5;
    // cout << "Enter number of stairs: ";
    // cin >> n;

    Solution solver;
    int ways = solver.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}
