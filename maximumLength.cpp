#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0, n = nums.size();

        int odd = 0, even = 0, alternate = 1, prev = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) odd++;
            else even++;

            if (i >= 1 && nums[i] % 2 != prev % 2) {
                alternate++;
                prev = nums[i];
            }
        }
        return max({odd, even, alternate});
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,1,1,2,1,2}; // Sample input

    int result = sol.maximumLength(nums);
    cout << "Maximum length of odd, even, or alternating parity: " << result << endl;

    return 0;
}
