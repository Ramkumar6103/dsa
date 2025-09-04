#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(x - z) == abs(y - z)) return 0;
        if (abs(x - z) < abs(y - z)) return 1;
        return 2;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    int x1 = 5, y1 = 10, z1 = 7;
    int result1 = sol.findClosest(x1, y1, z1);
    cout << "Closest to " << z1 << " between " << x1 << " and " << y1 << " is: ";
    if (result1 == 0) cout << "Both are equally close" << endl;
    else if (result1 == 1) cout << x1 << endl;
    else cout << y1 << endl;

    int x2 = 3, y2 = 8, z2 = 6;
    int result2 = sol.findClosest(x2, y2, z2);
    cout << "Closest to " << z2 << " between " << x2 << " and " << y2 << " is: ";
    if (result2 == 0) cout << "Both are equally close" << endl;
    else if (result2 == 1) cout << x2 << endl;
    else cout << y2 << endl;

    return 0;
}

