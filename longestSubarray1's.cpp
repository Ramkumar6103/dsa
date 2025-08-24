#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, zeroCount = 0, maxLen = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left);
            right++;
        }
        return maxLen;
    }
    // int longestSubarray(vector<int>& nums) {
    //     int maxCount = 0;
    //     int zero = 0;
    //     int l = 0;
    //     int n = nums.size();
    //     int r = l;
    //     int cnt = 0;

    //     while (l < n) {
    //         while (r < n && zero <= 1) {
    //             if (nums[r] == 0 && zero == 0) {
    //                 zero++;
    //             } else if (zero == 1 && nums[r] == 0) {
    //                 break;
    //             }
    //             cnt++;
    //             r++;
    //         }
    //         cnt--; // because we must delete one element
    //         maxCount = max(cnt, maxCount);
    //         l++;
    //         r = l;
    //         cnt = 0;
    //         zero = 0;
    //     }
    //     return maxCount;
    // }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};

    // Output the result
    int result = sol.longestSubarray(nums);
    cout << "Longest subarray after deleting one element: " << result << endl;

    return 0;
}
