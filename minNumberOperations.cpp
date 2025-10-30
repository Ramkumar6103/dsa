#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int res = A[0];  // first element needs A[0] operations
        for (int i = 1; i < A.size(); ++i)
            res += max(A[i] - A[i - 1], 0);  // add only positive differences
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> A1 = {1, 2, 3, 2, 1};
    cout << "Minimum operations for [1, 2, 3, 2, 1]: "
         << sol.minNumberOperations(A1) << endl;

    // Example 2
    vector<int> A2 = {3, 1, 1, 2};
    cout << "Minimum operations for [3, 1, 1, 2]: "
         << sol.minNumberOperations(A2) << endl;

    // Example 3
    vector<int> A3 = {3, 1, 5, 4, 2};
    cout << "Minimum operations for [3, 1, 5, 4, 2]: "
         << sol.minNumberOperations(A3) << endl;

    return 0;
}
