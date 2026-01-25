#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValidOperation(string str){
        int n = str.size();
        if(n == 0) return false;
        stack<char> stk;
        int isOpen = true;
        int isClose = true;
        for(char ch : str){
            if(ch == '(') isOpen++;
            if(isOpen > 0){
                stk.push(ch);
                cout<<ch<<" ";
            }
            if(ch == ')'){

            }
            
        }
        return false;
    }
};
int main(){
    Solution obj;
    string str = "((a+b)(a*b))";
    // string str = "(a+b)(ab*)";
    if(obj.isValidOperation(str)){
        cout<<"The given string operator and operants are valid";
    }
    else{
        cout<<"The given string operator and operants are invalid";
    }
    return 0;
}