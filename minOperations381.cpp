#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                s.insert(nums[i]);
            }
        }

        return s.size();
    }
};

int main() {
    // Hardcoded input
    vector<int> nums   = {1, 2, 3, 4, 5};
    vector<int> target = {1, 3, 3, 2, 5};

    Solution sol;
    int result = sol.minOperations(nums, target);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
