#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;  // Start with 1 possible string
        for (int i = 0; i < word.size() - 1; i++) {
            if (word[i] == word[i + 1]) {
                ans++;  // Increment count if adjacent characters are the same
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "abbcccc";

    // cout << "Enter a string: ";
    // cin >> input;

    int result = sol.possibleStringCount(input);
    cout << "Possible string count: " << result << endl;

    return 0;
}
