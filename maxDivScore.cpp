#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& numbers, vector<int>& divisors) {
        int maxDivisibleCount = 0;       // maximum count of divisible numbers
        int bestDivisor = INT_MAX;       // divisor with highest score (smallest if tie)

        for (int i = 0; i < divisors.size(); i++) {
            int currentDivisor = divisors[i];
            int divisibleCount = 0;

            // Count how many numbers are divisible by currentDivisor
            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[j] % currentDivisor == 0) {
                    divisibleCount++;
                }
            }

            // Update best divisor if we found a higher score
            if (divisibleCount > maxDivisibleCount) {
                maxDivisibleCount = divisibleCount;
                bestDivisor = currentDivisor;
            }
            // If tie, choose the smaller divisor
            else if (divisibleCount == maxDivisibleCount) {
                bestDivisor = min(bestDivisor, currentDivisor);
            }
        }

        return bestDivisor;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> numbers = {12, 18, 24, 36};
    vector<int> divisors = {2, 3, 6, 12};

    int result = solution.maxDivScore(numbers, divisors);

    cout << "The divisor with maximum divisible count is: " << result << endl;

    return 0;
}
