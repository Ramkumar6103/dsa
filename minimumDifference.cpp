#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = nums[k - 1] - nums[0];
        for (int i = 1; i <= n - k; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hard-coded input
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;

    int result = sol.minimumDifference(nums, k);
    cout << "Minimum Difference: " << result << endl;

    return 0;
}
