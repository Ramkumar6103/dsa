#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;
            if (freq[num] >= n / 2) {
                return num;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Hardcoded input
    vector<int> nums = {1, 2, 3, 3};

    int result = sol.repeatedNTimes(nums);

    cout << "Repeated element: " << result << endl;

    return 0;
}
