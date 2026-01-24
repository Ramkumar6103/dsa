#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        
        return ans;
    }
};

int main() {
    
    vector<int> nums = {3,5,4,2,4,6};

    Solution obj;
    int result = obj.minPairSum(nums);

    cout << "Minimum possible maximum pair sum = " << result << endl;

    return 0;
}
