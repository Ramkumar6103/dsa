#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombination(int ind, vector<int>& cand, int target,
                         vector<vector<int>>& ans, vector<int>& ds) {

        // Base case
        if (ind == cand.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick the current element (if possible)
        if (cand[ind] <= target) {
            ds.push_back(cand[ind]);
            findCombination(ind, cand, target - cand[ind], ans, ds);
            ds.pop_back(); // backtrack
        }

        // Not pick the current element
        findCombination(ind + 1, cand, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, cand, target, ans, ds);
        return ans;
    }
};

int main() {
    Solution obj;

    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> cand(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> cand[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = obj.combinationSum(cand, target);

    cout << "\nCombinations are:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
