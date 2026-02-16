#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printSubsequenceSum(int index,
                             vector<int>& arr,
                             vector<int>& temp,
                             int sum,
                             int target)
    {
        if(index == arr.size()){
            if(sum == target){
                for(int i : temp){
                    cout<<i<<" ";
                }
                cout<<endl;
                
            }
            return;
        }

        temp.push_back(arr[index]);
        printSubsequenceSum(index+1, arr, temp, sum + arr[index], target);
        temp.pop_back();
        printSubsequenceSum(index+1, arr, temp, sum, target);
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 2, 1};
    int target = 2;
    vector<int> temp;

    obj.printSubsequenceSum(0, arr, temp, 0, target);
    return 0;
}
