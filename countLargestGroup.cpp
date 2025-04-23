#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int maxi = INT_MIN;
        int ds = 0;
        unordered_map<int, int> mpp(40);
        for (int i = 1; i <= n; i++) {
            ds = digitSum(i);
            mpp[ds]++;
            maxi = max(maxi, mpp[ds]);
        }
        int ans = 0;
        for (int i = 0; i < 40; i++) {
            if (maxi == mpp[i]) ans++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 13;

    int result = solution.countLargestGroup(n);
    cout << "Number of groups with largest size: " << result << endl;

    return 0;
}
