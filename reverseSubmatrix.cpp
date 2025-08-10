#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            int top = x + i;
            int bottom = x + k - 1 - i;
            for (int col = 0; col < k; col++) {
                swap(grid[top][y + col], grid[bottom][y + col]);
            }
        }
        return grid;
    }
};

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int x = 1; // starting row of submatrix
    int y = 1; // starting column of submatrix
    int k = 2; // size of the submatrix (k x k)

    Solution sol;
    vector<vector<int>> result = sol.reverseSubmatrix(grid, x, y, k);

    cout << "Modified Grid:" << endl;
    printGrid(result);

    return 0;
}
