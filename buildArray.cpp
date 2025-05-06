#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0, 2, 1, 5, 3, 4}; // Default example

    Solution sol;
    vector<int> result = sol.buildArray(nums);

    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
