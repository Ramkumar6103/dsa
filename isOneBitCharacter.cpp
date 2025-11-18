#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1)
            i += bits[i] + 1;
        return i == n - 1;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> bits1 = {1, 0, 0};
    cout << "Test 1: " << (sol.isOneBitCharacter(bits1) ? "true" : "false") << endl; // Output: true

    // Example 2
    vector<int> bits2 = {1, 1, 1, 0};
    cout << "Test 2: " << (sol.isOneBitCharacter(bits2) ? "true" : "false") << endl; // Output: false

    // Example 3
    vector<int> bits3 = {0};
    cout << "Test 3: " << (sol.isOneBitCharacter(bits3) ? "true" : "false") << endl; // Output: true

    return 0;
}
