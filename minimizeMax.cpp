#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool findPair(vector<int>& nums, int mid, int p) {
        int pairs = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= mid) {  // Pair is valid
                pairs++;
                i++;  // Skip next element since it's already paired
            }
        }
        return pairs >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n-1] - nums[0];
        int ans = 0;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(findPair(nums,mid,p)){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {10,1,2,7,1,3};  // Example input
    int p = 2;  // Number of pairs needed
    
    Solution sol;
    int result = sol.minimizeMax(nums, p);
    
    cout << "Minimum possible maximum difference: " << result << endl;
    
    return 0;
}
