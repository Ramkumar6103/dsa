#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cnt = 0;
        int n = 0;
        bool *hit = new bool[k];
        for (int i = 0; i < k; i++) hit[i] = false;
        
        while (true) {
            cnt++;
            n = (n * 10 + 1) % k;
            if (n == 0) return cnt;
            if (hit[n]) return -1;
            hit[n] = true;
        }
    }
};

int main() {
    Solution sol;
    int k = 7;
    // cout << "Enter value of k: ";
    // cin >> k;

    int result = sol.smallestRepunitDivByK(k);
    if (result == -1) {
        cout << "No repunit divisible by " << k << endl;
    } else {
        cout << "Smallest repunit divisible by " << k << " has length: " << result << endl;
    }

    return 0;
}
