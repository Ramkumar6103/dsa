#include<bits/stdc++.h>
using namespace std;
        // code here
    int main()
    {
        int arr[]={12,76,232,122,97,345};
        int n = size(arr);
        for(int i=n-1;i>=1;i--)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
        return 0;
    }