#include <bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     bool isStringPresent(string temp, unordered_map<string,int> baseMap, int si){
//         for(int i = 0; i < temp.size(); i += si){
//             string part = temp.substr(i, si);
//             if (baseMap.find(part) == baseMap.end()) return false;
//             baseMap[part]--;
//             if (baseMap[part] < 0) return false;
//         }
//         return true;
//     }

// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> ans;
//         int si = words[0].size();
//         int ws = si * words.size();

//         if (s.size() < ws) return ans;   // ✅ fixed

//         unordered_map<string, int> baseMap;
//         for (auto &w : words) {
//             baseMap[w]++;
//         }

//         for(int i = 0; i <= s.size() - ws; i++){
//             string temp = s.substr(i, ws);
//             if(isStringPresent(temp, baseMap, si)){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int si = words[0].size();
        int wc = words.size();
        int ws = si * wc;

        if (s.size() < ws) return ans;

        unordered_map<string, int> baseMap;
        for (auto &w : words) baseMap[w]++;

        for (int i = 0; i < si; i++) {
            unordered_map<string, int> seen;
            int left = i, count = 0;

            for (int j = i; j + si <= s.size(); j += si) {
                string word = s.substr(j, si);

                if (baseMap.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > baseMap[word]) {
                        string leftWord = s.substr(left, si);
                        seen[leftWord]--;
                        left += si;
                        count--;
                    }

                    if (count == wc) {
                        ans.push_back(left);
                    }
                }
                else {
                    seen.clear();
                    count = 0;
                    left = j + si;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // 🔹 Inbuilt input
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = sol.findSubstring(s, words);

    cout << "Starting indices: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
