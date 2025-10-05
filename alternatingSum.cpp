#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                count += nums[i];
            else
                count -= nums[i];
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {5, 3, 8, 2, 7}; // Alternating sum: 5 - 3 + 8 - 2 + 7 = 15
    
    int result = sol.alternatingSum(nums);
    
    cout << "Alternating sum: " << result << endl;
    
    return 0;
}
