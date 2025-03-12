#include<bits/stdc++.h>
using namespace std;
vector<int> squareOfSortingArray(vector<int> nums){
    int n = nums.size();
    vector<int> v(n);
    int st = 0;
    int end = n-1;
    for(int i=end ; i>=0; i--){
        if(nums[end] * nums[end] > nums[st] * nums[st]){
            v[i] = nums[end] * nums[end];
            end--;
        }
        else{
            v[i] = nums[st] * nums[st];
            st++;
        }
    }
    return v;
}
void printArray(vector<int> nums){
    for(int n : nums){
        cout<<n<<" ";
    }
}
int main(){
    vector<int> nums = {-4,-2,0,5,7,10};
    cout<<"Before the square : ";
    printArray(nums);
    nums = squareOfSortingArray(nums);
    cout<<"\nAfter the square : ";
    printArray(nums);
    return 0;
}