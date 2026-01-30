#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<int> leaderArray(vector<int>& arr){
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i] > maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    arr = obj.leaderArray(arr);
    for(int n : arr){
        cout<<n<<" ";
    }
    return 0;
}