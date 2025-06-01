#include <iostream>
using namespace std;

class Solution {
public:
    // long long distributeCandies(int n, int limit) {          // Approach 1
    //     long long ans = 0;
    //     for (int i = 0; i <= limit; i++) {
    //         for (int j = 0; j <= limit; j++) {
    //             for (int k = 0; k <= limit; k++) {
    //                 if ((i + j + k) == n) {
    //                     ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    //     long long distributeCandies(int n, int limit) {       // Approach 2
    //     long long ans = 0;
    //     for(int i=0;i<=limit;i++){
    //         for(int j=0;j<=limit;j++){
    //             int k = (n-i-j);
    //             if(k >= 0 && k <= limit) ans++;
    //         }
    //     }
    //     return ans;
    // }
                                                                // Approach 3
        long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i=0;i<=min(n,limit);i++){
            int rem = n-i;
            if(rem > 2*limit) continue;
            int j = max(0,rem-limit);
            int k = min(rem,limit);
            ans += k - j + 1;
        }
        return ans;
    }
};

int main() {
    int n = 5;
    int limit = 2;

    Solution sol;
    long long ways = sol.distributeCandies(n, limit);
    cout << "Number of ways to distribute candies: " << ways << endl;

    return 0;
}
