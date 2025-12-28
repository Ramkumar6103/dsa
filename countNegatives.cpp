#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] < 0) {
                    cnt += (m - j);
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    // Inbuilt input
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    Solution obj;
    int result = obj.countNegatives(grid);

    cout << "Number of negative elements: " << result << endl;

    return 0;
}
