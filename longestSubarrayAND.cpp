#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;

        int maxi = *max_element(nums.begin(), nums.end());
        int maxLen = 0;
        int currLen = 0;

        for (int num : nums) {
            if (num == maxi) {
                currLen++;
            } else {
                maxLen = max(currLen, maxLen);
                currLen = 0;
            }
        }
        maxLen = max(currLen, maxLen);
        return maxLen;
    }
};

int main() {
    vector<int> nums = {1, 3, 3, 2, 3, 3, 3, 1};
    Solution sol;
    int result = sol.longestSubarray(nums);
    cout << "Length of the longest subarray with maximum value: " << result << endl;
    return 0;
}
