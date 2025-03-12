#include<bits/stdc++.h>
using namespace std;
int maximumCount(vector<int> nums){
    int posCount = 0;
    int negCount = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > 0) posCount++;
        else if(nums[i] < 0) negCount++;
    }
    return max(posCount,negCount);
}
int main(){
    vector<int> nums = {-4,-3,-2,-1,0,1,2,3,4,5};
    cout<<maximumCount(nums);
    return 0;
}