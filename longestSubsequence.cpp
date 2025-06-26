#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cntZeros = 0, cntOnes = 0;
        long long sum = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') cntZeros++;
        }

        int power = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                if(power < 64) {
                    sum += pow(2, power);
                    if(sum <= k) {
                        cntOnes++;
                    } else break;
                } else break;
            }
            power++;
        }

        return cntZeros + cntOnes;
    }
};

int main() {
    Solution sol;
    string s = "1001010";
    int k = 5;

    // cout << "Enter binary string: ";
    // cin >> s;

    // cout << "Enter value of k: ";
    // cin >> k;

    int result = sol.longestSubsequence(s, k);
    cout << "Longest subsequence length: " << result << endl;

    return 0;
}
