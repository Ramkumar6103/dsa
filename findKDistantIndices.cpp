#include <iostream>
#include <vector>
#include <algorithm> // for max and min
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;  // Keeps track of the smallest unchecked index
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                // Calculate valid range from current j (key) with distance k
                int l = max(r, j - k);       // Don't go below last 'r'
                r = min(n - 1, j + k) + 1;   // Update r to avoid duplicate checking

                for (int i = l; i < r; ++i) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    // Print result
    cout << "K-distant indices are: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
