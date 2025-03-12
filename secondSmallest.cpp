#include<bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr) {
        // Code Here
        int l = arr[0];
        int sl = -1;
        for(int i=0;i<arr.size();i++)
        {
            if(l<arr[i])
            {
                sl = l;
                l = arr[i];
            }
            else if(l>arr[i] && arr[i]> sl)
            {
                sl = arr[i];
            }
        }
        return sl;
    }
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(4);
    cout<<"The array elements are:";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<"\nSecond smallest element: "<<getSecondLargest(arr);
    return 0;
}