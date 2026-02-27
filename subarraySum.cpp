#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int l = 0, sum = 0;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            // Shrink window when sum exceeds target
            while (sum > target && l <= r) {
                sum -= arr[l];
                l++;
            }

            // Target sum found
            if (sum == target) {
                return {l + 1, r + 1}; // 1-based index
            }
        }

        return {-1};
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.subarraySum(arr, target);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}