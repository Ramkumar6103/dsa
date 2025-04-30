#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int n : nums){
            int soln = abs(log10(n)) + 1;
            if(soln % 2 == 0) ans++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {12, 345, 2, 6, 7896}; // Example input
    Solution solution;
    int result = solution.findNumbers(nums);
    
    cout << "Count of numbers with an even number of digits: " << result << endl;
    
    return 0;
}
