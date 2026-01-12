#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int toTime(vector<int>& from, vector<int>& to) {
        int xdiff = abs(from[0] - to[0]);
        int ydiff = abs(from[1] - to[1]);
        return max(xdiff, ydiff);
    }

public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for (int i = 1; i < points.size(); i++) {
            time += toTime(points[i - 1], points[i]);
        }
        return time;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> points = {
        {1, 1},
        {3, 4},
        {-1, 0}
    };

    int result = sol.minTimeToVisitAllPoints(points);

    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}
