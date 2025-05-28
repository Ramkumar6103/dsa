#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string currStr = "";
                while(st.top() != '['){
                    currStr = st.top() + currStr;
                    st.pop();
                }
                st.pop();

                string currNum = "";
                while(!st.empty() && isdigit(st.top())){
                    currNum = st.top() + currNum;
                    st.pop();
                }

                int k_times = stoi(currNum);
                while(k_times--){
                    for(int p=0;p<currStr.size();p++){
                        st.push(currStr[p]);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// **Main function to test the decodeString function**
int main() {
    Solution sol;
    string s = "3[a2[c]]";
    
    // cout << "Enter an encoded string: ";
    // cin >> s;
    
    string decoded = sol.decodeString(s);
    cout << "Decoded string: " << decoded << endl;
    
    return 0;
}
