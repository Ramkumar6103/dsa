#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Test case: Example input
    nums = {1, 2, 3, 4, 5}; // Modify this to test different arrays
    if (solution.isArraySpecial(nums)) {
        cout << "The array is special." << endl;
    } else {
        cout << "The array is not special." << endl;
    }

    return 0;
}
