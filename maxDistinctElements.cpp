#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, prev = -1e9;

        for (int i = 0; i < nums.size(); i++) {
            int l = max(nums[i] - k, prev + 1);
            if (l <= nums[i] + k) {
                prev = l;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 3, 6, 10};
    int k = 2;

    int result = sol.maxDistinctElements(nums, k);
    cout << "Maximum number of distinct elements: " << result << endl;

    return 0;
}
