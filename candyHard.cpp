#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int candy(vector<int>& ratings, int cnt = 0) {
    //     int n = ratings.size();
    //     vector<int> candies(n, 1);

    //     // Forward pass
    //     for (int i = 1; i < n; i++) 
    //         if (ratings[i] > ratings[i - 1])
    //             candies[i] = candies[i - 1] + 1;

    //     // Backward pass
    //     for (int i = n - 1; i > 0; i--) {
    //         if (ratings[i - 1] > ratings[i])
    //             candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
    //         cnt += candies[i - 1];
    //     }
    //     return cnt + candies[n - 1];
    // }

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);  // Step 1: Initialize with 1

        // Step 2: Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        // Step 3: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                count[i] = max(count[i], count[i + 1] + 1);
            }
        }

        // Step 4: Total candies
        return accumulate(count.begin(), count.end(), 0);
    }
};

int main() {
    vector<int> ratings = {1, 2, 4, 2, 1};  // Example input
    Solution sol;
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
