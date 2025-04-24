#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int left = 0;
        int ans = 0;
        int k = unordered_set<int>(nums.begin(), nums.end()).size(); // Count distinct elements in nums
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                ans += nums.size() - i; // Add the valid subarrays
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]); // Remove element if its count reaches zero
                }
                left++; // Shrink the window
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 1, 2, 2}; // Example input
    Solution solution;
    int result = solution.countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl; // Output the result
    return 0;
}
