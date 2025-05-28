#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // string replaceDigits(string s) {
    //     string ans = "";
    //     for(int i=0;i<s.size();i++){
    //         if(isdigit(s[i])){
    //             char ch = (s[i-1] + (s[i] - '0'));
    //             ans = ans + ch;
    //         }
    //         else{
    //             ans = ans + s[i];
    //         }
    //     }
    //     return ans;
    // } 
    
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0') + s[i - 1];
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Example input
    string input = "a1c1e1";
    // cout << "Enter the string (e.g., a1c1e1): ";
    // cin >> input;

    string result = sol.replaceDigits(input);
    cout << "Result after replacing digits: " << result << endl;

    return 0;
}
