#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        vector<int> ans(n, 1); // dry lake 1 by default
        unordered_map<int, int> rainDay; // lake -> last rain day
        rainDay.reserve(n);
        set<int> dry; // dry days

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry.insert(i); // dry day
            } else {
                const int lake = rains[i];
                const auto it0 = rainDay.find(lake);
                if (it0 != rainDay.end()) {
                    int prev = it0->second;
                    // find dry day after prev
                    auto it = dry.lower_bound(prev);
                    if (it == dry.end()) return {}; // no dry day available
                    int d = *it;
                    ans[d] = lake; // dry this lake on day d
                    dry.erase(it); // dry day used
                }
                rainDay[lake] = i;
                ans[i] = -1; // rainy day
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> rains = {1, 2, 0, 0, 2, 1}; // Sample input
    vector<int> result = sol.avoidFlood(rains);

    if (result.empty()) {
        cout << "Flood cannot be avoided." << endl;
    } else {
        cout << "Avoid flood plan: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
