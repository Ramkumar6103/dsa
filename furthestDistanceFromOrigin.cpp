#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int r = 0;
        int l = 0;
        int rs = 0;
        for(char m : moves){
            if(m == 'R') r++;
            else if(m == 'L') l++;
            else if(m == '_') rs++;
        }
        if(l > r){
            cout << l << " " << r << " " << rs << endl;  // debug output
            if(r == 0) return n;
            return rs + (l - r);
        }
        else if(l < r) {
            cout << l << " " << r << " " << rs << endl;  // debug output
            if(l == 0) return n;
            return rs + (r - l);
        }
        return n - (r + l);
    }
};

int main() {
    Solution sol;
    string moves = "L_RL__R";
    // cout << "Enter moves string (use R, L, _): ";
    // cin >> moves;

    int result = sol.furthestDistanceFromOrigin(moves);
    cout << "Furthest distance from origin: " << result << endl;

    return 0;
}
