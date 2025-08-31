#include <iostream>
using namespace std;

class Solution {
public:
    // int minOperations(int n) {
    //     int ans = 0;

    //     if (n % 2 == 0) {
    //         int maxN = ((2 * n) + 1) / 2;
    //         for (int i = 1; i < maxN; i += 2) {
    //             ans += i;
    //         }
    //     } else {
    //         int maxN = ((2 * (n / 2)) + 1);
    //         for (int i = 2; i < maxN; i += 2) {
    //             ans += i;
    //         }
    //     }
    //     return ans;
    // }

    int minOperations(int n) {
        int ans = 0;
        for(int i=1;i<n;i+=2){
            ans += (n-i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 31;

    // cout << "Enter value of n: ";
    // cin >> n;

    int result = sol.minOperations(n);
    cout << "Minimum operations to make array equal: " << result << endl;

    return 0;
}
