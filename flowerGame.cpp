#include <iostream>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * n * m / 2;
    }
};

int main() {
    Solution sol;

    // Sample input
    int n = 5;
    int m = 7;

    long long result = sol.flowerGame(n, m);
    cout << "Number of games with different parity: " << result << endl;

    return 0;
}
