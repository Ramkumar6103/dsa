#include<bits/stdc++.h>
using namespace std;
int longestSumArray(vector<int>& arr, int tgt)
{
    int n = arr.size();
    int len = 0;
    for(int i=0;i<n;i++)
    {
        int sum =0;
        for(int j=i;j<n;j++)
        {
            sum += arr[j];
            if(sum == tgt) len = max(len, j-i+1);
        }
    }
    return len;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    int target = 3;
    cout<<"Longest sum array is "<<longestSumArray(arr,target);
    return 0;
}