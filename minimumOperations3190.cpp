#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i] % 3;
            if (temp == 0) continue;
            else if (temp == 2) {
                nums[i] = nums[i] + 1;
                cnt++;
            }
            else if (temp == 1) {
                nums[i] = nums[i] - 1;
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {

    // Example input
    int n = 5;
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Input array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    Solution sol;
    int result = sol.minimumOperations(nums);

    cout << "Minimum operations: " << result << "\n";

    cout << "Modified array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}
