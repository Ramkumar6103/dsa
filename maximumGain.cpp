#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string first;
        string second;
        int firstval, secondval;
        if(x >= y){
            firstval = x;
            secondval = y;
            first = "ab";
            second = "ba";
        }
        else{
            firstval = y;
            secondval = x;
            first = "ba";
            second = "ab";
        }
        string temp;
        stack<char> st;
        for(char ch : s){
            if(!st.empty() && st.top() == first[0] && ch == first[1]){
                res += firstval;
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());

        for(char ch : temp){
            if(!st.empty() && st.top() == second[0] && ch == second[1]){
                res += secondval;
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return res;
    }
};

int main() {
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;
    
    // cout << "Enter the string: ";
    // cin >> s;
    // cout << "Enter gain for 'ab': ";
    // cin >> x;
    // cout << "Enter gain for 'ba': ";
    // cin >> y;

    Solution sol;
    int result = sol.maximumGain(s, x, y);
    // sol.maximumGain(s, x, y);
    cout << "Maximum gain: " << result << endl;

    return 0;
}
