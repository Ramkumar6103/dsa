#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int, int>& p) const {
            return p.first * 31 + p.second;
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int, int>, int, hash_pair> mpp;

        for (auto& d : dominoes) {
            if (d[0] > d[1]) swap(d[0], d[1]);
            mpp[{d[0], d[1]}]++;
        }

        int count = 0;
        for (auto& [d, freq] : mpp)
            count += freq * (freq - 1) / 2;

        return count;
    }
};

int main() {
    vector<vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}, {3, 4}};
    
    Solution sol;
    int result = sol.numEquivDominoPairs(dominoes);
    
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}
