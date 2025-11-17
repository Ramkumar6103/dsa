#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        bool firstOneFound = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (firstOneFound && cnt < k) {
                    return false;
                }
                firstOneFound = true;
                cnt = 0;
            } else {
                if (firstOneFound) {
                    cnt++;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Sample test case
    vector<int> nums = {1, 0, 0, 0, 1, 0, 0, 1};
    int k = 2;

    bool result = sol.kLengthApart(nums, k);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
