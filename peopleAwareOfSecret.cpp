#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long share = 0, MOD = 1000000007;

        for (int t = 2; t <= n; t++) {
            if (t - delay > 0) {
                share = (share + dp[t - delay] + MOD) % MOD;
            }
            if (t - forget > 0) {
                share = (share - dp[t - forget] + MOD) % MOD;
            }
            dp[t] = share;
        }

        long long known = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            known = (known + dp[i]) % MOD;
        }

        return (int)known;
    }
};

int main() {
    Solution sol;

    // Sample test case
    int n = 10;
    int delay = 2;
    int forget = 4;

    int result = sol.peopleAwareOfSecret(n, delay, forget);
    cout << "Number of people aware of the secret on day " << n << ": " << result << endl;

    return 0;
}
