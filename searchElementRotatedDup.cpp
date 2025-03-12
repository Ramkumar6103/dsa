#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int searchElementRotatedDup(vector<int> &arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return true;
            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
                continue;
            }
            //left sorted
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            //right sorted
            else{
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
int main(){
    vector<int> arr = {3,0,1,2,3,3,3,3};
    int x = 1;
    Solution obj;
    int ans= obj.searchElementRotatedDup(arr,x);
    if(ans == true) cout<<"Element is present";
    else cout<<"Element is not present";
    return 0;
}