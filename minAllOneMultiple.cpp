#include <iostream>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int remainder = 0;

        for (int length = 1; length <= k; length++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0)
                return length;
        }

        return -1;
    }
};

int main() {
    // Inbuilt input
    int k = 3;

    Solution obj;
    int result = obj.minAllOneMultiple(k);

    if (result == -1)
        cout << "No such number exists" << endl;
    else
        cout << "Minimum length of all-ones multiple: " << result << endl;

    return 0;
}
