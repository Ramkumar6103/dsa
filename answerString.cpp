// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         int n = word.size();
//         string res = "";
//         int len = n - numFriends + 1;

//         if (numFriends == 1) return word;

//         for (int i = 0; i <= n - len; i++) {
//             res = max(res, word.substr(i, len));
//         }
//         return res;
//     }
// };

// int main() {
//     Solution sol;

//     // Test case 1
//     string word1 = "dbca";
//     int friends1 = 2;
//     cout << "Input: word = \"" << word1 << "\", numFriends = " << friends1 << endl;
//     cout << "Output: \"" << sol.answerString(word1, friends1) << "\"" << endl;

//     // Test case 2
//     string word2 = "gggg";
//     int friends2 = 4;
//     cout << "Input: word = \"" << word2 << "\", numFriends = " << friends2 << endl;
//     cout << "Output: \"" << sol.answerString(word2, friends2) << "\"" << endl;

//     return 0;
// }
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string result = "";

    void dfs(const string& word, int start, int cutsLeft, vector<string>& parts) {
        int n = word.size();
        if (cutsLeft == 0) {
            // Last part: from current position to end
            parts.push_back(word.substr(start));
            // Find max part in this split
            for (const string& part : parts) {
                result = max(result, part);
            }
            parts.pop_back(); // backtrack
            return;
        }

        // Try all cut positions from (start+1) to valid end
        for (int i = start + 1; i <= n - cutsLeft; ++i) {
            parts.push_back(word.substr(start, i - start));
            dfs(word, i, cutsLeft - 1, parts);
            parts.pop_back(); // backtrack
        }
    }

    string answerString(string word, int numFriends) {
        vector<string> parts;
        dfs(word, 0, numFriends - 1, parts);
        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string word1 = "aann";
    int friends1 = 2;
    cout << "Input: \"" << word1 << "\", " << friends1 << " friends" << endl;
    cout << "Output: " << sol.answerString(word1, friends1) << endl;

    // Test case 2
    string word2 = "dbca";
    int friends2 = 2;
    cout << "Input: \"" << word2 << "\", " << friends2 << " friends" << endl;
    cout << "Output: " << sol.answerString(word2, friends2) << endl;

    return 0;
}
