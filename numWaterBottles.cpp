#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int b, int n) {
        return b + (b - 1) / (n - 1);
    }
};

int main() {
    Solution sol;

    int bottles = 9;      // Initial full bottles
    int exchange = 3;     // Number of empty bottles needed for one full bottle

    int result = sol.numWaterBottles(bottles, exchange);

    cout << "Total bottles drunk: " << result << endl;

    return 0;
}
