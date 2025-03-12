#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int low,int mid,int high)
    {
        int left=low;
        int right=mid+1;
        vector<int> temp;
        
        while(left <= mid && right<=high)
        {
            if(arr[left]<arr[right])
            {
                temp.push_back(arr[left]);
                //temp[left] = arr[left];
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                //temp[right] = arr[right];
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            //temp[left] = arr[left];
            left++;
        }
        while(right<=high)
        {
            temp.push_back(arr[right]);
            //temp[right] = arr[right];
            right++;
        }
        for(int i=low;i<=high;i++)
        {
            arr[i] = temp[i-low];
        }
    }
    void mergeSort(int arr[], int low, int high) 
    {
        // code here
        int mid = (low+high)/2;
        if(low==high) return;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
int main()
{
    //vector<int> arr;
    // arr.push_back(234);
    // arr.push_back(31);
    // arr.push_back(10);
    // arr.push_back(54);
    // arr.push_back(64);
    int n;
    
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter an array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    // for(vector<int>::iterator it=arr.begin();it!=arr.end();it++)
    // {
    //     cout<<*(it)<<" ";
    // }
    for(int i=0;i<5;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
    return 0;
}