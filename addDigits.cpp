#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = sol.addDigits(num);
    cout << "Result of addDigits(" << num << ") = " << result << endl;

    return 0;
}

