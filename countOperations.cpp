#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 < num2) {
                num2 = num2 - num1;
            } else {
                num1 = num1 - num2;
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample test cases
    int num1 = 5, num2 = 3;
    cout << "Operations for (" << num1 << ", " << num2 << "): " 
         << sol.countOperations(num1, num2) << endl;

    num1 = 10, num2 = 10;
    cout << "Operations for (" << num1 << ", " << num2 << "): " 
         << sol.countOperations(num1, num2) << endl;

    num1 = 15, num2 = 4;
    cout << "Operations for (" << num1 << ", " << num2 << "): " 
         << sol.countOperations(num1, num2) << endl;

    return 0;
}
