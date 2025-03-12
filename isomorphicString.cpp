#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isomorphicString(string s, string t){
        unordered_map<char,char> mp1, mp2;
        for(int i=0;i<s.size();i++){
            if(mp1[s[i]] && mp1[s[i]] != t[i]) return false;
            if(mp2[t[i]] && mp2[t[i]] != s[i]) return false;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};
int main(){
    Solution obj;
    string s,t;
    //Strings should be have the same length...
    cout<<"Enter the first string: ";
    cin>>s;
    cout<<"Enter the second string: ";
    cin>>t;
    if(obj.isomorphicString(s,t)) cout<<"The strings are isomorphic";
    else cout<<"The strings are not isomorphic";
    return 0;
}