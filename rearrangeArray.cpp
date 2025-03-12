#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> nums){
        // vector<int> pos;                             //brute force approach
        // vector<int> neg;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i] > 0) pos.push_back(nums[i]);
        //     else if(nums[i] < 0) neg.push_back(nums[i]);
        // }
        // for(int i = 0;i<(n/2);i++){
        //     nums[2*i] = pos[i];
        //     nums[2*i+1] = neg[i];
        // }
        // return nums;

        // int n = nums.size();                            //optimal approach
        // vector<int> ans(n , 0);
        // int pos = 0;
        // int neg = 1;
        // for(int i=0;i<n;i++){
        //     if(nums[i] > 0){
        //         ans[pos] = nums[i];
        //         pos+=2;
        //     }
        //     else if(nums[i] < 0){
        //         ans[neg] = nums[i];
        //         neg+=2;
        //     }
        // }
        // return ans;

        vector<int> pos;                             //if both are not same size
        vector<int> neg;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else if(nums[i] < 0) neg.push_back(nums[i]);
        }
        //cout<<pos.size()<<" "<<neg.size();
        if(pos.size()>neg.size()){
            for(int i=0;i<neg.size();i++){
                ans[2*i] = pos[i];
                ans[2*i+1] = neg[i];
            }
            int index = neg.size() * 2;
            for(int i=neg.size();i<pos.size();i++){
                ans[index] = pos[i];
                index++;
            }
        }
        else{
            for(int i=0;i<pos.size();i++){
                ans[2*i] = pos[i];
                ans[2*i+1] = neg[i];
            }
            int index = pos.size() * 2;
            for(int i=pos.size();i<neg.size();i++){
                ans[index] = neg[i];
                index++;
            }
        }
        return ans;
}
int main(){
    vector<int> nums = {3,1,-2,-5,2,-4,5,6};
    nums = rearrangeArray(nums);
    for(int n : nums){
        cout<<n<<" ";
    }
    return 0;
}