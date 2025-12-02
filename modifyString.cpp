#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                char left = (i > 0) ? s[i - 1] : ' ';
                char right = (i + 1 < n) ? s[i + 1] : ' ';
                s[i] = (left != 'a' && right != 'a') ? 'a' 
                     : (left != 'b' && right != 'b') ? 'b' 
                     : 'c';
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "??ab??";

    // cout << "Enter a string with '?' characters: ";
    // cin >> s;

    string result = sol.modifyString(s);

    cout << "Modified string: " << result << endl;

    return 0;
}
