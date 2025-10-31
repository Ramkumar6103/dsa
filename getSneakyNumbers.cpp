#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
            if (cnt[num] == 2) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2, 4, 5, 1, 6, 3, 3};
    
    vector<int> sneaky = sol.getSneakyNumbers(nums);
    
    cout << "Sneaky numbers (appearing exactly twice): ";
    for (int num : sneaky) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
