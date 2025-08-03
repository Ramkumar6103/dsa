#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        int p = 0;
        int q = 1;
        int r = 2;
        vector<bool> ans(n, false);

        while (i < n - 1) {
            if (nums[i] < nums[j] && !ans[q]) {
                ans[p] = true;
                i++;
                j++;
            }
            else if (nums[i] > nums[j] && !ans[r]) {
                ans[q] = true;
                i++;
                j++;
            }
            else if (nums[i] < nums[j]) {
                ans[r] = true;
                i++;
                j++;
            }
            else {
                return false;
            }
        }
        return (ans[p] && ans[q] && ans[r]);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 4, 5};
    if (sol.isTrionic(nums)) {
        cout << "The sequence is Trionic!" << endl;
    } else {
        cout << "The sequence is NOT Trionic." << endl;
    }
    return 0;
}
