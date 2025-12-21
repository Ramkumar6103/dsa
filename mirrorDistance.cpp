#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int t = stoi(s);
        return abs(t - n);
    }
};

int main() {
    Solution sol;
    int n = 25;
    // cout << "Enter a number: ";
    // cin >> n;

    int result = sol.mirrorDistance(n);
    cout << "Mirror distance: " << result << endl;

    return 0;
}
