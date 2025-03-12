#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countDeepestParentheses(string s){
        int bal = 0;
        int maxi = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                bal++;
                maxi = max(maxi, bal);
            }
            else{
                bal--;
            }
        }
        return maxi;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter the parentheses:";
    cin>>s;
    cout<<obj.countDeepestParentheses(s);
    return 0;
}