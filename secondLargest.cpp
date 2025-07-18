#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int secondLargest(vector<int>& arr){
        if(arr.size() <= 1) return -1;
        int firstLL = INT_MIN;
        int secondLL = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > firstLL){
                secondLL = firstLL;
                firstLL = arr[i];
            }else if(arr[i] > secondLL && arr[i] != firstLL) secondLL = arr[i];
        }
        if(secondLL == INT_MIN){
            return firstLL;
        }
        return secondLL;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {1,2,5,7,6,4};
    cout<<"Second largest element is "<<obj.secondLargest(arr);
    return 0;
}