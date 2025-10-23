#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        string res = "";
        while (s.size() > 2 && i < s.size() - 1) {
            res += ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            i++;
            if (i == s.size() - 1) {
                s = res;
                i = 0;
                res = "";
            }
        }
        return s.size() == 2 && s[0] == s[1];
    }
};

int main() {
    Solution sol;
    string input = "3902";
    // cout << "Enter a string of digits: ";
    // cin >> input;

    if (sol.hasSameDigits(input)) {
        cout << "The final two digits are the same." << endl;
    } else {
        cout << "The final two digits are different." << endl;
    }

    return 0;
}
