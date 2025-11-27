#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    static long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<ll> minS(k, LLONG_MAX / 2);
        ll prefix = 0, ans = LLONG_MIN;
        minS[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            ll& ksum = minS[i % k];
            ans = max(ans, prefix - ksum);
            ksum = min(prefix, ksum);
        }
        return ans;
    }
};

int main() {
    // Example input
    int n = 5, k = 2;
    vector<int> nums = {1, -2, 3, 4, -1};

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";
    cout << "k = " << k << "\n";

    long long result = Solution::maxSubarraySum(nums, k);
    cout << "Maximum subarray sum with modulo constraint = " << result << "\n";

    return 0;
}
