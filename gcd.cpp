#include<bits/stdc++.h>
using namespace std;
void findGcd(int m,int n)
{
    while(m>0 && n>0)
    {
        if(m>n) m=m%n;
        else n=n%m;
    }
    if(m==0) cout<<n;
    else cout<<m;
}
int main()
{
    int x,y;
    cout<<"Enter an integers:";
    cin>>x>>y;
    findGcd(x,y);
    return 0;
}