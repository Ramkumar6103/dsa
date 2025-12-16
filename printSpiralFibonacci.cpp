#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Generate first n Fibonacci numbers
    vector<long long> getFibonacciNumbers(int n) {
        vector<long long> fib;
        if (n <= 0) return fib;

        fib.push_back(0);
        if (n == 1) return fib;

        fib.push_back(1);
        for (int i = 2; i < n; i++) {
            fib.push_back(fib[i - 1] + fib[i - 2]);
        }
        return fib;
    }

public:
    void printSpiralFibonacci(int n) {
        vector<long long> fib = getFibonacciNumbers(n);

        // Find matrix size (smallest square)
        int sq = ceil(sqrt(n));

        vector<vector<long long>> mat(sq, vector<long long>(sq, -1));

        int top = 0, bottom = sq - 1;
        int left = 0, right = sq - 1;
        int idx = 0;

        // Spiral filling
        while (top <= bottom && left <= right && idx < n) {

            for (int i = left; i <= right && idx < n; i++)
                mat[top][i] = fib[idx++];
            top++;

            for (int i = top; i <= bottom && idx < n; i++)
                mat[i][right] = fib[idx++];
            right--;

            for (int i = right; i >= left && idx < n; i--)
                mat[bottom][i] = fib[idx++];
            bottom--;

            for (int i = bottom; i >= top && idx < n; i--)
                mat[i][left] = fib[idx++];
            left++;
        }

        // Print the matrix
        cout << "Spiral Fibonacci Matrix:\n";
        for (int i = 0; i < sq; i++) {
            for (int j = 0; j < sq; j++) {
                if (mat[i][j] == -1)
                    cout << setw(5) << " ";
                else
                    cout << setw(5) << mat[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 10;
    obj.printSpiralFibonacci(n);
    return 0;
}
