#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    // Create array of size n+1
    vector<int> dp(n + 1);

    // Base case
    dp[0] = 0;

    // Fill dp array
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i / 2] + (i % 2);
    }

    return dp;
}

int main() {
    int n = 5;   // hardcoded input

    vector<int> result = countBits(n);

    cout << "Number of 1s in binary from 0 to " << n << ":\n";

    for (int i = 0; i <= n; i++) {
        cout << "Number " << i << " -> " << result[i] << endl;
    }

    return 0;
}
