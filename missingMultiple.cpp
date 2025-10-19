#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int x = k;  
        for (auto i : nums) {
            if (i == x) x += k;
        }
        return x;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {3, 6, 9, 15}; // multiples of 3, missing 12
    int k = 3;

    int result = sol.missingMultiple(nums, k);
    cout << "The smallest missing multiple of " << k << " is: " << result << endl;

    return 0;
}
