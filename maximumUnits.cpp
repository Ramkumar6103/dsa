#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;

        // Sort by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), [](auto &x, auto &y){
            return x[1] > y[1];
        });

        for(int i = 0; i < boxTypes.size(); i++) {
            if(truckSize == 0) break;

            int take = min(truckSize, boxTypes[i][0]);
            ans += take * boxTypes[i][1];
            truckSize -= take;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> boxTypes = {{1,3}, {2,2}, {3,1}};
    int truckSize = 4;

    int result = sol.maximumUnits(boxTypes, truckSize);
    cout << "Maximum units on the truck: " << result << endl;

    return 0;
}
