#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            int num = 0;
            while(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            
            if(s[i] >= 'a' && s[i] <= 'z'){
                for(int j=0;j<=num;j++){
                    cout<<s[i];
                }
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    string s = "22a";
    // cout << "Enter an encoded string: ";
    // cin >> s;
    string decoded = sol.decodeString(s);
    // cout << "Decoded string: " << decoded << endl;
    
    return 0;
}
