#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        
        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1]++;
            if (r2 + 1 < n)
                diff[r2 + 1][c1]--;
            if (c2 + 1 < n)
                diff[r1][c2 + 1]--;
            if (r2 + 1 < n && c2 + 1 < n)
                diff[r2 + 1][c2 + 1]++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int above = i ? diff[i - 1][j] : 0;
                int left = j ? diff[i][j - 1] : 0;
                int diag = (i && j) ? diff[i - 1][j - 1] : 0;
                diff[i][j] += above + left - diag;
            }
        }
        
        return diff;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> queries = {
        {1, 1, 3, 3},
        {0, 0, 1, 1}
    };

    Solution sol;
    vector<vector<int>> result = sol.rangeAddQueries(n, queries);

    cout << "Resulting matrix after range additions:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

