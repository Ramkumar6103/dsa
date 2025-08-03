#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int maxBal = 0;
        int i = 0;
        int j = i + 1;
        int n = nums.size();

        while (i < n - 1 && j < n) {
            int prev = nums[i];

            if (prev < nums[j]) {
                i++;
                j++;
            } 
            else if (nums[j] < prev) {
                maxBal++;
                i = j + 1;
                j = j + 2;
            } 
            else {
                i++;
                j++;
            }
        }
        return maxBal;
    }
};

int main() {
    Solution sol;
    vector<int> shipments = {5, 3, 6, 2, 4, 1};
    int result = sol.maxBalancedShipments(shipments);
    cout << "Maximum balanced shipments: " << result << endl;
    return 0;
}
