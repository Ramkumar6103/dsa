#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         stack<int> st;
//         int ans = 0;

//         for (int num : nums) {
//             while (!st.empty() && num < st.top()) {
//                 st.pop();  // Invalidate larger numbers for current context
//             }
//             if (st.empty() || num > st.top()) {
//                 if (num > 0) ans++;
//                 st.push(num);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        bool change = false;
        for (int i = 0; i < nums.size(); i++) {
            bool change = false;
            bool first = false;
            int temp = nums[i];
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == temp && nums[j] != 0) {
                    if(i == j) first = true;
                    nums[j] = 0;
                    change = true;
                } else if (nums[j] == 0) {
                    if(first){
                        break;
                    }
                    change = false;
                    break;
                }
            }
            if (change) cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 2, 2, 3, 2, 4, 5};

    // Call the function and print the result
    int result = sol.minOperations(nums);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
