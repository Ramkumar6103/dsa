#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int result = -1;
        for (int i = 1; i <= 60; i++) {
            long long r = 1LL * num1 - 1LL * i * num2;
            if (r < i) continue;
            int pop = __builtin_popcountll(r);
            if (pop <= i && i <= r) return i;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    int num1=3, num2=-2;

    // cout << "Enter num1: ";
    // cin >> num1;
    // cout << "Enter num2: ";
    // cin >> num2;

    int result = sol.makeTheIntegerZero(num1, num2);
    if (result != -1)
        cout << "Minimum number of operations to make the integer zero: " << result << endl;
    else
        cout << "It's not possible to make the integer zero with given constraints." << endl;

    return 0;
}
