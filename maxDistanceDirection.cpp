#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0, south = 0, east = 0, west = 0;
        int n = s.size();
        int x = 0, y = 0, md = 0, dis = 0, avc = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            x = abs(north - south);
            y = abs(east - west);
            md = x + y;
            avc = min(2 * k, i + 1 - md);
            dis = md + avc;
            ans = max(ans, dis);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string moves = "NSWWEW";
    int k = 3;

    // cout << "Enter move sequence (N/S/E/W): ";
    // cin >> moves;

    // cout << "Enter number of allowed changes (k): ";
    // cin >> k;

    int result = sol.maxDistance(moves, k);
    cout << "Maximum Distance: " << result << endl;

    return 0;
}
