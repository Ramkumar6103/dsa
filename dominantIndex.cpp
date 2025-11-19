#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = INT_MIN;
        int maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (m < nums[i]) {
                maxi = i;
                m = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != maxi && nums[i] * 2 > m) {
                return -1;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 6, 1, 0};

    int result = sol.dominantIndex(nums);
    if (result != -1) {
        cout << "Dominant index: " << result << endl;
        cout << "Dominant value: " << nums[result] << endl;
    } else {
        cout << "No dominant index found." << endl;
    }

    return 0;
}
