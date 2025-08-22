#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if (maxRow == -1) return 0; // No 1s found
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};

int main() {
    Solution sol;

    // Sample grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int area = sol.minimumArea(grid);
    cout << "Minimum area enclosing all 1s: " << area << endl;

    return 0;
}
