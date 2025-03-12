#include<bits/stdc++.h>
using namespace std;
void countDigit(int n)
{
    cout<<(int)(log10(n)+1);
}
int main()
{
    int n;
    cout<<"Enter an integer:";
    cin>>n;
    countDigit(n);
    return 0;
}