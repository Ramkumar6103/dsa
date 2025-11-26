#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;
                if (freq.size() >= 2) {
                    int first = INT_MIN;
                    int last = INT_MAX;
                    for (auto [x, y] : freq) {
                        first = max(first, y);
                        last = min(last, y);
                    }
                    sum += (first - last);
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string s = "aabcb";
    // cout << "Enter a string: ";
    // cin >> s;

    int result = sol.beautySum(s);
    cout << "Beauty sum of substrings: " << result << endl;

    return 0;
}
