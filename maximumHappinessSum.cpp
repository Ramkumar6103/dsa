#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long sum = 0;
        int n = h.size();
        sort(h.begin(), h.end(), greater<int>()); // sort descending
        for (int i = 0; i < k; i++) {
            int happy = h[i] - i; // reduce by index
            if (happy <= 0) break; // stop if non-positive
            sum += happy;
        }
        return sum;
    }
};

int main() {
    // Example 1
    {
        int n = 5, k = 3;
        vector<int> h = {5, 3, 9, 2, 8};
        Solution sol;
        cout << "Example 1:\n";
        cout << "Input: n = " << n << ", k = " << k << ", h = {5,3,9,2,8}\n";
        cout << "Output: " << sol.maximumHappinessSum(h, k) << "\n\n";
    }

    // Example 2
    {
        int n = 4, k = 2;
        vector<int> h = {1, 2, 3, 4};
        Solution sol;
        cout << "Example 2:\n";
        cout << "Input: n = " << n << ", k = " << k << ", h = {1,2,3,4}\n";
        cout << "Output: " << sol.maximumHappinessSum(h, k) << "\n\n";
    }

    // Example 3
    {
        int n = 6, k = 4;
        vector<int> h = {10, 10, 10, 10, 10, 10};
        Solution sol;
        cout << "Example 3:\n";
        cout << "Input: n = " << n << ", k = " << k << ", h = {10,10,10,10,10,10}\n";
        cout << "Output: " << sol.maximumHappinessSum(h, k) << "\n\n";
    }

    return 0;
}
