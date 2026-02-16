#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printSubsequence(int index, vector<int>& arr, vector<int>& temp){
        if(index >= arr.size()){
            if(temp.size() == 0){
                cout<<"{}";
            }
            else{
                for(int i : temp) cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        temp.push_back(arr[index]);
        printSubsequence(index+1, arr, temp);
        temp.pop_back();
        printSubsequence(index+1, arr, temp);
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 2, 3};
    vector<int> temp;

    obj.printSubsequence(0, arr, temp);
    return 0;
}
