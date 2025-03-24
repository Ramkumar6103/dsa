#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        int ans = 0; // To count the free days
        int prev = 0; // Tracks the end of the last meeting
        
        for (auto meet : meetings) {
            // Count free days between previous meeting's end and the start of the current meeting
            if (meet[0] > prev) ans += meet[0] - prev - 1;
            // Update the end of the last meeting
            prev = max(prev, meet[1]);
        }
        
        // Add the free days after the last meeting ends
        if (days > prev) {
            ans += days - prev;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int days = 10;
    vector<vector<int>> meetings = {{1, 3}, {5, 6}, {8, 9}};
    cout << "Free days: " << sol.countDays(days, meetings) << endl;
    return 0;
}
