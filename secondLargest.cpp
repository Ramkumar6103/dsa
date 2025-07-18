#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int secondLargest(vector<int>& arr){
        int firstLL = arr[0];
        int secondLL = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] > firstLL){
                secondLL = firstLL;
                firstLL = arr[i];
            } 
        }
        return secondLL;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {4,5,3,1,2};
    cout<<"Second largest element is "<<obj.secondLargest(arr);
    return 0;
}