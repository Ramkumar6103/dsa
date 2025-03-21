#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int n1 = s.size();
        int n2 = t.size();
        if (n1 == 0) return true;
        while (i < n1 && j < n2) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n1;
    }
};

int main() {
    Solution solution;

    // Example usage:
    string s = "abc"; // The string to check if it's a subsequence.
    string t = "ahbgdc"; // The target string.

    if (solution.isSubsequence(s, t)) {
        cout << "Yes, \"" << s << "\" is a subsequence of \"" << t << "\"." << endl;
    } else {
        cout << "No, \"" << s << "\" is not a subsequence of \"" << t << "\"." << endl;
    }

    return 0;
}
