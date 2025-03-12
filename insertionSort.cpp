#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={12,523,1,5343,64,124};
    int n=size(a);
    for(int i=0;i<=n-1;i++)
    {
        int j = i;
        while(j>0 && a[j-1]>a[j])
        {
            int temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}