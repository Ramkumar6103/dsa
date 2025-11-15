#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();

        // positions of zeros
        vector<int> zero;
        for (int i = 0; i < n; ++i)
            if (s[i] == '0') zero.push_back(i);

        int Z = zero.size();
        long long ans = 0;

        // Case A: substrings with 0 zeros -> count all substrings inside each run of '1'
        long long run = 0;
        for (char c : s) {
            if (c == '1') run++;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;

        // Case B: substrings with z >= 1 zeros
        int maxZ = (int)floor(sqrt(n)) + 2;
        for (int z = 1; z <= maxZ; ++z) {
            if (z > Z) break;
            for (int i = 0; i + z - 1 < Z; ++i) {
                int leftZero = zero[i];
                int rightZero = zero[i + z - 1];

                int need = z * z;

                int leftBound = (i == 0 ? -1 : zero[i - 1]);
                int leftFree = leftZero - leftBound - 1;

                int rightBound = (i + z < Z ? zero[i + z] : n);
                int rightFree = rightBound - rightZero - 1;

                int internalOnes = (rightZero - leftZero + 1) - z;

                int rem = need - internalOnes;
                if (rem <= 0) {
                    ans += 1LL * (leftFree + 1) * (rightFree + 1);
                    continue;
                }

                if (leftFree + rightFree + 2 < rem) continue;

                long long count = 0;
                for (int L = 0; L <= leftFree; ++L) {
                    int minR = rem - L;
                    if (minR <= 0) minR = 0;
                    if (minR > rightFree) continue;
                    count += (rightFree - minR + 1);
                }
                ans += count;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "1101001";
    // cout << "Enter binary string: ";
    // cin >> s;

    long long result = sol.numberOfSubstrings(s);
    cout << "Number of valid substrings: " << result << endl;

    return 0;
}
