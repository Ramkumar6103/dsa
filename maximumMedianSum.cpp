#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        int l = 0;
        int r = n - 2;
        while (l < r) {
            res.push_back(nums[r]);
            l++;
            r -= 2;
        }
        for (int i : res) {
            ans += i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 3, 2, 6, 4};
    long long result = sol.maximumMedianSum(nums);
    cout << "Maximum Median Sum: " << result << endl;
    return 0;
}
