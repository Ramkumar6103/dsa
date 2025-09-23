#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        int v1sum = 0;
        int v2sum = 0;

        for (char ch : version1) {
            if (ch == '.') {
                v1.push_back(v1sum);
                v1sum = 0;
            } else {
                v1sum = (v1sum * 10) + (ch - '0');
            }
        }
        v1.push_back(v1sum);

        for (char ch : version2) {
            if (ch == '.') {
                v2.push_back(v2sum);
                v2sum = 0;
            } else {
                v2sum = (v2sum * 10) + (ch - '0');
            }
        }
        v2.push_back(v2sum);

        int minver = min(v1.size(), v2.size());
        for (int i = 0; i < minver; i++) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }

        if (minver == v1.size()) {
            for (int i = minver; i < v2.size(); i++) {
                if (v2[i] != 0) return -1;
            }
        } else if (minver == v2.size()) {
            for (int i = minver; i < v1.size(); i++) {
                if (v1[i] != 0) return 1;
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> testCases = {
        {"1.01", "1.001"},
        {"1.0", "1.0.0"},
        {"0.1", "1.1"},
        {"1.0.1", "1"},
        {"7.5.2.4", "7.5.3"},
        {"1.2", "1.10"}
    };

    for (auto& test : testCases) {
        int result = sol.compareVersion(test.first, test.second);
        cout << "Compare \"" << test.first << "\" vs \"" << test.second << "\": " << result << endl;
    }

    return 0;
}
