#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int even = 1;  // empty prefix
        int odd = 0;
        int parity = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (char ch : s) {
            if (vowels.count(ch)) {
                parity ^= 1;  // flip parity
            }
            if (parity == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return even * odd > 0;
    }
};

int main() {
    Solution sol;
    string input = "leetcoder";

    // cout << "Enter a lowercase string: ";
    // cin >> input;

    bool result = sol.doesAliceWin(input);
    if (result) {
        cout << "Alice wins!" << endl;
    } else {
        cout << "Alice loses!" << endl;
    }

    return 0;
}
