#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int factorialRecursive(int n){
        if(n == 1) return 1;
        return n * factorialRecursive(n-1);
    }
};
int main(){
    Solution obj;
    cout<<obj.factorialRecursive(5);
    return 0;
}