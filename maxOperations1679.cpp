#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end()); // sort ascending
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int tempSum = nums[l] + nums[r];
            if (tempSum == k) {
                l++;
                r--;
                ans++;
            } else if (tempSum < k) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};

int main() {
    // Example 1
    {
        vector<int> nums = {1, 2, 3, 4};
        int k = 5;
        Solution sol;
        cout << "Example 1:\n";
        cout << "Input: nums = {1,2,3,4}, k = 5\n";
        cout << "Output: " << sol.maxOperations(nums, k) << "\n\n";
    }

    // Example 2
    {
        vector<int> nums = {3, 1, 3, 4, 3};
        int k = 6;
        Solution sol;
        cout << "Example 2:\n";
        cout << "Input: nums = {3,1,3,4,3}, k = 6\n";
        cout << "Output: " << sol.maxOperations(nums, k) << "\n\n";
    }

    // Interactive input
    // {
    //     int n, k;
    //     cout << "Enter number of elements (n): ";
    //     cin >> n;
    //     cout << "Enter k: ";
    //     cin >> k;

    //     vector<int> nums(n);
    //     cout << "Enter " << n << " elements:\n";
    //     for (int i = 0; i < n; i++) {
    //         cin >> nums[i];
    //     }

    //     Solution sol;
    //     cout << "Maximum number of operations = " << sol.maxOperations(nums, k) << "\n";
    // }

    return 0;
}
