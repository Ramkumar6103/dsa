#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findPeak(vector<int> &nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] > nums[1]) return nums[0];
        if(nums[n-1] > nums[n-2]) return nums[n-1];
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return nums[mid];
            else if(nums[mid-1]>nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};
int main(){
    vector<int> arr = {1,2,3,2,1,0,-1};
    Solution obj;
    cout<<"The peak element index is "<<obj.findPeak(arr);
    return 0;
}