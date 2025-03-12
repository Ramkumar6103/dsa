#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>& arr,int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,3,5,6,6,7,8,9,9,9};
    int target = 6;
    cout<<"Lower Bound:"<<lowerBound(arr,target);
    cout<<"Lower Bound:"<<lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    return 0;
}