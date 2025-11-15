#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        map<int, vector<int>> mpp;

        // Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        // Check for each number that appears at least 3 times
        for (auto [x, y] : mpp) {
            if (y.size() >= 3) {
                for (int i = 0; i < y.size() - 2; i++) {
                    int y1 = y[i];
                    int y2 = y[i + 1];
                    int y3 = y[i + 2];
                    int mini = abs(y1 - y2) + abs(y2 - y3) + abs(y3 - y1);
                    ans = min(ans, mini);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,5,5,2,5};
    int n, val;

    // cout << "Enter number of elements: ";
    // cin >> n;

    // cout << "Enter the elements:\n";
    // for (int i = 0; i < n; ++i) {
    //     cin >> val;
    //     nums.push_back(val);
    // }

    int result = sol.minimumDistance(nums);
    cout << "Minimum distance among any three identical elements: " << result << endl;

    return 0;
}
