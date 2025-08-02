#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int nCr(int n, int r) {
        int res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) { // corrected loop boundary
                int sol = nCr(i, j);
                temp.push_back(sol);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    int numRows = 5; // Example value for numRows
    // cout << "Enter the number of rows for Pascal's Triangle: ";
    // cin >> numRows;

    Solution sol;
    vector<vector<int>> triangle = sol.generate(numRows);

    cout << "Pascal's Triangle:\n";
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
