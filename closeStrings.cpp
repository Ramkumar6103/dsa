#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        set<char> s1, s2;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        if (n != m)
            return false;

        for (int i = 0; i < n; i++) {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if (s1 == s2 && v1 == v2) return true;
        return false;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    string word1 = "abc";
    string word2 = "bca";
    cout << "Test 1: " << (sol.closeStrings(word1, word2) ? "true" : "false") << endl;

    word1 = "a";
    word2 = "aa";
    cout << "Test 2: " << (sol.closeStrings(word1, word2) ? "true" : "false") << endl;

    word1 = "cabbba";
    word2 = "abbccc";
    cout << "Test 3: " << (sol.closeStrings(word1, word2) ? "true" : "false") << endl;

    word1 = "cabbba";
    word2 = "aabbss";
    cout << "Test 4: " << (sol.closeStrings(word1, word2) ? "true" : "false") << endl;

    return 0;
}
