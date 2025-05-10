#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        int i = 0, j = 0;
        while (i < n - 1) {
            j = i + 1;
            while (j < n && prices[i] < prices[j]) {
                j++;
            }
            if (j < n) {
                prices[i] = prices[i] - prices[j];
            }
            i++;
        }
        return prices;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {8, 4, 6, 2, 3}; // Example input
    vector<int> result = sol.finalPrices(prices);

    cout << "Final prices after discount: ";
    for (int price : result) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}
