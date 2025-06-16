#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mini) {
                ans = max(ans, nums[i] - mini);
            } else {
                mini = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {7, 1, 5, 4}; // Example input
    Solution sol;
    int result = sol.maximumDifference(nums);

    cout << "Maximum Difference: " << result << endl;
    return 0;
}
