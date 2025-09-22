#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> memo = triangle[row - 1];
        for (int r = row - 2; r >= 0; r--) {
            for (int c = 0; c <= r; c++) {
                memo[c] = min(memo[c], memo[c + 1]) + triangle[r][c];
                // cout << memo[c] << " ";
            }
            // cout << endl;
        }
        return memo[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Minimum path sum from top to bottom: " << sol.minimumTotal(triangle) << endl;
    return 0;
}
