#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, streak = 0;
        for (int num : nums) {
            if (num == 0) {
                streak++;
                cnt += streak;
            } else {
                streak = 0;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {0, 0, 0, 2, 0, 0};

    // Call the function and print the result
    long long result = sol.zeroFilledSubarray(nums);
    cout << "Number of zero-filled subarrays: " << result << endl;

    return 0;
}
