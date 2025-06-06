#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            // Check if s[i] and s[i-1] have the same parity (even/odd ASCII codes)
            if ((s[i] & 1) == (s[i - 1] & 1) && s[i] < s[i - 1]) {
                swap(s[i], s[i - 1]);
                break; // Only one swap allowed
            }
        }
        return s;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    string s1 = "4312";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.getSmallestString(s1) << endl;

    // Test Case 2
    string s2 = "987654";
    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << sol.getSmallestString(s2) << endl;

    // Test Case 3
    string s3 = "2468";
    cout << "\nInput: " << s3 << endl;
    cout << "Output: " << sol.getSmallestString(s3) << endl;

    return 0;
}
