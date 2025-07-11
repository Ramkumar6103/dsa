#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 2, 3, 4};

    // Create an object of Solution class
    Solution sol;

    // Get the running sum
    vector<int> result = sol.runningSum(nums);

    // Display the output
    cout << "Running Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
