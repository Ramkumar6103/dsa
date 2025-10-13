#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            string a = words[i], b = ans.back();
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (a != b) ans.push_back(words[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result = sol.removeAnagrams(words);

    cout << "Result after removing consecutive anagrams:\n";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
