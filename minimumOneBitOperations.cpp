#include <iostream>
using namespace std;

int minimumOneBitOperations(int n) {
    if (n <= 1)
        return n;
    int bit = 0;
    while ((1 << bit) <= n)
        bit++;
    return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit - 1)));
}

int main() {
    int n = 3;
    // cout << "Enter an integer n: ";
    // cin >> n;

    int result = minimumOneBitOperations(n);
    cout << "Minimum number of operations to convert " << n << " to 0: " << result << endl;

    return 0;
}
