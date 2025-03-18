#include<bits/stdc++.h>
using namespace std;
int longestNiceSubarray(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    int l = 0;
    int r = 0;
    int num = 0;
    while(r < n){
        while((num & nums[r]) != 0){
            num = num ^ nums[l];
            l++;
        }
        num = num | nums[r];
        ans = max(ans, (r-l+1));
        r++;
    }
    return ans;
}
int main(){
    vector<int> nums = {1,3,8,48,10};
    cout<<longestNiceSubarray(nums);
    return 0;
}