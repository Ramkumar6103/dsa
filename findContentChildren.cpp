#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int l = 0;
    int r = 0;
    while( l < m && r < n){
        if( g[r] <= s[l]){
            r = r+1;
        }
        l = l+1;
    }
    return r;
}
int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> size = {4,2,1,2,1,3};
    cout<<findContentChildren(greed,size);
    return 0;
}