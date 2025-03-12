#include<bits/stdc++.h>
using namespace std;
void printDivision(int n)
{
    vector<int> v1;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            v1.push_back(i);
            if(n/i!=i)
            {
            v1.push_back(n/i);
            }
        }
        
    }
    sort(v1.begin(),v1.end());
        for(auto it : v1)
        {
            cout<<it<<" ";
        }
}
int main()
{
    int n;
    cout<<"Enter an integer:";
    cin>>n;
    printDivision(n);
    return 0;
}
