#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i); // counts 1's in binary
            if (isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    int left = 6, right = 10;

    int result = sol.countPrimeSetBits(left, right);
    cout << "Count of numbers with prime number of set bits: " << result << endl;

    return 0;
}
