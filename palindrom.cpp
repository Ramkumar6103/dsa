#include<bits/stdc++.h>
using namespace std;
bool printPalindrom(int n)
{
 if(n<0) return false;
 int temp = n;
 int result = 0;
 while(temp)
 {
    result = result * 10 + (temp%10);
    temp = temp / 10;
 }   
 return result == n;
}
int main()
{
    int n;
    cout<<"Enter an integer:";
    cin>>n;
    cout<<printPalindrom(n);
    return 0;
}