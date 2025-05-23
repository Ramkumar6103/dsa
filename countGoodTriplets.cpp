#include <iostream>
#include <vector>
#include <cmath> // For abs() function
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7, b = 2, c = 3;

    // Output for example input
    int result = solution.countGoodTriplets(arr, a, b, c);

    cout << "Example input: [3, 0, 1, 1, 9, 7]" << endl;
    cout << "a = 7, b = 2, c = 3" << endl;
    cout << "The number of good triplets is: " << result << endl;

    return 0;
}
