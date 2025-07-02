#include <iostream>
#include <unordered_map>

class Solution {
public:                                     // Approach 1

    // int climbStairs(int n, std::unordered_map<int, int>& memo) {
    //     if (n == 0 || n == 1) {
    //         return 1;
    //     }
    //     if (memo.find(n) == memo.end()) {
    //         memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
    //     }
    //     return memo[n];
    // }

    // int climbStairs(int n) {
    //     std::unordered_map<int, int> memo;
    //     return climbStairs(n, memo);
    // }    
                                            //Approach 2

    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main() {
    Solution sol;
    int n = 3;

    // std::cout << "Enter the number of stairs: ";
    // std::cin >> n;

    int ways = sol.climbStairs(n);
    std::cout << "Number of distinct ways to climb " << n << " stairs: " << ways << std::endl;

    return 0;
}

