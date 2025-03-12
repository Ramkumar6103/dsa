#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countSubArraySum(vector <int>& nums, int k){
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1,1,2,3};
    int k = 3;
    int ans = obj.countSubArraySum(nums, k);
    cout << "Count the sum of subarray: " << ans << "\n";
    return 0;
}