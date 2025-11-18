#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int x = 0, y = arr.size() - 1;
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                ans.push_back(arr[y]);
                y--;
            } else {
                ans.push_back(arr[x]);
                x++;
            }
        }
        return ans;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Sample input
    vector<int> input = {1, 3, 2, 2, 5, 4};

    cout << "Original array: ";
    printVector(input);

    vector<int> result = sol.alternateSort(input);

    cout << "Alternate sorted array: ";
    printVector(result);

    return 0;
}
