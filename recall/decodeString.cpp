#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            int num = 0;
            while(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if(s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z')){
                if(s[i] == '['){
                    i++;
                }
                string temp = "";
                while(i < s.size() && s[i] >= 'a' && s[i] <= 'z' && s[i] != ']'){
                    temp += s[i];
                    i++;
                }
                for(int j=0;j<=num;j++){
                    ans += temp;
                }
            }
            
        }
        cout<<ans;
        return "";
    }
};

int main() {
    Solution sol;
    // string s = "11[ab]";
    string s = "11a";
    // cout << "Enter an encoded string: ";
    // cin >> s;
    string decoded = sol.decodeString(s);
    // cout << "Decoded string: " << decoded << endl;
    
    return 0;
}
