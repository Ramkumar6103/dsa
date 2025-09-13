#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int smallestAbsentPositive(vector<int>& nums) {
    double avg = 0;
    for (int num : nums) avg += num;
    avg /= nums.size();

    unordered_set<int> present(nums.begin(), nums.end());

    int candidate = 1; // Start from 1 to ensure we check all positive integers
    while (true) {
        if (candidate > avg && present.find(candidate) == present.end())
            return candidate;
        candidate++;
    }
}

int main() {
    vector<vector<int>> testCases = {
        {3, 5},
        {-1, 1, 2},
        {4, -1},
        {-34}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        for (int num : nums) cout << num << " ";
        cout << "\nOutput: " << smallestAbsentPositive(nums) << "\n\n";
    }

    return 0;
}
