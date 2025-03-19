#include<bits/stdc++.h>
using namespace std;
        void flip(vector<int>& nums, int i){
            if(nums[i] == 0) nums[i] = 1;
            else nums[i] = 0;
        }
        int minOperations(vector<int>& nums) {
            int ans = 0;
            int l = 0;
            int n = nums.size();
            int num = 0;
            while(l < n-2){
                if(nums[l] == 0){
                    flip(nums,l);
                    flip(nums,l+1);
                    flip(nums,l+2);
                    ans++;
                }
                l++;
            }
            if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
            return ans;
        }
int main(){
    vector<int> nums = {0,1,1,1,0,0};
    cout<<minOperations(nums);
    return 0;
}