#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s;
        string b = s;

        // Find first digit not equal to '9' for max replacement
        char maxReplace = 0;
        for (char c : s) {
            if (c != '9') {
                maxReplace = c;
                break;
            }
        }
        if (maxReplace) {
            for (char &c : a) {
                if (c == maxReplace) c = '9';
            }
        }

        // For min replacement
        char minReplace = 0;
        if (s[0] != '1') {
            minReplace = s[0];
            for (char &c : b) {
                if (c == minReplace) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    minReplace = s[i];
                    break;
                }
            }
            if (minReplace) {
                for (int i = 1; i < b.size(); ++i) {
                    if (b[i] == minReplace) b[i] = '0';
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};

int main() {
    Solution sol;
    int num = 123456;

    // cout << "Enter an integer: ";
    // cin >> num;

    int result = sol.maxDiff(num);
    cout << "Maximum difference after replacements: " << result << endl;

    return 0;
}
