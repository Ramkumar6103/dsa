#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValidOperation(string str){
        int n = str.size();
        if(n == 0) return false;
        // stack<char> stk;
        // int isOpen = 0;
        // bool isThereValue = false;
        // for(char ch : str){
        //     if(ch == '('){
                
        //         stk.push(ch);
        //         isOpen++;
        //     } 
        //     if(isOpen > 0){
        //         if(ch >= 'a' && ch <= 'z'){
        //             stk.push(ch);
        //             isThereValue = true;
        //         }
        //         stk.push(ch);
        //         cout<<ch<<" ";
        //     }
        //     else{
        //         return false;
        //     }
        //     if((ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') && stk.top() == '('){
        //         stk.push(ch);
        //     }
        //     if(ch == ')'){
        //     }
        // }

        int balance = 0;
        char prev = '';
        for(int i=0;i<str.size();i++){
            if(prev == '' && i != 0){
                
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