#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (mpp.find(nums[i]) != mpp.end() && (i - mpp[nums[i]]) <= k) {
                return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution solution;
    if (solution.containsNearbyDuplicate(nums, k)) {
        cout << "Contains nearby duplicate" << endl;
    } else {
        cout << "No nearby duplicate" << endl;
    }

    return 0;
}
