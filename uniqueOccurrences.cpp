#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp; // To count occurrences of each number
        for (int a : arr) {
            mpp[a]++;
        }
        unordered_set<int> s; // To store the counts
        for (auto m : mpp) {
            s.insert(m.second); // Insert the occurrences into the set
        }
        return mpp.size() == s.size(); // Check if sizes match (all counts are unique)
    }
};

int main() {
    // Example usage
    Solution solution;

    // Example input
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    // Check if the occurrences are unique
    if (solution.uniqueOccurrences(arr)) {
        cout << "The occurrences are unique." << endl;
    } else {
        cout << "The occurrences are not unique." << endl;
    }

    return 0;
}
