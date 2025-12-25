#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string ans = "";
        for (char ch : s) {
            if (ch == '*' && !stk.empty()) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        while (!stk.empty()) {
            char ch = stk.top();
            stk.pop();
            ans.push_back(ch);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        string s = "leet**cod*e";
        cout << "Example 1:\n";
        cout << "Input: " << s << "\n";
        cout << "Output: " << sol.removeStars(s) << "\n\n";
    }

    // Example 2
    {
        string s = "erase*****";
        cout << "Example 2:\n";
        cout << "Input: " << s << "\n";
        cout << "Output: " << sol.removeStars(s) << "\n\n";
    }

    // Interactive input
    // {
    //     string s;
    //     cout << "Enter a string with '*' characters: ";
    //     cin >> s;
    //     cout << "Result after removing stars: " << sol.removeStars(s) << "\n";
    // }

    return 0;
}
