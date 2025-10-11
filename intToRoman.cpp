#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string res;

        for (const auto& [value, symbol] : valueSymbols) {
            if (num == 0)
                break;

            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Sample test cases
    vector<int> testCases = {3, 4, 9, 58, 1994, 2025};

    for (int num : testCases) {
        string roman = solution.intToRoman(num);
        cout << "Integer: " << num << " => Roman: " << roman << endl;
    }

    return 0;
}
