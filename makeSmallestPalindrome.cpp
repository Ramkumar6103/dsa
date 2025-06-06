#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                // Replace the larger character with the smaller one
                if (s[i] < s[j]) {
                    s[j] = s[i];
                } else {
                    s[i] = s[j];
                }
            }
            i++;
            j--;
        }
        return s;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "egcfe";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.makeSmallestPalindrome(s1) << endl;

    // Test Case 2
    string s2 = "abcd";
    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << sol.makeSmallestPalindrome(s2) << endl;

    // Test Case 3
    string s3 = "seven";
    cout << "\nInput: " << s3 << endl;
    cout << "Output: " << sol.makeSmallestPalindrome(s3) << endl;

    return 0;
}
