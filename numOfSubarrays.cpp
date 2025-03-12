#include<bits/stdc++.h>
using namespace std;
int numOfSubarrays(vector<int> arr){

    long long count = 0,sum =0;                              //One solution
    int mod = (int)pow(10,9)+7;
    for(int i = 0;i<arr.size();i++){
        sum = sum + arr[i];
        if(sum % 2 == 1) count++;
    }
    count += (arr.size()-count) * count;
    return count%mod;

    // long long sum = 0, oddcount = 0, evencount = 0;          //Another solution
    // int result = 0;
    // int mod = (int)pow(10,9)+7;
    // for(int n : arr){
    //     sum = sum + n;
    //     if(sum % 2 == 0){
    //         evencount++;
    //         result += evencount;
    //     }
    //     else{
    //         oddcount++;
    //         result += oddcount;
    //     }
    // }
    // return result % mod;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    // vector<int> arr = {2,4,6};
    cout<<numOfSubarrays(arr);
    return 0;
}