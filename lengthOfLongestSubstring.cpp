#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = s.size();   // use int instead of short int
        vector<bool> mpp(128, false);

        while (r < n) {
            if (mpp[s[r]] == false) {
                mpp[s[r]] = true;
                r++;
                maxLen = max(maxLen, r - l);
            } else {
                mpp[s[l]] = false;
                l++;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = "abcdabbc";

    // cout << "Enter the string: ";
    // cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " 
         << result << endl;

    return 0;
}
