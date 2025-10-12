#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mpp;
        for (int n : nums) {
            mpp[n]++;
        }
        for (auto [x, y] : mpp) {
            if (y % k == 0 && y >= k) {
                ans += (y * x);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {2, 3, 2, 3, 3, 4, 4, 4, 4};
    int k = 2;

    // Function call
    int result = sol.sumDivisibleByK(nums, k);

    // Output result
    cout << "Sum of elements with frequency divisible by " << k << " and >= " << k << " is: " << result << endl;

    return 0;
}
