#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int totalSum = 0;
        
        // Calculate total sum of the array
        for (int n : nums) {
            totalSum += n;
        }
        
        int leftSum = 0;
        int rightSum = totalSum;
        
        // Iterate through possible partitions
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            
            // Check condition
            if (abs(leftSum + rightSum) % 2 == 0) {
                cnt++;
            }
        }
        
        return cnt;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {1, 2, 3, 4};
    
    int result = sol.countPartitions(nums);
    
    cout << "Number of valid partitions: " << result << endl;
    
    return 0;
}
