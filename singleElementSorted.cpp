#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int singleElementSorted(vector<int> &nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid % 2 == 1 && nums[mid-1] == nums[mid] || mid % 2 == 0 && nums[mid+1] == nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5};
    Solution obj;
    cout<<"The single element is "<<obj.singleElementSorted(arr);
    return 0;
}