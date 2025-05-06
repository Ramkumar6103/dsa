#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int sz = s.size();
        return (s[sz-1] - '0') * (s[sz-2] - '0');
    }
};

int main() {
    int n=267;

    Solution sol;
    int result = sol.maxProduct(n);

    cout << "Maximum product of two largest digits: " << result << endl;

    return 0;
}
