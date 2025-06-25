#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    long countPositive(int a, vector<int>& nums, long long mid){
        int low = 0;
        int high = nums.size();
        while(low < high){
            int m = low + (high - low) / 2;
            if((long)a * nums[m] <= mid){
                low = m + 1;
            }
            else{
                high = m;
            }
        }
        return low;
    }
    long countNegative(int a, vector<int>& nums, long long mid){
        int low = 0;
        int high = nums.size();
        while(low < high){
            int m = low + (high - low) / 2;
            if((long)a * nums[m] <= mid){
                high = m;
            }
            else{
                low = m + 1;
            }
        }
        return nums.size() - low;
    }
    long countLessOrEqual(long long mid, vector<int>& nums1, vector<int>& nums2){
        long count = 0;
        for(int a : nums1){
            if(a >= 0) count += countPositive(a, nums2, mid);
            else count += countNegative(a, nums2, mid);
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -pow(10,10);
        long long right = pow(10,10);
        while(left < right){
            long long mid = left + (right - left) / 2;
            if(countLessOrEqual(mid, nums1, nums2) < k){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums1 = {2,5};
    vector<int> nums2 = {3,4};
    long long k = 2;

    Solution sol;
    cout << "The " << k << "rd smallest product is: " 
         << sol.kthSmallestProduct(nums1, nums2, k) << endl;

    return 0;
}
