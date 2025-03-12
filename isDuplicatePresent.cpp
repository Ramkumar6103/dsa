#include<bits/stdc++.h>
using namespace std;
bool isDuplicatePresent(vector<int> &nums){
    //return nums.size() > set<int>(nums.begin(),nums.end()).size();          //one line answer

    int n = nums.size();                                                      //using map
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]] > 1) return true;
    }
    return false;
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,3,1,4};
    cout<<isDuplicatePresent(nums);
    return 0;
}