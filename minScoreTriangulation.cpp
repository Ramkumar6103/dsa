#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int dp[50][50] = {};

    int minScoreTriangulation(vector<int>& values, int i = 0, int j = 0, int res = 0) {
        if (j == 0) j = values.size() - 1;
        if (dp[i][j] != 0) return dp[i][j];
        for (int k = i + 1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) +
                values[i] * values[k] * values[j] +
                minScoreTriangulation(values, k, j));
        }
        return dp[i][j] = res;
    }
};

int main() {
    Solution sol;
    vector<int> values = {1, 3, 1, 4, 1, 5}; // Example polygon vertex values
    int result = sol.minScoreTriangulation(values);
    cout << "Minimum score triangulation: " << result << endl;
    return 0;
}
