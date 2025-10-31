#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int n : nums) {
            mpp[n]++;
            if (mpp[n] == 2) { // Only add when it becomes a duplicate
                ans.push_back(n);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = sol.findDuplicates(nums);

    cout << "Duplicates in the array: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
