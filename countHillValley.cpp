#include <iostream>
#include <vector>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int count = 0;
        int left = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    ++count;
                }
                left = i;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example test case
    std::vector<int> nums = {2, 4, 1, 1, 6, 5};
    int result = sol.countHillValley(nums);

    std::cout << "Number of hills and valleys: " << result << std::endl;
    return 0;
}
