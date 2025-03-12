#include<bits/stdc++.h>
using namespace std;
class Solution{
      public:
    int floor(vector<int> &arr,int n, int x){
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]<=x){
			ans = arr[mid];
			low = mid+1;
		}
		else high = mid-1;
	}
	return ans;
}
int ceil(vector<int> &arr,int n, int x){
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low <= high){
		int mid = (low+high)/2;
		if(arr[mid] >= x){
			ans = arr[mid];
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> temp;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        temp.push_back(floor(arr,n,x));
        temp.push_back(ceil(arr,n,x));
        return temp;
    }
};
int main()
{
    vector<int> arr = {1,3,5,6,6,7,8,9,9,9};
    int x = 4;
    Solution obj;
    auto ans = obj.getFloorAndCeil(x,arr);
    cout<<"Floor:"<<ans[0] <<" Ceil: "<< ans[1];
    return 0;
}