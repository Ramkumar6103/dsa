#include<bits/stdc++.h>
using namespace std;
    int main()
    {
        // code here
        int arr[] = {32,54,21,12,1,867,32};
        int n = size(arr);
        for(int i=0;i<=n-2;i++)
        {
            int min = i;
            for(int j=i;j<=n-1;j++)
            {
                if(arr[j]<arr[min]) min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
        return 0;
    }
