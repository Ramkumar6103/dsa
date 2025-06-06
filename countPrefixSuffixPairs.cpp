#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Check if str1 is both prefix and suffix of str2
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.size(), n2 = str2.size();
        if (n1 > n2)
            return false;
        return str2.substr(0, n1) == str1 && str2.substr(n2 - n1) == str1;
    }

    // Count pairs where words[i] is both prefix and suffix of words[j]
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};

// Main function to test the class
int main() {
    Solution sol;

    // Test case
    vector<string> words = {"a","aba","ababa","aa"};

    cout << "Input words: ";
    for (const auto& w : words) cout << w << " ";
    cout << "\n";

    int result = sol.countPrefixSuffixPairs(words);

    cout << "Number of prefix and suffix pairs: " << result << endl;

    return 0;
}
