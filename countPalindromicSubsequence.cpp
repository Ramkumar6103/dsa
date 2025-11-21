#include <bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     bool isPalindrom(string ans) {
//         // A 3-character string is palindromic if first and last characters match
//         return ans[0] == ans[2];
//     }

// public:
//     int countPalindromicSubsequence(string s) {
//         int n = s.size();
//         if (n < 3)
//             return 0;

//         unordered_set<string> palin;
//         for (int i = 0; i < n - 2; i++) {
//             for (int j = i + 1; j < n - 1; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     string isP = "";
//                     isP.push_back(s[i]);
//                     isP.push_back(s[j]);
//                     isP.push_back(s[k]);
//                     if (isPalindrom(isP)) {
//                         palin.insert(isP);
//                     }
//                 }
//             }
//         }
//         return palin.size();
//     }
// };

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> minExist(26, INT_MAX);
        vector<int> maxExist(26, INT_MIN);
        for (int i = 0; i < s.size(); i++) {
            int charIndex = s[i] - 'a';
            minExist[charIndex] = min(minExist[charIndex], i);
            maxExist[charIndex] = max(maxExist[charIndex], i);
        }
        for(int i=0;i<26;i++){
            if(maxExist[i] == INT_MIN || minExist[i] == INT_MAX){
                continue;
            }
            unordered_set<char> charbetween;
            for(int j=minExist[i]+1;j<maxExist[i];j++){
                charbetween.insert(s[j]);
            }
            ans += charbetween.size();
        }
        return ans;
    }
};
int main() {
    Solution sol;

    // Example input
    string s = "bbcbaba";
    cout << "Input string: " << s << endl;

    int result = sol.countPalindromicSubsequence(s);
    cout << "Number of distinct palindromic subsequences of length 3: " << result << endl;

    return 0;
}
