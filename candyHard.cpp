#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings, int cnt = 0) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Forward pass
        for (int i = 1; i < n; i++) 
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        // Backward pass
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            cnt += candies[i - 1];
        }
        return cnt + candies[n - 1];
    }
};

int main() {
    vector<int> ratings = {1, 2, 4, 2, 1};  // Example input
    Solution sol;
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
