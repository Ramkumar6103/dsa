#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int prev = INT_MIN;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j] && prev != nums1[i]) {
                ans.push_back(nums1[i]);
                prev = nums1[i];
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {4, 9, 5, 4};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    Solution sol;
    vector<int> result = sol.intersection(nums1, nums2);

    cout << "Intersection of arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
