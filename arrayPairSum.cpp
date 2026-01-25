#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hard-coded input
    vector<int> nums = {1, 4, 3, 2};

    int result = sol.arrayPairSum(nums);
    cout << "Maximum Sum of Min Pairs: " << result << endl;

    return 0;
}
