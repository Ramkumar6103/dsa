#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) ans++;
            }
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Input array and k value
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    // Calculate the result
    int result = solution.countPairs(nums, k);

    // Output the result
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
