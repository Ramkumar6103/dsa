#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int x = numExchange;
        int emptyB = numBottles;
        while (x <= emptyB) {
            emptyB -= x;
            ans++;
            x++;
            emptyB++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    int numBottles = 9;
    int numExchange = 3;

    int result = sol.maxBottlesDrunk(numBottles, numExchange);
    cout << "Maximum bottles drunk: " << result << endl;

    return 0;
}
