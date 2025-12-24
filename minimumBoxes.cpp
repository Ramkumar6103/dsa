#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        int n = capacity.size();
        int temp = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;
            temp += capacity[i];
            if (temp >= sum) {
                return cnt;
            }
        }
        return sum; // fallback, though logically shouldn't reach here
    }
};

int main() {
    // Example input
    vector<int> apple = {1, 2, 3};       // total apples = 6
    vector<int> capacity = {3, 3, 3, 3}; // box capacities

    Solution sol;
    int result = sol.minimumBoxes(apple, capacity);

    cout << "Apples: ";
    for (int a : apple) cout << a << " ";
    cout << "\nCapacities: ";
    for (int c : capacity) cout << c << " ";
    cout << "\nMinimum number of boxes required = " << result << "\n";

    return 0;
}
