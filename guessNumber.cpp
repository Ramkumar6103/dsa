#include <iostream>

using namespace std;

// Mock implementation of the guess function
// Assume the target number is 6 for demonstration purposes
int target = 6;

int guess(int num) {
    if (num == target) return 0;
    else if (num > target) return -1;
    else return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 10; // Example upper bound
    cout << "The guessed number is: " << sol.guessNumber(n) << endl;
    return 0;
}
