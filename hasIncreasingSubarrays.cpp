#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& A, int k) {
        int n = A.size(), up = 1, pre_max_up = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                up++;
            } else {
                pre_max_up = up;
                up = 1;
            }
            res = max({res, up / 2, min(pre_max_up, up)});
        }
        return res >= k;
    }
};

int main() {
    Solution sol;

    // Sample test case
    vector<int> A = {1, 2, 3, 1, 2, 3, 4};
    int k = 3;

    bool result = sol.hasIncreasingSubarrays(A, k);
    cout << "Has increasing subarray of length >= " << k << "? " << (result ? "Yes" : "No") << endl;

    return 0;
}
