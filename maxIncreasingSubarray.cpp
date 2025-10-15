#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& A) {
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
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> A = {1, 2, 3, 1, 2, 3, 4, 1};

    // Call the function and print the result
    int result = sol.maxIncreasingSubarrays(A);
    cout << "Maximum increasing subarray metric: " << result << endl;

    return 0;
}
