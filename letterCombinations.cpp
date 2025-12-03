#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<string> letter = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // return empty vector

        vector<string> res{""};  // start with one empty string
        for (char d : digits) {
            vector<string> tmp;
            for (char ch : letter[d - '0']) {
                for (string &st : res) {
                    tmp.push_back(st + ch);
                }
            }
            res.swap(tmp);  // efficient replacement
        }
        return res;
    }
};

int main() {
    Solution sol;

    string digits = "23";
    // cout << "Enter digits (2-9): ";
    // cin >> digits;

    vector<string> combinations = sol.letterCombinations(digits);

    cout << "Letter combinations:\n";
    for (const string &s : combinations) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
