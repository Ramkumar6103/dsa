#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Sample inputs to test
    string input1 = "A";
    string input2 = "AB";
    string input3 = "ZY";
    string input4 = "FXSHRXW"; // Large input

    cout << "Column Title: " << input1 << " → Column Number: " << sol.titleToNumber(input1) << endl;
    cout << "Column Title: " << input2 << " → Column Number: " << sol.titleToNumber(input2) << endl;
    cout << "Column Title: " << input3 << " → Column Number: " << sol.titleToNumber(input3) << endl;
    cout << "Column Title: " << input4 << " → Column Number: " << sol.titleToNumber(input4) << endl;

    return 0;
}
