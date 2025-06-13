#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;  // If no pairs are needed, return 0
        sort(nums.begin(), nums.end());  // Sort the array to work with differences
        int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];  // Define search boundaries

        // Binary search for the minimum max difference
        while (left < right) {
            int mid = left + (right - left) / 2, pairs = 0;
            
            // Try to form 'p' pairs with max difference <= mid
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {  
                    ++pairs; // Form a pair
                    ++i;  // Skip the next element since it's already paired
                }
            }

            // Adjust binary search boundaries based on number of valid pairs
            if (pairs >= p) right = mid;  // If enough pairs can be formed, reduce max difference
            else left = mid + 1;  // Otherwise, increase max difference
        }
        
        return left;  // Minimum possible maximum difference
    }
};

int main() {
    vector<int> nums = {10,1,2,7,1,3};  // Example input
    int p = 2;  // Number of pairs needed
    
    Solution sol;
    int result = sol.minimizeMax(nums, p);
    
    cout << "Minimum possible maximum difference: " << result << endl;
    
    return 0;
}
