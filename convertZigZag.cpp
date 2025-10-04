#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<vector<char>> rows(numRows);
        int ind = 0, d = 1;
        string res;

        for (char ch : s) {
            rows[ind].push_back(ch);
            if (ind == 0) {
                d = 1;
            } else if (ind == numRows - 1) {
                d = -1;
            }
            ind += d;
        }

        for (auto& row : rows) {
            for (char c : row) {
                res += c;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string input = "PAYPALISHIRING";
    int numRows = 3;

    string result = sol.convert(input, numRows);
    cout << "Zigzag Conversion: " << result << endl;

    return 0;
}
