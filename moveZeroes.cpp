#include <iostream>
#include <vector>
#include <algorithm> // For the swap function

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // Pointer for the position of the next non-zero element
        int j = 0; // Pointer for iterating through the array
        int n = nums.size();
        while (j < n) {
            if (nums[j] != 0) { 
                swap(nums[i], nums[j]); // Swap non-zero element with element at i
                i++; // Move i to the next position
            }
            j++; // Always move j to iterate through the array
        }
    }
};

int main() {
    // Example usage
    vector<int> nums = {0, 1, 0, 3, 12}; // Input array

    Solution solution;
    solution.moveZeroes(nums);

    // Output the modified array
    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
