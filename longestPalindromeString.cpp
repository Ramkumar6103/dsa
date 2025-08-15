#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool isPalindrome(string str) {
        int l = 0;
        int r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        string tempStr = "";
        string maxStr = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int it = 1;
            for (int j = i + 1; j <= n; j++) {
                if (isPalindrome(s.substr(i, it))) {
                    tempStr = s.substr(i, it);
                    if (tempStr.size() > maxStr.size()) {
                        maxStr = tempStr;
                    }
                }
                it++;
            }
        }
        return maxStr;
    }
};

int main() {
    Solution sol;
    string input = "babad";
    // cout << "Enter a string: ";
    // cin >> input;

    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
