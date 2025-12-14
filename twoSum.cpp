#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (indexMap.find(needed) != indexMap.end()) {
                return { indexMap[needed], i };
            }

            indexMap[nums[i]] = i;
        }

        return { -1, -1 }; // No valid pair found
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solver;
    vector<int> result = solver.twoSum(nums, target);

    cout << "Indices: " << result[0] << ", " << result[1] << "\n";
    return 0;
}
