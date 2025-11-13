#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int ones = 0;
        bool use = false;

        for (char c : s) {
            if (c == '0') {
                use = true;
            } else {
                if (use) {
                    result += ones;
                }
                ones++;
                use = false;
            }
        }

        if (use) {
            result += ones;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    string test1 = "0101";
    string test2 = "001011";
    string test3 = "1111";
    string test4 = "0000";

    cout << "maxOperations(\"" << test1 << "\") = " << sol.maxOperations(test1) << endl;
    cout << "maxOperations(\"" << test2 << "\") = " << sol.maxOperations(test2) << endl;
    cout << "maxOperations(\"" << test3 << "\") = " << sol.maxOperations(test3) << endl;
    cout << "maxOperations(\"" << test4 << "\") = " << sol.maxOperations(test4) << endl;

    return 0;
}
