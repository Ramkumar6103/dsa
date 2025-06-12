#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> visited;

        while (!paths.empty()) {
            vector<string> path = paths.front(); paths.pop();
            if (path.size() > level) {
                for (const string& word : visited) st.erase(word);
                visited.clear();
                level = path.size();
                if (level > minLevel) break;
            }

            string lastWord = path.back();
            if (lastWord == endWord) {
                minLevel = level;
                ans.push_back(path);
            }

            for (int i = 0; i < lastWord.size(); ++i) {
                string temp = lastWord;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (st.count(temp)) {
                        vector<string> newPath = path;
                        newPath.push_back(temp);
                        paths.push(newPath);
                        visited.insert(temp);
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> result = sol.findLadders("hit", "cog", wordList);

    for (const auto& path : result) {
        for (const auto& word : path) cout << word << " ";
        cout << endl;
    }

    return 0;
}
