#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();

        // Prefix sum array
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        // Suffix minimum array
        vector<int> suffix(n, INT_MAX);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        // Compute maximum score
        for (int i = 0; i < n - 1; i++) {
            long long temp = prefix[i] - suffix[i + 1];
            ans = max(ans, temp);
        }

        return ans;
    }
};

int main() {
    // Inbuilt input
    vector<int> nums = {5, 3, 1, 7, 2};

    Solution obj;
    long long result = obj.maximumScore(nums);

    cout << "Maximum Score: " << result << endl;

    return 0;
}
