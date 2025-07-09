#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
//         int count = startTime.size();
//         vector<int> prefixSum(count + 1, 0);
//         int maxFree = 0;

//         for (int i = 0; i < count; ++i) {
//             prefixSum[i + 1] = prefixSum[i] + (endTime[i] - startTime[i]);
//         }

//         for (int i = k - 1; i < count; ++i) {
//             int occupied = prefixSum[i + 1] - prefixSum[i - k + 1];
//             int windowEnd = (i == count - 1) ? eventTime : startTime[i + 1];
//             int windowStart = (i == k - 1) ? 0 : endTime[i - k];
//             int freeTime = windowEnd - windowStart - occupied;
//             maxFree = max(maxFree, freeTime);
//         }

//         return maxFree;
//     }
// };

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime[n-1]);
        int currTime = 0;
        for(int i=0;i<k+1;i++) currTime += freeTime[i];
        int maxFreeTime = currTime;
        for(int i=k+1;i<freeTime.size();i++){
            currTime += freeTime[i] - freeTime[i-(k+1)];
            maxFreeTime = max(currTime,maxFreeTime);
        }
        return maxFreeTime;
    }
};

int main() {
    Solution sol;

    // Example input
    int eventTime = 20;
    int k = 2;
    vector<int> startTime = {1, 5, 10, 15};
    vector<int> endTime = {3, 7, 12, 18};

    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time between any " << k << " consecutive events: " << result << endl;

    return 0;
}
