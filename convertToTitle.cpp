#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";

        while (columnNumber > 0) {
            columnNumber--;
            res = char((columnNumber % 26) + 'A') + res;
            columnNumber /= 26;
        }
        
        return res;        
    }
};

int main() {
    Solution solution;
    int columnNumber = 28;

    string result = solution.convertToTitle(columnNumber);
    cout << "Excel column title: " << result << endl;

    return 0;
}
