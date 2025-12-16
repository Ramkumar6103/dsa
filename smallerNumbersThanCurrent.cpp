#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> valueToIndex;
        vector<int> sortedNums = nums;
        int n = nums.size();

        // Sort the copy
        sort(sortedNums.begin(), sortedNums.end());

        // Store the first occurrence index of each value
        for (int i = n - 1; i >= 0; i--) {
            valueToIndex[sortedNums[i]] = i;
        }

        // Replace each number with its count of smaller numbers
        for (int i = 0; i < n; i++) {
            nums[i] = valueToIndex[nums[i]];
        }

        return nums;
    }
};

int main() {
    Solution solver;

    vector<int> nums = {8, 1, 2, 2, 3};

    vector<int> result = solver.smallerNumbersThanCurrent(nums);

    cout << "Output: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
