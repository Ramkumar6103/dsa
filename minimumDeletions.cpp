#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        int ans = INT_MAX;

        for (char c : word) {
            freq[c]++;
        }

        for (auto [c1, f1] : freq) {
            int deletions = 0;
            for (auto [c2, f2] : freq) {
                if (f2 < f1) {
                    deletions += f2;
                } else if (f2 - f1 > k) {
                    deletions += f2 - f1 - k;
                }
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string word = "dabdcbdcdcd";
    int k = 2;

    // cout << "Enter the string: ";
    // cin >> word;
    // cout << "Enter the value of k: ";
    // cin >> k;

    int result = solution.minimumDeletions(word, k);
    cout << "Minimum deletions required: " << result << endl;

    return 0;
}
