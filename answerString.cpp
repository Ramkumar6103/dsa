#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string res = "";
        int len = n - numFriends + 1;

        if (numFriends == 1) return word;

        for (int i = 0; i <= n - len; i++) {
            res = max(res, word.substr(i, len));
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string word1 = "dbca";
    int friends1 = 2;
    cout << "Input: word = \"" << word1 << "\", numFriends = " << friends1 << endl;
    cout << "Output: \"" << sol.answerString(word1, friends1) << "\"" << endl;

    // Test case 2
    string word2 = "gggg";
    int friends2 = 4;
    cout << "Input: word = \"" << word2 << "\", numFriends = " << friends2 << endl;
    cout << "Output: \"" << sol.answerString(word2, friends2) << "\"" << endl;

    return 0;
}
