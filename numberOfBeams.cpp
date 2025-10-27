#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        vector<int> v;

        for (auto a : bank) {
            int cnt = 0;
            for (char c : a) {
                if (c == '1') cnt++;
            }
            if (cnt != 0) {
                v.push_back(cnt);
            }
        }

        for (int i = 1; i < v.size(); i++) {
            ans += v[i] * v[i - 1];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<string> bank = {
        "011001",
        "000000",
        "010100",
        "001000"
    };

    int result = sol.numberOfBeams(bank);
    cout << "Number of beams: " << result << endl;

    return 0;
}
