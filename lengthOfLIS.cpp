#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxLength = 0;

    //     for (int i = 0; i < n; i++) {
    //         vector<int> temp;
    //         temp.push_back(nums[i]);

    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[j] > temp.back()) {
    //                 temp.push_back(nums[j]);
    //             } else {
    //                 // Find the first element >= nums[j] and replace it
    //                 auto it = lower_bound(temp.begin(), temp.end(), nums[j]);
    //                 *it = nums[j];
    //             }
    //         }

    //         maxLength = max(maxLength, static_cast<int>(temp.size()));
    //     }

    //     return maxLength;
    // }

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = length of LIS ending at i
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;
    return 0;
}
