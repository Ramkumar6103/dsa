#include <iostream>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long ls = 0;
        int cases = 0;
        for (int num : nums) {
            long long rs = total - ls - num;
            if (num == 0) {
                if (ls == rs) {
                    cases += 2;
                } else if (ls == rs - 1 || ls - 1 == rs) {
                    cases++;
                }
            }
            ls += num;
        }
        return cases;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 0, 1, 0, 1};
    int result = sol.countValidSelections(nums);

    cout << "Number of valid selections: " << result << endl;

    return 0;
}
