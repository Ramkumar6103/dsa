#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
              int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string input = "leetcode";
    // cout << "Enter a string: ";
    // cin >> input;

    int index = sol.firstUniqChar(input);

    if (index == -1) {
        cout << "No unique character found" << endl;
    } else {
        cout << "First unique character is at index: " << index << endl;
    }

    return 0;
}
