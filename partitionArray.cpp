#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         vector<int> res;
//         int i = 0, j = i + 1;
//         res.push_back(nums[0]);

//         while (i < n && j < n) {
//             while (j < n && nums[j] - nums[i] <= k) {
//                 res.push_back(nums[j]);
//                 j++;
//             }
//             ans.push_back(res);
//             res.clear();
//             if (j < n) res.push_back(nums[j]);
//             i = j;
//             j = i + 1;
//         }

//         while (i < n) {
//             ans.push_back({nums[i]});
//             i++;
//         }

//         // Optional: print the groups
//         cout << "Partitions:" << endl;
//         for (const auto& group : ans) {
//             for (int num : group) {
//                 cout << num << " ";
//             }
//             cout << endl;
//         }

//         return ans.size();
//     }
// };


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 1;
        int start = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] - start > k){
                count++;
                start = nums[i];
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3};
    int k = 1;
    int result = solution.partitionArray(nums, k);
    cout << "Total number of partitions: " << result << endl;
    return 0;
}
