#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// private:
//     bool helper(vector<int>& ans, int k) {
//         int n = ans.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int an = abs(ans[i] - ans[j]);
//                 if (an > k) return false;
//             }
//         }
//         return true;
//     }

// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n % 3 != 0) return {};  // Ensure division into groups of 3 is possible

//         vector<vector<int>> ans(n / 3, vector<int>(3)); // Initialize 2D vector
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < n; i++) {
//             ans[i / 3][i % 3] = nums[i];  // Assign elements properly
//         }

//         for (auto& group : ans) {
//             if (!helper(group, k)) return {};  // Validate each group
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i+=3){
            if(nums[i+2] - nums[i] <= k){
                res.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else return {};
        }
        return res;
    }
};

int main() {
    // int n, k;
    // cout << "Enter number of elements (must be a multiple of 3): ";
    // cin >> n;
    
    // if (n % 3 != 0) {
    //     cout << "Invalid input! Number of elements must be a multiple of 3." << endl;
    //     return 0;
    // }

    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    // cout << "Enter the elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }

    // cout << "Enter value of k: ";
    // cin >> k;

    Solution sol;
    vector<vector<int>> result = sol.divideArray(nums, k);

    if (result.empty()) {
        cout << "No valid division possible." << endl;
    } else {
        cout << "Divided groups:" << endl;
        for (auto& group : result) {
            for (int num : group) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
