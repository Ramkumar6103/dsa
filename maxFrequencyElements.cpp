#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        int maxCount = 0;
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
            maxCount = max(maxCount, mpp[num]);
        }
        for (auto [x, y] : mpp) {
            if (y == maxCount) ans += y;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 1, 1, 3, 3}; // Sample input
    int result = sol.maxFrequencyElements(nums);
    cout << "Sum of frequencies of most frequent elements: " << result << endl;
    return 0;
}
