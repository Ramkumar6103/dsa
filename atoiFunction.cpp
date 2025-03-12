#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int atoiFunction(string s){
        int result = 0;
        int sign = 1;
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        while(i < s.size()){
            if(s[i]>='0' && s[i]<='9'){
                result = result*10 + (s[i] - '0');
                if(result > INT_MAX && sign == -1)
                return -1;
                if(result > INT_MAX && sign == 1)
                return -1;
                i++;
            }
            else return result*sign;
        }
        return result*sign;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a number in string: ";
    cin>>s;
    cout<<obj.atoiFunction(s);
    return 0;
}