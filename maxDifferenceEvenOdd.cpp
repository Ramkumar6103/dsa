#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

array<vector<int>, 5> freq;
int n;

class Solution {
public:
    // Helper function for computing max difference for a pair (a, b)
    static int maxD_ab(int a, int b, int k) {
        int cnt = INT_MIN;
        const int INF = 1e8;

        // minFreq[x][y] stores min(freq_a - freq_b) where:
        // x = parity of freq_a (0=even, 1=odd)
        // y = parity of freq_b (0=even, 1=odd)
        int minFreq[2][2] = { {INF, INF}, {INF, INF} };

        int freq_a = 0, freq_b = 0, prev_a = 0, prev_b = 0;

        for (int l = 0, r = k - 1; r < n; r++) {
            // Get prefix sums for a and b at position r+1
            freq_a = freq[a][r + 1];
            freq_b = freq[b][r + 1];

            // Shrink window from left to keep at least 2 b's
            while (r - l + 1 >= k && freq_b - prev_b >= 2) {
                minFreq[prev_a & 1][prev_b & 1] = min(minFreq[prev_a & 1][prev_b & 1], prev_a - prev_b);
                prev_a = freq[a][l + 1];
                prev_b = freq[b][l + 1];
                l++;
            }

            // Try updating max difference
            cnt = max(cnt, freq_a - freq_b - minFreq[1 - (freq_a & 1)][freq_b & 1]);
        }

        return cnt;
    }

    static int maxDifference(string& s, int k) {
        n = s.size();
        freq.fill(vector<int>(n + 1, 0));  // 1-indexed prefix sum

        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= 4; d++) {
                freq[d][i + 1] = freq[d][i];
            }
            freq[s[i] - '0'][i + 1]++;
        }

        int ans = INT_MIN;
        for (int a = 0; a <= 4; a++) {
            if (freq[a][n] == 0) continue;  // skip if a not present
            for (int b = 0; b <= 4; b++) {
                if (a == b || freq[b][n] == 0) continue;  // skip if b is same or not present
                ans = max(ans, maxD_ab(a, b, k));
            }
        }

        return ans;
    }
};

int main() {
    string s = "1122211";
    int k = 3;

    // // Example input
    // cout << "Enter string (only digits 0 to 4): ";
    // cin >> s;

    // cout << "Enter k (minimum substring length): ";
    // cin >> k;

    int result = Solution::maxDifference(s, k);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
