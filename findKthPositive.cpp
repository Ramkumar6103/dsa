#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> nums, int k){
    int low = 0;
    int high = nums.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing = nums[mid] - (mid+1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    return high + 1 + k;
}
int main(){
    vector<int> nums = {2,3,4,7,11};
    cout<<findKthPositive(nums,5);
    return 0;
}