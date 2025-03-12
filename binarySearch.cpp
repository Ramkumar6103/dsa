#include<bits/stdc++.h>
using namespace std;
// mid = 
// = =
// >
// <
// int binarySearch(int nums[],int n, int target) {
//     int low = 0, high = n - 1 ;
//     int mid;
//     while(low <= high) {
//         mid = (low + high) / 2;
//         if(nums[mid] == target) return mid;
//         else if(target > nums[mid]) low = mid + 1;
//         else if(target < nums[mid]) high = mid - 1;
//     }
//     return -1;
// }
int binarySearch(int nums[],int low,int high,int target) 
{
    if(low>high){
        return -1;        
    }
    int mid = (low+high)/2;
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]){
        return binarySearch(nums,mid+1,high,target);
    }
    else{
        return binarySearch(nums,low,mid-1,target);
    }
}

int main() {
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int low = 0;
    int high = sizeof(nums) - 1 ;
    int x = binarySearch(nums,low,high,target);
    if(x != -1) {
        cout << "The given number is present";
    } else {
        cout << "The given number is not present";    
    }
    return 0;
}
