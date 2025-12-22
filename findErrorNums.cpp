#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int initialSum = accumulate(nums.begin(), nums.end(), 0);
        set<int> s;
        for (auto& i : nums) {
            s.insert(i);
        }
        int sum = accumulate(s.begin(), s.end(), 0);
        int repeatedNum = initialSum - sum;
        int n = nums.size();
        int missingNum = n * (n + 1) / 2 - sum;
        return {repeatedNum, missingNum};
    }
};

int main() {
    Solution sol;
    // int n;
    // cout << "Enter size of array: ";
    // cin >> n;

    vector<int> nums = {1,2,2,4};
    // cout << "Enter " << n << " elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }

    vector<int> result = sol.findErrorNums(nums);
    cout << "Repeated Number: " << result[0] << endl;
    cout << "Missing Number: " << result[1] << endl;

    return 0;
}
