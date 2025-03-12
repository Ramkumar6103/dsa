#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main()
{
    string s = "the    sky is    blue";
    // string temp,word;
    // stack<string> st;
    // stringstream ss(s);
    // while(getline(ss,word,' '))
    // {
    //     if(!word.empty())
    //     {
    //         st.push(word);
    //     }
    // }
    // while(!st.empty())
    // {
    //     temp += st.top();
    //     st.pop();
    //     if(!st.empty())
    //     {
    //         temp += " ";
    //     }
    // }
    // reverse(s.begin(), s.end());
    // for(int i=0;i<size(temp);i++)
    // {
    //     cout<<temp[i];
    // }
    // for(int i=0;i<size(s);i++)
    // {
    //     cout<<s[i];
    // }
    reverse(s.begin(),s.end());
    int left=0;
    int right=0;
    int k=0;
    int n=s.size();
    while(k<n)
    {
        while(k<n && s[k]==' ')    k++;
        if(k==n)    break;
        while(k<n && s[k]!=' ')
        {
            s[right] = s[k];
            right++;
            k++;
        }
        reverse(s.begin()+left,s.begin()+right);
        s[right] = ' ';
        right++;
        left = right;
        k++;
    }
        s.resize(right-1);
        cout<<s;
    return 0;
}