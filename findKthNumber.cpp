#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Count how many numbers start with 'prefix' and are <= n
    long long countPrefix(long long prefix, long long n) {
        long long count = 0, curr = prefix, next = prefix + 1;
        while (curr <= n) {
            count += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    // Find the k-th smallest number in lexicographical order from 1 to n
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k = k - 1;  // since we start from 1, we reduce k by 1
        while (k > 0) {
            long long cnt = countPrefix(prefix, n);
            if (cnt <= k) {
                prefix++;     // move to next prefix
                k -= cnt;
            } else {
                prefix *= 10; // go deeper in tree (lexical order)
                k--;
            }
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    int n = 13, k = 2;

    // Sample input
    // cout << "Enter value of n: ";
    // cin >> n;
    // cout << "Enter value of k: ";
    // cin >> k;

    int result = sol.findKthNumber(n, k);
    cout << "The " << k << "-th smallest number in lexicographical order is: " << result << endl;

    return 0;
}
