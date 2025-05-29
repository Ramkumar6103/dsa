#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

class Solution {
private:
    int sumofDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            nums[i] = sumofDigit(n);
            mini = min(mini, nums[i]);
        }
        return mini;
    }
};

int main() {
    vector<int> nums = {123, 456, 789, 12};  // Example input

    Solution sol;
    int result = sol.minElement(nums);

    cout << "Minimum sum of digits among elements: " << result << endl;

    return 0;
}
