#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1])
                cnt++;
        }
        if (s[0] == 'b' && cnt != 0)
            return false;
        return cnt <= 1;
    }
};

int main() {
    Solution obj;
    string s = "aabba";

    // cout << "Enter the string: ";
    // cin >> s;

    if (obj.checkString(s)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
