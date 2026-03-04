#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        string curr = "";
        int num = 0;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            
            else if(s[i] == '[') {
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            
            else if(s[i] == ']') {
                int repeat = numStack.top();
                numStack.pop();
                
                string temp = curr;
                curr = strStack.top();
                strStack.pop();
                
                while(repeat--) {
                    curr += temp;
                }
            }
            
            else { // character case
                
                if(num > 0) {
                    // case like 11a
                    while(num--) {
                        curr += s[i];
                    }
                    num = 0;
                } else {
                    curr += s[i];
                }
            }
        }
        
        return curr;
    }
};

int main() {
    Solution sol;

    cout << sol.decodeString("11a") << endl;        // aaaaaaaaaaa
    cout << sol.decodeString("3[a]") << endl;       // aaa
    cout << sol.decodeString("3[a2[c]]") << endl;   // accaccacc
    
    return 0;
}