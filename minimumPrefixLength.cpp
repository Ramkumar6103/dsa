#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] <= nums[i - 1]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,2,5};
    int result = sol.minimumPrefixLength(nums);
    cout << "Minimum Prefix Length: " << result << endl;

    return 0;
}
