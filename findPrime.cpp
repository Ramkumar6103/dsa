#include<bits/stdc++.h>
using namespace std;
bool findPrime(int n)
{
    for(int i=n-1;i>2;i--)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter an integer:";
    cin>>n;
    cout<<findPrime(n);
    return 0;
}