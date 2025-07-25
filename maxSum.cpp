#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        bool neg = true;
        int maxEle = INT_MIN;
        for (int n : nums) {
            if (n > 0) neg = false;
            maxEle = max(maxEle, n);
        }
        if (neg) return maxEle;
        int ans = 0;
        for (int un : unique) {
            if (un > 0) ans += un;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 2, 1};
    cout << "Max Sum of unique positive elements (Example 1): " << sol.maxSum(nums1) << endl;

    // Example 2 (all negatives)
    vector<int> nums2 = {-1, -2, -3};
    cout << "Max element (all negative case - Example 2): " << sol.maxSum(nums2) << endl;

    // Example 3 (mixed values)
    vector<int> nums3 = {5, -2, 5, 7, -3, 7};
    cout << "Max Sum of unique positive elements (Example 3): " << sol.maxSum(nums3) << endl;

    return 0;
}
