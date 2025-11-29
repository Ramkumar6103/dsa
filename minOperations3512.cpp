#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum % k;
    }
};

int main() {
    // Example input
    vector<int> nums = {3, 9, 7};
    int k = 5;
    // cout << "Enter number of elements: ";
    // cin >> n;

    // vector<int> nums(n);
    // cout << "Enter " << n << " elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }

    // cout << "Enter k: ";
    // cin >> k;

    Solution sol;
    int result = sol.minOperations(nums, k);

    cout << "Result: " << result << endl;

    return 0;
}
