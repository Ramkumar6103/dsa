#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0) return 0;

//         sort(nums.begin(), nums.end());

//         int maxCnt = 1;
//         int cnt = 1;

//         for(int i = 1; i < nums.size(); i++) {

//             while(i < nums.size() && (nums[i-1] + 1 == nums[i] || nums[i-1] == nums[i])) {

//                 if(nums[i-1] != nums[i]) {
//                     cnt++;
//                 }

//                 i++;
//             }

//             maxCnt = max(cnt, maxCnt);

//             if(i < nums.size() && !(nums[i-1] + 1 == nums[i])) {
//                 cnt = 1;
//             }
//         }

//         return maxCnt;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int count = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i-1]) {
                continue;
            }

            if(nums[i] == nums[i-1] + 1) {
                count++;
            } else {
                longest = max(longest, count);
                count = 1;
            }
        }

        return max(longest, count);
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.longestConsecutive(nums);

    cout << "Longest Consecutive Sequence Length: " << result << endl;

    return 0;
}