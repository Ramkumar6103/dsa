#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        if(n <= 1) return 0;

        for(int i = 2; i < n; i++) {
            bool isPrime = true;
            for(int j = 2; j <= sqrt(i); j++) {  // fixed condition & increment
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) cnt++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    int n = 10;

    // cout << "Enter a number: ";
    // cin >> n;

    int result = sol.countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << result << endl;

    return 0;
}
