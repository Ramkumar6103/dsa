#include<bits/stdc++.h>
using namespace std;
bool divideArray(vector<int>& nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i=i+2){
        if(nums[i] != nums[i+1]) return false;
    }
    return true;
}
int main(){
    vector<int> nums = {3,2,3,2,2,2};
    cout<<divideArray(nums);
    return 0;
}