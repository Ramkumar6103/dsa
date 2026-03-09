#include<bits/stdc++.h>
using namespace std;
// class Solution {
//     public:
//         long MOD = 1e9+7;
//         long countGoodNumbers(long n) {
//             long odd = n/2;
//             long even = (n+1)/2;
//             return (int)(pow(5,even) * pow(4,odd) % MOD);
//         }
//         long pow(long x, long n){
            
//             // Base case for the recursion
//             if(n==0) 
//                 return 1;
            
//             // Recursively calculate x^(n/2)
//             long temp = pow(x,n/2);
            
//             // If n is even, return (x^(n/2))^2
//             if(n%2==0){
//                 return (temp * temp)% MOD;
//             }
//             // If n is odd, return (x^(n/2))^2 * x
//             else{
//                 return (x * temp * temp)% MOD;
//             }
//         }
//     };


class Solution {
public:
    long MOD = 1e9+7;
    int countGoodNumbers(long n) {
        long odd = n/2;
        long even = (n+1)/2;
        return (int)(pow(5,even) * pow(4,odd) % MOD);
    }
    long pow(long x, long n){
        long temp = n;
        long ans = 1;
        while(temp){
            if(temp % 2 == 1){
                ans = (ans * x) % MOD;
                temp = temp - 1;
            }
            else{
                x = (x * x) % MOD;
                temp = temp / 2;
            }
        }
        return ans % MOD;
    }
};
    int main(){
        long n = 5;
        Solution obj;
        cout<<"Count of good numbers: "<<obj.countGoodNumbers(n);
        return 0;
    }