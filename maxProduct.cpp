#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> nums){
    // int maxi = INT_MIN;                                                  //Brute force approach
    // for(int i = 0;i<nums.size();i++){
    //     for(int j = i;j<nums.size();j++){
    //         int product = 1;
    //         for(int k = i;k<=j;k++){
    //             product = product * nums[k];
    //         }
    //         maxi = max(maxi, product);
    //     }
    // }
    // return maxi;    

    // int maxi = INT_MIN;                                                  Better approach
    // for(int i = 0;i<nums.size();i++){
    //     int product = 1;
    //     for(int j = i;j<nums.size();j++){
    //         product = product * nums[j];
    //         maxi = max(product ,maxi);
    //     }
    // }
    // return maxi;

    int maxi = INT_MIN;
    int pref = 1;
    int suf = 1;
    for(int i = 0;i<nums.size();i++){
        if(pref == 0) pref = 1;
        if(suf == 0) suf = 1;
        pref = pref * nums[i];
        suf = suf * nums[nums.size()-i-1];
        maxi = max(maxi, max(pref,suf));
    }
    return maxi;
}
int main(){
    vector<int> nums = {2,3,-2,4};
    cout<<maxProduct(nums);
    return 0;
}