#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();

    // If only one house
    if (n == 1)
        return nums[0];

    // DP array
    vector<int> dp(n);

    // Base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // Fill dp array
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    // Last element has the answer
    return dp[n - 1];
}

int main() {
    // Hardcoded input
    vector<int> nums = {2, 7, 9, 3, 1};

    int result = rob(nums);

    cout << "Maximum money that can be robbed: " << result << endl;

    return 0;
}
