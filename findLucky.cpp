#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // for max
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> mpp;

        // Count frequency of each number
        for (int n : arr) {
            mpp[n]++;
        }

        // Check for lucky numbers
        for (auto [x, y] : mpp) {
            if (x == y) {
                ans = max(ans, y);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> arr = {2, 2, 3, 4};

    // Call the function and print the result
    int result = sol.findLucky(arr);
    cout << "The largest lucky number is: " << result << endl;

    return 0;
}
