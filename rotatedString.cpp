#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool rotatedString(string s, string goal){
        if(s.size() != goal.size()) return false;
        string NewString = s+s;
        return NewString.find(goal) != string::npos;
    }
};
int main(){
    Solution obj;
    string s,goal;
    cout<<"Enter the string:";
    cin>>s;
    cout<<"Enter the goal:";
    cin>>goal;
    if(obj.rotatedString(s,goal)) cout<<"True";
    else cout<<"False";
    return 0;
}