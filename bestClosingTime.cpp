#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        // Initial penalty: count all 'Y'
        for (char ch : customers) {
            if (ch == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Move closing time from 1 to n
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // no longer closed on a 'Y'
            } else { // 'N'
                penalty++;   // open but no customers
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};

int main() {
    Solution sol;

    string customers = "YYNY";   // hard-coded input
    int result = sol.bestClosingTime(customers);

    cout << "Best closing hour: " << result << endl;

    return 0;
}
