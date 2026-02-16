// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<int> reverseArrayRecursive(vector<int>& nums, vector<int>& ans,int i){
//         if(i == nums.size()){
//             return ans;
//         }
//         reverseArrayRecursive(nums, ans, i+1);
//         ans.push_back(nums[i]);
//         return ans;
//     }
// };
// int main(){
//     Solution obj;
//     vector<int> nums = {1,2,3,4,5};
//     vector<int> ans;
//     obj.reverseArrayRecursive(nums, ans, 0);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void reverseArrayRecursive(vector<int>& nums,int left,int right){
        if(left >= right){
            return;
        }
        swap(nums[left],nums[right]);
        reverseArrayRecursive(nums,left+1, right-1);
    }
};
int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4,5};
    obj.reverseArrayRecursive(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}