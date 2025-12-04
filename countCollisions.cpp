#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string d) {
        int ans = 0;
        int n = d.size();
        int i = 0;

        // Remove leading L's
        while(i < n && d[i] == 'L') 
            i++;

        int j = n - 1;

        // Remove trailing R's
        while(j >= 0 && d[j] == 'R') 
            j--;

        // Count collisions inside the middle segment
        for(int k = i; k <= j; k++) {
            if(d[k] == 'L' || d[k] == 'R')
                ans++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string directions = "LLRSLLRSRR";
    // cout << "Enter directions string: ";
    // cin >> directions;

    int collisions = obj.countCollisions(directions);

    cout << "Total collisions: " << collisions << endl;

    return 0;
}
