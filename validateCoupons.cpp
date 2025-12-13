#include <bits/stdc++.h>
using namespace std;

const array<string, 4> categories = {
    "electronics",
    "grocery",
    "pharmacy",
    "restaurant"
};

class Solution {
public:
    static bool isValidCode(const string& s) noexcept {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }

    static vector<string> validateCoupons(
        const vector<string>& code,
        const vector<string>& businessLine,
        const vector<bool>& isActive) noexcept
    {
        int n = code.size();
        vector<int> valid;

        for (int i = 0, cid = -1; i < n; ++i) {
            if (isActive[i] &&
                (cid = find(categories.begin(), categories.end(),
                            businessLine[i]) - categories.begin()) < 4 &&
                isValidCode(code[i])) {

                // pack index + category
                valid.push_back(i | (cid << 8));
            }
        }

        sort(valid.begin(), valid.end(), [&code](int a, int b) {
            int catDiff = (a >> 8) - (b >> 8);
            if (catDiff != 0)
                return catDiff < 0;
            return code[a & 255] < code[b & 255];
        });

        vector<string> validCodes;
        for (int v : valid) {
            validCodes.push_back(code[v & 255]);
        }
        return validCodes;
    }
};

int main() {
    // Sample test case
    vector<string> code = {
        "SAVE_10", "OFF20", "BAD@CODE", "FOOD5", "MED_30"
    };

    vector<string> businessLine = {
        "electronics", "grocery", "electronics", "restaurant", "pharmacy"
    };

    vector<bool> isActive = {
        true, true, true, false, true
    };

    vector<string> result =
        Solution::validateCoupons(code, businessLine, isActive);

    cout << "Valid Coupons:\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}
