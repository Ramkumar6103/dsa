#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxQ = -1;
        vector<int> ans(2, -1);

        for (int i = 0; i < towers.size(); i++) {
            int dx = abs(towers[i][0] - center[0]);
            int dy = abs(towers[i][1] - center[1]);

            double dist = dx + dy;  // Manhattan distance

            if (dist <= radius) {
                if (towers[i][2] > maxQ) {
                    maxQ = towers[i][2];
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                }
                else if (towers[i][2] == maxQ) {
                    // tie-break: lexicographically smallest
                    if (towers[i][0] < ans[0] || 
                       (towers[i][0] == ans[0] && towers[i][1] < ans[1])) {
                        ans[0] = towers[i][0];
                        ans[1] = towers[i][1];
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    // Hardcoded input
    vector<vector<int>> towers = {
        {1, 2, 5},
        {2, 1, 7},
        {3, 3, 4},
        {0, 0, 7}
    };

    vector<int> center = {1, 1};
    int radius = 3;

    Solution sol;
    vector<int> result = sol.bestTower(towers, center, radius);

    cout << "Best Tower Coordinates: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
