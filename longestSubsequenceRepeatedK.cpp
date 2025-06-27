#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string result = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                string next = curr + ch;
                if (isK(next, s, k)) {
                    result = next;
                    q.push(next);
                }
            }
        }
        return result;
    }

    bool isK(string sub, string t, int k) {
        int count = 0, i = 0;
        for (char ch : t) {
            if (ch == sub[i]) {
                if (++i == sub.size()) {
                    i = 0;
                    if (++count == k) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "letsleetcode";
    int k = 2;

    // cout << "Enter a string: ";
    // cin >> s;
    // cout << "Enter k: ";
    // cin >> k;

    string result = sol.longestSubsequenceRepeatedK(s, k);
    cout << "Longest subsequence repeated " << k << " times: " << result << endl;

    return 0;
}
