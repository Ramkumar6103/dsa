#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
    /*
    int ans = 0;
        int n = 0;
        for(int i=size(s)-1;i>=0;i--){
            switch(s[i]){
                case 'I': n = 1; break;
                case 'V': n = 5; break;
                case 'X': n = 10; break;
                case 'L': n = 50; break;
                case 'C': n = 100; break;
                case 'D': n = 500; break;
                case 'M': n = 1000; break;
            }
            if(4*n<ans){
                ans = ans - n;
            }
            else{
                ans = ans + n;
            }
        }
        return ans;
    }
    */
};
int main(){
    Solution obj;
    string s = "MCMXCIV";
    cout<<obj.romanToInt(s);
    return 0;
}