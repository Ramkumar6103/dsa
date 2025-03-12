#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumRotatedArray(vector<int> &nums){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = nums[0];
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[high]){
                mini = min(nums[low], mini);
                break;
            }
            //left sorted
            if(nums[low] <=nums[mid]){
                if(nums[low]<mini) mini = nums[low];
                low = mid + 1;
            }
            else{
                if(nums[mid]<mini) mini = nums[mid];
                high = mid - 1;
            }
        }
        return mini;
    }
};
int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    Solution obj;
    cout<<"The minimum element is "<<obj.minimumRotatedArray(arr);
    return 0;
}