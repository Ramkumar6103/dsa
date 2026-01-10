#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

int main() {
    Solution sol;

    int amount = 11;

    vector<int> coins = {1,2,5};

    int result = sol.coinChange(coins, amount);

    if (result == -1)
        cout << "Not possible to make the amount with given coins." << endl;
    else
        cout << "Minimum coins required: " << result << endl;

    return 0;
}
