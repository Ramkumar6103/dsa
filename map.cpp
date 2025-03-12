#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = { 1,2,5,2,1};
    map<int,int> mpp;
    for(int i=0;i<5;i++)
    {
        mpp[arr[i]]++;
    }
    for(int i=0;i<mpp.size();i++)
    {
        cout<<mpp[i];
    }
    for(auto it:mpp)
    {
        cout<<it.first<<" : "<<it.second<<endl;
    }
    return 0;
}