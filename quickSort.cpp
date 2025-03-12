#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(arr[i]<=pivot && i <= high-1)
        {
            i++;
        }
        while(arr[j]>pivot && j >= low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    int pIndex;
    if(low<high)
    {
        pIndex = partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}
int main()
{
    //int arr[] = {3,1,6,2,9,5,4};
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(4);
    cout<<"Before quick sort:";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }

    quickSort(arr,0,size(arr)-1);
    cout<<"\n";
    cout<<"After quick sort:";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}