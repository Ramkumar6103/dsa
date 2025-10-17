#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    static int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), qz = queries.size();
        vector<vector<int>> qEnd(n);
        for (int i = 0; i < qz; i++)
            qEnd[queries[i][0]].push_back(queries[i][1]);

        priority_queue<int> pq; // max heap for ends of queries
        vector<int> cntQ(n + 1, 0); // number of overlapping queries ending at i
        int dec = 0;

        for (int i = 0; i < n; i++) {
            const int x = nums[i];
            dec += cntQ[i]; // current max possible number for decrementing
            for (int j : qEnd[i])
                pq.push(j); // push ends of queries starting at i

            int k;
            while (x > dec && !pq.empty() && (k = pq.top()) >= i) {
                cntQ[k + 1]--;
                pq.pop();
                dec++;
            }

            if (x > dec)
                return -1;
        }

        return pq.size();
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 1, 1, 0};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}};

    int result = Solution::maxRemoval(nums, queries);
    cout << "Maximum number of queries that can be removed: " << result << endl;

    return 0;
}
