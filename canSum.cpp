#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSum(vector<int>& nums, int targetSum) {
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= targetSum; j++) {
                // cout<<j-nums[i]<<" ";
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }

        return dp[targetSum];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 4};
    int targetSum = 2;
    cout<<sol.canSum(nums, targetSum);
    return 0;
}
