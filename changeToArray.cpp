#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<string> changeToArray(string s) {
        int i = 0;
        vector<string> temp;
        int n = s.size();
        string dummy = "";
        while (i < n) {
            while (i < n && s[i] != ' ') {
                dummy += s[i];
                i++;
            }
            i++; // skip space
            temp.push_back(dummy);
            dummy = "";
        }
        return temp;
    }

public:
    bool wordPattern(string pattern, string s) {
        vector<string> temp = changeToArray(s);
        if (pattern.size() != temp.size()) return false;

        unordered_map<char, string> mpp;
        unordered_map<string, char> rev_mpp;

        for (int i = 0; i < temp.size(); i++) {
            char p = pattern[i];
            string w = temp[i];

            if (mpp.count(p) == 0 && rev_mpp.count(w) == 0) {
                mpp[p] = w;
                rev_mpp[w] = p;
            } else {
                if (mpp[p] != w || rev_mpp[w] != p) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    string pattern1 = "abba";
    string str1 = "dog cat cat dog";
    cout << "Test 1: " << (sol.wordPattern(pattern1, str1) ? "True" : "False") << endl;

    string pattern2 = "abba";
    string str2 = "dog cat cat fish";
    cout << "Test 2: " << (sol.wordPattern(pattern2, str2) ? "True" : "False") << endl;

    string pattern3 = "aaaa";
    string str3 = "dog dog dog dog";
    cout << "Test 3: " << (sol.wordPattern(pattern3, str3) ? "True" : "False") << endl;

    string pattern4 = "abba";
    string str4 = "dog dog dog dog";
    cout << "Test 4: " << (sol.wordPattern(pattern4, str4) ? "True" : "False") << endl;

    return 0;
}
