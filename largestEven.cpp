#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '1') {
            s.erase(s.begin() + i);
            i--;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "1222111";
    // cout << "Enter a string of digits: ";
    // cin >> s;

    Solution sol;
    string result = sol.largestEven(s);

    cout << "Largest even string: " << result << "\n";

    return 0;
}
