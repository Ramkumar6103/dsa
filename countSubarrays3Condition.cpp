#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int left = 0; 
        int right = 2;
        int count = 0;
        double sum = 0;
        int n = nums.size();
        while (right < n) {
            sum = nums[left] + nums[right];
            if ((double)nums[left+1] / 2 == sum) {
                count++;
            }
            left++;
            right++;
        }
        return count;
    }
};

int main() {
    // Example input
vector<int> nums = { 1, 2, 1, 4, 1 };

    // Create an instance of Solution
    Solution solution;

    // Get the result
    int result = solution.countSubarrays(nums);

    // Display the result
    cout << "Number of subarrays meeting the condition: " << result << endl;

    return 0;
}
