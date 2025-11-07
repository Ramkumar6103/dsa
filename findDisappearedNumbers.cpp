#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            int m = abs(nums[i]) - 1; // index starts from 0
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
