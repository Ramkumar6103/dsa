#include<bits/stdc++.h>
using namespace std;
void printSubSequenceArray(vector<int>& nums,vector<int>& arr,int i,int n){
    if(i >= n){
        for(int a : arr){
            cout<<a<<" ";
        }
        if(arr.size() == 0) cout<<"{}";
        cout<<endl;
        return;
    }
    arr.push_back(nums[i]);
    printSubSequenceArray(nums,arr,i+1,n);
    arr.pop_back();
    printSubSequenceArray(nums,arr,i+1,n);
}
int main(){
    vector<int> nums = {3,1,2};
    vector<int> arr;
    int n = nums.size();
    printSubSequenceArray(nums,arr,0,n);
    return 0;
}