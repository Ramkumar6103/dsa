#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int hash[26] = {0};
    string s = "abcdsersdz";
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']++;
    }
    int q,a=0;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(a<q)
    {
        char c;
        cout<<"Enter an alphabet:";
        cin>>c;
        cout<<hash[c-'a']<<endl;
        a++;
    }
    return 0;
}