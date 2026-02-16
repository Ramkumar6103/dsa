#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int fibonacci(int n){
        if(n == 0 || n == 1) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};
int main(){
    Solution obj;
    cout<<obj.fibonacci(6);
    return 0;
}