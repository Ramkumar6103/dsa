#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Expands around center and returns palindrome length
    int func(string &s, int left, int right) {
        int l = left;
        int r = right;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        // length of palindrome
        return r - l - 1;
    }

public:
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0;
        int maxlen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int odd = func(s, i, i);

            // Even length palindrome
            int even = func(s, i, i + 1);

            int currLen = max(odd, even);

            if (currLen > maxlen) {
                maxlen = currLen;
                start = i - (currLen - 1) / 2;
            }
        }

        return s.substr(start, maxlen);
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}
