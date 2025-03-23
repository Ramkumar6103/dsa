// Online Judge: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time Complexity: O(N log N) - due to sorting
// Space Complexity: O(1) - in-place operations, no extra space required

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        // Sort the array in ascending order
        sort(begin(A), end(A));
        
        long i = 0, N = A.size(), ans = 1, sum = 0;

        for (int j = 0; j < N; ++j) {
            sum += A[j]; // Add the current element to the cumulative sum

            // Check if the current window is valid (can all elements in the window become equal)
            while ((j - i + 1) * A[j] - sum > k) {
                // Shrink the window from the left by removing A[i]
                sum -= A[i++];
            }

            // Update the maximum frequency
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> A = {1, 2, 4};
    int k = 5;

    int result = solution.maxFrequency(A, k);
    cout << "Maximum Frequency: " << result << endl;

    return 0;
}
