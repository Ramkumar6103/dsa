#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(30, 0), res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((nums[i] & (1 << bit)) > 0)
                    lastSeen[bit] = i;
                res[i] = max(res[i], lastSeen[bit] - i + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 2, 1, 3}; // Sample input
    vector<int> result = sol.smallestSubarrays(nums);

    cout << "Result: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
