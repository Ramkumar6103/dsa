#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int prevMax = neededTime[0];
        
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                totalCost += min(prevMax, neededTime[i]);
                prevMax = max(prevMax, neededTime[i]);
            } else {
                prevMax = neededTime[i];
            }
            cout << "Step " << i << ": TotalCost = " << totalCost << endl;
        }
        
        return totalCost;
    }
};

int main() {
    string colors = "aaabbabbbb";
    vector<int> neededTime = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};


    Solution sol;
    int result = sol.minCost(colors, neededTime);

    cout << "\nMinimum total cost to remove adjacent duplicates: " << result << endl;
    return 0;
}
