#include <iostream>
using namespace std;

// Function to compute nCr (combinations)
int nCr(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main() {
    int n = 4, r = 2;
    // cout << "Enter values for n and r: ";
    // cin >> n >> r;

    if (r > n || n < 0 || r < 0) {
        cout << "Invalid input: r must be ≤ n and both should be non-negative." << endl;
    } else {
        int result = nCr(n, r);
        cout << "nCr(" << n << ", " << r << ") = " << result << endl;
    }

    return 0;
}
