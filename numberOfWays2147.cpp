#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string c) {
        const int MOD = 1e9 + 7;

        int seats = 0;
        for (char ch : c) {
            if (ch == 'S') seats++;
        }

        // If total seats is odd or zero → impossible
        if (seats == 0 || seats % 2 != 0) return 0;

        long long ans = 1;
        int seatCount = 0;
        int plants = 0;
        bool countingPlants = false;

        for (char ch : c) {
            if (ch == 'S') {
                seatCount++;

                // Finished one group of 2 seats
                if (seatCount % 2 == 0) {
                    countingPlants = true;
                    plants = 0;
                }
                // Starting next group → multiply choices
                else if (seatCount > 2) {
                    ans = (ans * (plants + 1)) % MOD;
                    countingPlants = false;
                }
            }
            else if (ch == 'P' && countingPlants) {
                plants++;
            }
        }

        return ans;
    }
};

int main() {
    string s = "SPPSSSSPPS";
    // cout << "Enter the garden string (S/P): ";
    // cin >> s;

    Solution sol;
    int result = sol.numberOfWays(s);

    cout << "Number of ways: " << result << endl;
    return 0;
}
