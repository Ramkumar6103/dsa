#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> array;
        int rem = grid[0][0] % x;

        // Step 1: Insert array elements and check remainder compatibility
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] % x != rem) {
                    return -1;
                }
                array.push_back(grid[i][j]);
            }
        }

        // Step 2: Sort 1D array
        sort(array.begin(), array.end());
        int n = array.size();
        int median = array[n / 2];

        // Step 3: Count steps required
        int steps = 0;
        for (int i = 0; i < n; ++i) {
            steps += abs(array[i] - median) / x;
        }

        return steps;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;

    // Function call and output
    int result = sol.minOperations(grid, x);
    if (result != -1) {
        cout << "Minimum number of operations: " << result << endl;
    } else {
        cout << "Transformation is not possible." << endl;
    }

    return 0;
}
