#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            bool isCele = true;

            // Row check: i should not know anyone
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] == 1) {
                    isCele = false;
                    break;
                }
            }

            // Column check: everyone should know i
            if (isCele) {
                for (int j = 0; j < n; j++) {
                    if (i != j && mat[j][i] == 0) {
                        isCele = false;
                        break;
                    }
                }
            }

            if (isCele)
                return i;
        }

        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    cout << sol.celebrity(mat) << endl;

    return 0;
}
