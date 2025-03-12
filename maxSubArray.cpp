#include<bits/stdc++.h>
using namespace std;
vector<int> printMaxSubArray(vector<int> nums){
    vector<int> ans;
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = 0;
    int ansEnd = 0;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i;
        sum = sum+nums[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    for(int i = ansStart;i<=ansEnd;i++){
        ans.push_back(nums[i]);
    }
    return ans;
}
int maxSubArray(vector<int> nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + nums[i];
        maxi = max(sum , maxi);
        if(sum < 0) sum = 0;
    }
    return maxi;
}
int main(){
    vector<int> nums = {-2,-1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
    cout<<endl;
    vector<int> maxSubArrayElements = printMaxSubArray(nums);
    cout << "Maximum Subarray: ";
    for(int num : maxSubArrayElements) {
        cout << num << " ";
    }
    return 0;
}