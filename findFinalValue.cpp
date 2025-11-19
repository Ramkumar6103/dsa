#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == original) {
                original = 2 * original;
            }
        }
        return original;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int result = sol.findFinalValue(nums, original);
    cout << "Final value: " << result << endl;

    return 0;
}
