#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        freq[0] = 1;   // base case
        
        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            int remainder = prefixSum % k;

            // Handle negative remainder
            if (remainder < 0)
                remainder += k;

            // If this remainder seen before
            if (freq.count(remainder)) {
                count += freq[remainder];
            }

            // Increase frequency
            freq[remainder]++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = obj.subarraysDivByK(nums, k);

    cout << "Number of subarrays divisible by k: " << result << endl;

    return 0;
}