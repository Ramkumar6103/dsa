#include <iostream>
#include <bitset>
#include <cstdint> // ✅ Required for uint32_t

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = ans << 1;
            if (n & 1) {
                ans = ans | 1;
            }
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    uint32_t input = 43261596; // Example input
    uint32_t reversed = sol.reverseBits(input);

    cout << "Original:  " << bitset<32>(input) << " (" << input << ")" << endl;
    cout << "Reversed:  " << bitset<32>(reversed) << " (" << reversed << ")" << endl;

    return 0;
}
