#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> opened(n, false);
        queue<int> q;

        // Add initial boxes
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (opened[box]) continue;
            opened[box] = true;

            totalCandies += candies[box];

            // Add keys found in this box
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    if (hasBox[key] && !opened[key]) {
                        q.push(key);
                    }
                }
            }

            // Add contained boxes
            for (int newBox : containedBoxes[box]) {
                if (!hasBox[newBox]) {
                    hasBox[newBox] = true;
                }
                if ((status[newBox] == 1 || hasKey[newBox]) && !opened[newBox]) {
                    q.push(newBox);
                }
            }
        }

        return totalCandies;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> status         = {1, 0, 1, 0};
    vector<int> candies        = {7, 5, 4, 100};
    vector<vector<int>> keys   = {{}, {}, {1}, {}};
    vector<vector<int>> boxes  = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes   = {0};

    int result = sol.maxCandies(status, candies, keys, boxes, initialBoxes);
    cout << "Maximum candies collected: " << result << endl;

    return 0;
}
