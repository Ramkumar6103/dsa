#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int gap = 3;
    for(int i=gap;i<sizeof(arr) / sizeof(arr[0]);i++){
        arr[i % gap] += arr[i];
    }
    cout<<"Sum of gap between the numbers:"<<endl;
    for(int i=0;i<gap;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}