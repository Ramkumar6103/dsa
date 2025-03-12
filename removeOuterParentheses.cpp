#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string removeOuterParentheses(string s){
        int bal = 0;
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                bal++;
                if(bal > 1) str+=s[i];
            }
            else{
                bal--;
                if(bal>=1) str+=s[i];
            }
        }
        return str;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter the parentheses:";
    cin>>s;
    cout<<obj.removeOuterParentheses(s);
    return 0;
}