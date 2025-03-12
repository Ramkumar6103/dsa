#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string sortingCharFreq(string s){
        string ans;
        unordered_map<char,int> mp;
        for(auto c: s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto d: mp){
            pq.push({d.second,d.first});
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans+=string(top.first,top.second);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"The sorting frequency of a characters: "<<obj.sortingCharFreq(s);
    return 0;
}