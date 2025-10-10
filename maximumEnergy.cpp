#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // int maximumEnergy(vector<int>& energy, int k) {
    //     int n = energy.size();
    //     vector<int> dp(n);
    //     for (int i = 0; i < n; i++) {
    //         int temp = 0;
    //         for (int j = i; j < n; j += k) {
    //             temp += energy[j];
    //         }
    //         dp[i] = temp;
    //     }
    //     return *max_element(dp.begin(), dp.end());
    // }

        int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + ((i+k) < n ? dp[i+k] : 0);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> energy = {5, -2, 3, 1, -1, 4};
    int k = 2;

    // Call the function and print the result
    int result = sol.maximumEnergy(energy, k);
    cout << "Maximum energy: " << result << endl;

    return 0;
}
