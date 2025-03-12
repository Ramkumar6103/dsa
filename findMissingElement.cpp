#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nums[] = {9,6,3,8,0,1,2,5,10,7};
            int n = size(nums);
        int sum = (n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
            sum = sum - nums[i]; 
        }
        cout<<"Missing element: "<<sum;
    return 0;
}