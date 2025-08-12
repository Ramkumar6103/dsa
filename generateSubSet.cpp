#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateSubset(vector<int>& nums, vector<int>& current, int index) {
        
        if(index == nums.size()){
            return {current}; // Return the current subset
        }

        vector<vector<int>> subsets;
        //include the current index element
        current.push_back(nums[index]);
        vector<vector<int>> include = generateSubset(nums,current,index+1);
        subsets.insert(subsets.end(), include.begin(), include.end());

        //exclude the current index element
        current.pop_back();
        vector<vector<int>> exclude = generateSubset(nums, current, index + 1);
        subsets.insert(subsets.end(), exclude.begin(), exclude.end());
        return subsets;
    }
};
int main() {
    Solution sol;

    int n = 3;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> subsets;
    vector<int> current;

    subsets = sol.generateSubset(nums, current, 0);

    cout << "Subsets are:\n";
    for (auto subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    return 0;
}