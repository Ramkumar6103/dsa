#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto [x, y] : mpp) {
            if (y % 2 != 0) {
                maxi = max(maxi, y);
            } else if (y % 2 == 0) {
                mini = min(mini, y);
            }
        }

        return maxi - mini;
    }
};

int main() {
    string s = "aaaaabbc";
    // cout << "Enter a string: ";
    // cin >> s;

    Solution sol;
    int result = sol.maxDifference(s);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
