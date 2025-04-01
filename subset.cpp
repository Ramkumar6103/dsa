#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(result,current,nums,0);
        return result;
    }
    
private:
    void generateSubsets(vector<vector<int>>& result, vector<int>& current, vector<int>& nums, int index) {
        if(index == nums.size()){
            result.push_back(current);
            return;
        }
        generateSubsets(result,current,nums,index+1);
        current.push_back(nums[index]);
        generateSubsets(result,current,nums,index+1);
        current.pop_back();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};  // Input array
    vector<vector<int>> result = solution.subsets(nums);

    // Print the subsets
    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
