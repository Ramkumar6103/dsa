#include <iostream>
#include <vector>
#include <algorithm> // For the max function

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int n = nums.size();
        double maxsum = 0;
        double sum = 0;

        // Compute the sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxsum = sum;

        // Slide the window over the array
        for (int j = k; j < n; j++) {
            sum = sum + nums[j] - nums[j - k];
            maxsum = max(sum, maxsum);
        }

        // Compute the maximum average
        ans = maxsum / k;
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Example input
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // Find the maximum average
    double result = solution.findMaxAverage(nums, k);

    // Output the result
    cout << "The maximum average is: " << result << endl;

    return 0;
}
