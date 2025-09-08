#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function: returns true if the number has no zero digits
    bool isNotZero(int num) {
        while (num > 0) {
            int d = num % 10;
            if (d == 0) return false;
            num = num / 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (isNotZero(i) && isNotZero(n - i)) {
                return {i, n - i};
            }
        }
        return {0, 0}; // fallback, though problem guarantees a solution
    }
};

int main() {
    Solution sol;

    int n = 11;
    // cout << "Enter a number: ";
    // cin >> n;

    vector<int> result = sol.getNoZeroIntegers(n);

    cout << "Two no-zero integers are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
