#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for (int i = 0 ; i < arr.size() - 2 ; i++) {
            if (arr[i] & 1 && arr[i + 1] & 1 && arr[i + 2] & 1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 5, 7, 8, 9, 11, 13}; // Sample test case
    if (sol.threeConsecutiveOdds(arr)) {
        cout << "The array contains three consecutive odd numbers.\n";
    } else {
        cout << "The array does not contain three consecutive odd numbers.\n";
    }
    return 0;
}
