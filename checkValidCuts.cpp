#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int sections = 0;
        int max_end = intervals[0][1];
        
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (max_end <= start) {
                sections++;
            }
            max_end = max(max_end, end);
        }
        
        return sections >= 2;
    }
    
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_intervals, y_intervals;
        
        for (auto& rect : rectangles) {
            x_intervals.push_back({rect[0], rect[2]});
            y_intervals.push_back({rect[1], rect[3]});
        }
        
        return check(x_intervals) || check(y_intervals);
    }
};

int main() {
    Solution sol;
    int n = 3;  // Example number of rectangles
    vector<vector<int>> rectangles = {
        {1, 1, 3, 3},
        {4, 1, 6, 3},
        {7, 1, 9, 3}
    };
    
    if (sol.checkValidCuts(n, rectangles)) {
        cout << "The rectangles can be validly cut into at least two sections." << endl;
    } else {
        cout << "The rectangles cannot be validly cut into at least two sections." << endl;
    }

    return 0;
}
