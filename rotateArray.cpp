#include<bits/stdc++.h>
using namespace std;
int main()
{
    //int nums[]={1,2,3,4,5,6,7};
    //int n = size(nums)-1;
    //int k = 3;
        // for(int i=0;i<k;i++)
        // {
        //     int temp = nums[n];
        //     for(int j=n;j>=0;j--)
        //     {
        //         nums[j] = nums[j-1];
        //     }    
        //     nums[0] = temp;
        // }
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);
        nums.push_back(5);
        nums.push_back(6);
        nums.push_back(7);
        int k = 3;
        k = k % 10;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        for(auto it:nums)
        {
            cout<<it<<" ";
        }
    return 0;
}