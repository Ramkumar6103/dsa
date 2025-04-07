#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int maxSum = 0;
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            leftSum += nums[i];
        }
        maxSum = leftSum;

        // Slide the window between the left and right ends of the array
        for (int i = 1; i <= k; i++) {
            leftSum -= nums[k - i];
            rightSum += nums[n - i];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Call the method and display the result
    int result = solution.maxScore(nums, k);
    cout << "Maximum score: " << result << endl;

    return 0;
}
