#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {

        vector<int> freq(26,0);
        stack<char> st;
        for(char ch : s){
            freq[ch - 'a']++;
        }
        string result = "";
        char minChar = 'a';
        for(char ch : s){
            st.push(ch);
            freq[ch - 'a']--;
            while(minChar <= 'z' && freq[minChar - 'a'] == 0){
                minChar++;
            }
            while(!st.empty() && minChar >= st.top()){
                result += st.top();
                st.pop();
            }
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1
    string input1 = "zza";
    cout << "Input: " << input1 << endl;
    cout << "Output: " << sol.robotWithString(input1) << endl;  // Expected: "azz"

    // Test Case 2
    string input2 = "bac";
    cout << "\nInput: " << input2 << endl;
    cout << "Output: " << sol.robotWithString(input2) << endl;  // Expected: "abc"

    // Test Case 3
    string input3 = "bdda";
    cout << "\nInput: " << input3 << endl;
    cout << "Output: " << sol.robotWithString(input3) << endl;  // Expected: "addb"

    return 0;
}
