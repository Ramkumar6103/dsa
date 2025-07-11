#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 2, 3};

    // Create object of Solution class
    Solution sol;

    // Get the concatenated result
    vector<int> result = sol.getConcatenation(nums);

    // Display the output
    cout << "Concatenated Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
