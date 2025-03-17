#include<bits/stdc++.h>
using namespace std;
bool increasingTriplet(vector<int>& nums){
    int a = INT_MAX;
    int b = INT_MAX;
    for(int n : nums){
        if(n <= a) a = n;
        else if(n <= b) b = n;
        else return true;
    }
    return false;
}
int main(){
    vector<int> nums = {20,100,5,43,25,104};
    cout<<increasingTriplet(nums);
    return 0;
}