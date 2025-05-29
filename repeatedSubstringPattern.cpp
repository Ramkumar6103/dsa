#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string substring = "";
        int n = s.size();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                substring = s.substr(0, i);
                string repeat = "";
                for (int j = 0; j < n / i; j++) {
                    repeat += substring;
                }
                if (repeat == s) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "abcabcabcabc";

    // cout << "Enter a string: ";
    // cin >> s;

    if (sol.repeatedSubstringPattern(s)) {
        cout << "The string can be formed by repeating a substring." << endl;
    } else {
        cout << "The string cannot be formed by repeating a substring." << endl;
    }

    return 0;
}
