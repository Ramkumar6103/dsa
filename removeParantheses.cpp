#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "(()())(())";
    string result;
    int balance = 0;
    for(int i=0;i<size(s);i++)
    {
        if(s[i] == '(')
        {
            if(balance>0)
            {
                result += s[i];
            }
            balance++;
        }
        else
        {
            balance--;
            if(balance>0)
            {
                result += s[i];
            }
        }
    } 
    for(char ch:result)
    {
        cout<<ch;
    }
    return 0;
}
