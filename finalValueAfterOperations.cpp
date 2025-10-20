#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string str : operations) {
            if (str == "++X" || str == "X++") {
                ans++;
            } else if (str == "--X" || str == "X--") {
                ans--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<string> operations = {"++X", "X++", "--X", "X--", "++X"};
    
    // Call the function and print the result
    int result = sol.finalValueAfterOperations(operations);
    cout << "Final value after operations: " << result << endl;

    return 0;
}
