#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minEle = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++) {
            minEle = min(minEle, arr[i + 1] - arr[i]);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (minEle == (arr[i] - arr[i - 1])) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    // cout << "Enter number of elements: ";
    // cin >> n;

    vector<int> arr = {4,2,1,3};
    // cout << "Enter elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    vector<vector<int>> result = sol.minimumAbsDifference(arr);

    cout << "Pairs with minimum absolute difference:\n";
    for (auto &pair : result) {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}
