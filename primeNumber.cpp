#include <iostream>
#include <vector>
using namespace std;
// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
// Function to find all prime numbers within a range
vector<int> findPrimes(int start, int end) {
    vector<int> primes;
    for (int num = start; num <= end; ++num) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}
int main() {
    int start = 10, end = 50;
    vector<int> primes = findPrimes(start, end);

    cout << "Prime numbers between " << start << " and " << end << " are: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
