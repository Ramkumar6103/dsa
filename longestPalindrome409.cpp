#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto [ch, cnt] : mpp) {
            if (cnt % 2 == 0) {
                length += cnt;
            } else {
                length += cnt - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) length += 1; // one odd can be center

        return length;
    }
};

int main() {
    Solution sol;
    string s = "abccccdd";

    // cout << "Enter a string: ";
    // cin >> s;

    int result = sol.longestPalindrome(s);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;

    return 0;
}
