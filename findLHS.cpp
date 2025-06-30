#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // int n = nums.size();                              // Approach 1
        // sort(nums.begin(),nums.end());
        // int l = 0, r = 1;
        // int res = 0;
        // while(r < n){
        //     while(nums[r] - nums[l] > 1) l++;
        //     if(nums[r] - nums[l] == 1) res = max(res, r - l + 1);
        //     r++;
        // }
        // return res;

        unordered_map<int, int> mpp;                        // Approach 2
        int res = 0;
        for(int n : nums){
            mpp[n]++;
        }
        for(auto [num,freq] : mpp){
            if(mpp.find(num+1) != mpp.end()){
                res = max(res, mpp[num+1]+freq);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int result = solution.findLHS(nums);
    cout << "Length of Longest Harmonious Subsequence: " << result << endl;
    return 0;
}
