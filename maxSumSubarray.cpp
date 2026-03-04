#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int windowSum = 0;
    int ans = 0;
    int l = 0;
    //First Window
    for(int i=0;i<k;i++){
        windowSum += arr[i];
    }
    ans = windowSum;
    for(int r=k;r<n;r++){
        // windowSum += arr[r];
        // windowSum -= arr[l];

        windowSum += arr[r] - arr[r - k];
        ans = max(ans, windowSum);
    }
    return ans;
}

int main() {
    vector<int> arr = {2,1,5,1,3,2};
    int k = 3;
    
    cout << "Maximum Sum: " << maxSumSubarray(arr, k);
    
    return 0;
}