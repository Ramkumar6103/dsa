#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> howSum(vector<int>& nums, int targetSum) {
        // dp[i] will store one combination that sums to i
        vector<vector<int>> dp(targetSum + 1);
        vector<bool> can(targetSum + 1, false);

        can[0] = true; // base case

        for (int i = 0; i <= targetSum; i++) {
            if (can[i]) {
                for (int num : nums) {
                    if (i + num <= targetSum) {
                        can[i + num] = true;
                        dp[i + num] = dp[i];
                        dp[i + num].push_back(num);
                    }
                }
            }
        }

        if (can[targetSum])
            return dp[targetSum];

        return {}; // no solution
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 4};
    int targetSum = 7;

    vector<int> ans = sol.howSum(nums, targetSum);

    if (ans.empty()) {
        cout << "No combination found";
    } else {
        for (int x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}
