#include <iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        int l = low;
        int h = high;
        while(l <= h){
            if((l % 2) == 1) ans++;
            l++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    int low = 3, high = 9;
    cout << "Odd numbers between " << low << " and " << high << " = "
         << sol.countOdds(low, high) << endl;

    // Example 2
    low = 4; high = 10;
    cout << "Odd numbers between " << low << " and " << high << " = "
         << sol.countOdds(low, high) << endl;

    // Example 3
    low = 1; high = 1;
    cout << "Odd numbers between " << low << " and " << high << " = "
         << sol.countOdds(low, high) << endl;

    return 0;
}
