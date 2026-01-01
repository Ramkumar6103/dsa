#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                d[i]++;  // add 1 to the last digit
            }
            if (d[i] == 10) {
                d[i] = 0;
                if (i == 0) {
                    d.push_back(0);   // extend size
                    d[i] = 1;         // carry to new first digit
                } else {
                    d[i - 1]++;       // carry to previous digit
                }
            } else {
                break;  // no carry, stop
            }
        }
        return d;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> digits1 = {1, 2, 9};
    vector<int> result1 = sol.plusOne(digits1);
    cout << "Result 1: ";
    for (int digit : result1) cout << digit << " ";
    cout << endl;

    // Example 2
    vector<int> digits2 = {9, 9, 9, 9};
    vector<int> result2 = sol.plusOne(digits2);
    cout << "Result 2: ";
    for (int digit : result2) cout << digit << " ";
    cout << endl;

    // Example 3
    vector<int> digits3 = {4, 3, 2, 1};
    vector<int> result3 = sol.plusOne(digits3);
    cout << "Result 3: ";
    for (int digit : result3) cout << digit << " ";
    cout << endl;

    return 0;
}
