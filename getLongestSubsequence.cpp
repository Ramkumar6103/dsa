#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int last = -1;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != last) {
                ans.push_back(words[i]);
                last = groups[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    vector<int> groups = {1, 1, 2, 3, 3};

    vector<string> result = solution.getLongestSubsequence(words, groups);

    cout << "Longest subsequence: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
