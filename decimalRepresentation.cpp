#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int base10 = 0;
        vector<int> ans;
        while (n) {
            int dig = n % 10;
            if (dig != 0)
                ans.push_back(dig * pow(10, base10));
            base10++;
            n = n / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    vector<int> result = sol.decimalRepresentation(number);

    cout << "Decimal components: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
