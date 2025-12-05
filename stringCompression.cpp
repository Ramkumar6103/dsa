#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string stringCompression(string str){
        string ans = "";
        map<char, int> freq;
        for(char ch : str){
            ch = tolower(ch);
            freq[ch]++;
        }
        for(auto x : freq){
            ans += x.first;
            ans += to_string(x.second);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    cout<<sol.stringCompression("aabbcccdde")<<endl;
    cout<<sol.stringCompression("a")<<endl;
    cout<<sol.stringCompression("abcdef")<<endl;
    cout<<sol.stringCompression("aabbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc")<<endl;
    cout<<sol.stringCompression("aaAAAbbB")<<endl;
    return 0;
}