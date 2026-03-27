#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;  // reduce k < n

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // even row , left rotate
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    // odd row , right rotate
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int m, n, k;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    cout << "Enter rotation value (k): ";
    cin >> k;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements row by row:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    bool result = sol.areSimilar(mat, k);

    if (result)
        cout << "The matrix rows are similar after rotations.\n";
    else
        cout << "The matrix rows are NOT similar after rotations.\n";

    return 0;
}
