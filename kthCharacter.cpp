#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1) return 'a';
        string s = "a";
        string ans;
        while(s.size() < k){
            ans = s;
            for(char ch : s){
                ans += ch + 1;
            }
            s = ans;
        }
        return ans[k-1];
    }
};
int main(){
    Solution obj;
    cout<<obj.kthCharacter(5);
    return 0;
}