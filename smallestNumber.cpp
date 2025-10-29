#include <iostream>

class Solution {
public:
    int smallestNumber(unsigned n) {
        // Manual bit_ceil implementation
        if (n == 0) return 0;
        n += 1;
        unsigned power = 1;
        while (power < n) {
            power <<= 1;
        }
        return power - 1;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    unsigned test1 = 5;
    unsigned test2 = 15;
    unsigned test3 = 0;

    std::cout << "smallestNumber(" << test1 << ") = " << sol.smallestNumber(test1) << std::endl;
    std::cout << "smallestNumber(" << test2 << ") = " << sol.smallestNumber(test2) << std::endl;
    std::cout << "smallestNumber(" << test3 << ") = " << sol.smallestNumber(test3) << std::endl;

    return 0;
}
