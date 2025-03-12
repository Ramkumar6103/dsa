#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int searchElementRotated(vector<int> &arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return mid;
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
        return -1;
    }
};
int main(){
    vector<int> arr = {7,8,9,0,1,2,3,4,5,6};
    int x = 5;
    Solution obj;
    cout<<"The element is present at the index "<<obj.searchElementRotated(arr,x);
    return 0;
}