#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValidOperation(string str){
        stack<char> stk;
        char prev = ' ';
        for(int i=0;i<str.size();i++){
            char ch = ' ';
            if(ch == '('){
                stk.push(ch);
            }
            else if(ch == ')'){
                if(stk.empty()) return false;
                stk.pop();
            }
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                if(prev == ' ' || prev == '(' || prev == '+' || prev == '-' || prev == '*' || prev == '/'){
                    return false;
                }

            }
            prev = str[i];
        }
        return stk.empty() && !(prev == ' ' || prev == '(' || prev == '+' || prev == '-' || prev == '*' || prev == '/');
    }
};
int main(){
    Solution obj;
    string str = "(a+b)*c";
    // string str = "(a+b)(ab*)";
    if(obj.isValidOperation(str)){
        cout<<"The given string operator and operants are valid";
    }
    else{
        cout<<"The given string operator and operants are invalid";
    }
    return 0;
}