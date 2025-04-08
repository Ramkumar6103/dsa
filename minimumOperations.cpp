#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0; // Count of operations
        unordered_map<int, int> mpp; // Frequency map
        int i = 0; // Pointer for iteration
        int j = 0; // Helper for skipping chunks

        while (i < nums.size()) {
            mpp[nums[i]]++; // Increment frequency count
            if (mpp[nums[i]] > 1) { // Found a duplicate
                j = j + 3; // Skip 3 elements
                i = j; // Update i to skip
                mpp.clear(); // Clear the map
                ans++; // Increment operation count
            } else {
                i++; // Move to the next element
            }
        }

        return ans; // Return total operations
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 2, 3, 4, 2, 5, 6};

    Solution solution; // Create an instance of Solution
    int result = solution.minimumOperations(nums); // Call the function

    // Output the result
    cout << "Minimum operations: " << result << endl;

    return 0;
}
