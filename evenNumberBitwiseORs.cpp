#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                count |= nums[i]; // Bitwise OR with even number
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {2, 3, 4, 5, 6};

    // Call the function
    int result = sol.evenNumberBitwiseORs(nums);

    // Output the result
    cout << "Bitwise OR of even numbers: " << result << endl;

    return 0;
}
