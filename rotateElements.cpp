#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;

        // collect non-negative elements
        for (int x : nums) {
            if (x >= 0) temp.push_back(x);
        }

        int m = temp.size();
        if (m <= 1) return nums;

        k = k % m;  // important
        if (k == 0) return nums;

        // rotate left by k using reverse
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());
        reverse(temp.begin(), temp.end());

        // put back rotated values
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = temp[idx++];
            }
        }

        return nums;
    }
};

int main() {
    Solution sol;

    // 🔹 Hard-coded input
    vector<int> nums = {1, -2, 3, 4, -5, 6};
    int k = 2;

    cout << "Original array:\n";
    for (int x : nums) cout << x << " ";
    cout << endl;

    vector<int> result = sol.rotateElements(nums, k);

    cout << "After rotating non-negative elements by k = " << k << ":\n";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
