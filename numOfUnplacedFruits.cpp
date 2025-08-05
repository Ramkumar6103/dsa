#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < n) {
            while (j < n && (fruits[i] > baskets[j] || used[j])) {
                j++;
            }
            if (j < n) used[j] = true;
            i++;
            j = 0;
        }
        for (int ns : used) if (!ns) ans++;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {4, 2, 3};
    vector<int> baskets = {3, 5, 2};
    
    int result = sol.numOfUnplacedFruits(fruits, baskets);
    cout << "Number of unplaced fruits: " << result << endl;

    return 0;
}
