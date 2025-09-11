#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        vector<char> vowel = {'A','E','I','O','U','a','e','i','o','u'};
        auto it = find(vowel.begin(), vowel.end(), ch);
        return it != vowel.end();
    }

public:
    string sortVowels(string s) {
        vector<char> temp;
        for (char ch : s) {
            if (isVowel(ch)) {
                temp.push_back(ch);
            }
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = temp[0];
                temp.erase(temp.begin());
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string input = "leetcode";
    // cout << "Enter a string: ";
    // getline(cin, input);

    string result = sol.sortVowels(input);
    cout << "String after sorting vowels: " << result << endl;

    return 0;
}
