#include <bits/stdc++.h>
using namespace std;

int getSecondSmallest(vector<int> &arr) {

    if (arr.size() < 2)
        return -1;   // Not possible

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX)
        return -1;   // No second smallest (all same elements)

    return secondSmallest;
}

int main() {
    vector<int> arr = {3, 9, 1, 8, 2, 7, 4};

    cout << "The array elements are: ";
    for (auto it : arr) {
        cout << it << " ";
    }

    cout << "\nSecond smallest element: " << getSecondSmallest(arr);
    return 0;
}
