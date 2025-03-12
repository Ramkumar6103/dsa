#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
        for (int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << " ";
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;  // Number of initialized elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = nums2.size();
    obj.mergeSortedArray(nums1, m, nums2, n);
    return 0;
}
