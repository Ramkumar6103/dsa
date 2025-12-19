#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans = {{}, {}};

        // Create sets with elements of the vectors
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        // For every element in set A that is not present in set B
        for (auto x : s1) 
            if (!s2.count(x)) ans[0].push_back(x);

        // For every element in set B that is not present in set A
        for (auto x : s2) 
            if (!s1.count(x)) ans[1].push_back(x);

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    // Call the function
    vector<vector<int>> result = sol.findDifference(nums1, nums2);

    // Print the result
    cout << "Unique elements in nums1 not in nums2: ";
    for (int x : result[0]) cout << x << " ";
    cout << "\n";

    cout << "Unique elements in nums2 not in nums1: ";
    for (int x : result[1]) cout << x << " ";
    cout << "\n";

    return 0;
}
