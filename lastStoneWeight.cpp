#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x != y) pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    // Call the function and print the result
    int result = sol.lastStoneWeight(stones);
    cout << "Last stone weight: " << result << endl;

    return 0;
}
