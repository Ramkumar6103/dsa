#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> busy(n, 0); // Room end times
        vector<int> count(n, 0);      // Booking counts per room

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            long long earliest = LLONG_MAX;
            int roomIndex = -1;
            bool assigned = false;

            for (int i = 0; i < n; ++i) {
                if (busy[i] < earliest) {
                    earliest = busy[i];
                    roomIndex = i;
                }
                if (busy[i] <= start) {
                    busy[i] = end;
                    count[i]++;
                    assigned = true;
                    break;
                }
            }

            if (!assigned) {
                busy[roomIndex] += (end - start);
                count[roomIndex]++;
            }
        }

        int res = 0, maxCount = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                res = i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example test case: 2 rooms, 4 meetings
    vector<vector<int>> meetings = {
        {0, 10},
        {1, 5},
        {2, 7},
        {3, 4}
    };
    int n = 2;

    int result = sol.mostBooked(n, meetings);
    cout << "Most booked room: " << result << endl;

    return 0;
}
