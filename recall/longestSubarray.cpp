#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int target){
        int l = 0, r = 0, sum = 0, maxlen = 0, n = nums.size();
        while(r < n){
            sum = sum + nums[r];
            // while(sum > target){
            if(sum > target){
                sum = sum - nums[l];
                l++;
            }
            if(sum <= target){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5, 1, 4, 2, 9};
    int target = 9;
    cout<<obj.longestSubarray(nums, target);
    return 0;
}

