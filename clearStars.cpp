#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>> pq;  // Min-heap to get smallest character
        unordered_map<char, vector<int>> m;  // Map to track indices of characters
        vector<bool> v(n, true);  // Boolean array to mark which characters to keep

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    char temp = pq.top(); pq.pop();
                    int last = m[temp].back();
                    m[temp].pop_back();
                    v[i] = false;       // Remove '*'
                    v[last] = false;    // Remove smallest char before '*'
                }
            } else {
                pq.push(s[i]);
                m[s[i]].push_back(i);
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (v[i]) result += s[i];
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<string> testCases = {
        "de*",        // Expected: "e"
        "a*b*c*",     // Expected: ""
        "bac*dc*",    // Expected: "bd"
        "cb*a*",      // Expected: "a"
        "aab*bc*cd*", // Expected: "acd"
        "zxy*z*y*",   // Expected: "x"
        "abc*de*f*"   // Expected: "ad"
    };

    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\" --> Output: \"" << solution.clearStars(test) << "\"" << endl;
    }

    return 0;
}
