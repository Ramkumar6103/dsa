#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // Edge case: Not enough elements
        int ans = abs(nums[n - 1] - nums[0]);
        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(nums[i - 1] - nums[i]));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,4};  // Sample input
    int result = sol.maxAdjacentDistance(nums);
    cout << "Maximum adjacent distance: " << result << endl;
    return 0;
}
