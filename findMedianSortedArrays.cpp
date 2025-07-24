#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums1.begin(), nums1.end());
        for (int num : nums2) {
            temp.push_back(num);
        }
        sort(temp.begin(), temp.end());
        int half = temp.size() / 2;
        if (temp.size() % 2 != 0)
            return temp[half];
        else
            return (double)(temp[half] + temp[half - 1]) / 2.0;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median of merged arrays: " << median << endl;

    return 0;
}
