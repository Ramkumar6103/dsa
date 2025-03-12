#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nums[]={1,1,2,2,3,3,3,4,5,6,6,7,7,7,8};
    int i=0;
    for(int j=1;j<size(nums);j++)
    {
        if(nums[j]!=nums[i])
        {
            nums[i+1]=nums[j];
            i++;  
        }
    }
            for(int x=0;x<=i;x++)
            {
                cout<<nums[x]<<" ";
            }
    return 0;
}