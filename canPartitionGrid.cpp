#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        // Calculate total sum of grid
        for (auto &row : grid)
            for (int x : row)
                total += x;

        // If total is odd, can't divide equally
        if (total % 2) return false;

        long long target = total / 2, sum = 0;

        // Check horizontal cuts
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        // Check vertical cuts
        sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[j][i];
            }
            if (sum == target) return true;
        }

        return false;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    bool result = obj.canPartitionGrid(grid);

    if (result)
        cout << "True - Grid can be partitioned into two equal-sum parts.\n";
    else
        cout << "False - Grid cannot be partitioned into two equal-sum parts.\n";

    return 0;
}