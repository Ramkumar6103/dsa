#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        short result = 0;
        for (int i = 1; i < s.size(); i++) {
            result += abs(s[i] - s[i - 1]);
        }
        return result;
    }
};

int main() {
    string input = "hello";
    // cout << "Enter a string: ";
    // cin >> input;

    Solution sol;
    int score = sol.scoreOfString(input);

    cout << "Score of the string: " << score << endl;

    return 0;
}
