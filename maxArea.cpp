#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Optimized two-pointer approach
    // int maxArea(vector<int>& height) {
    //     int n = height.size();
    //     int area = 0;
    //     int ans = 0;
    //     for(int i = 0; i < n - 1; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             area = (j - i) * min(height[i], height[j]);
    //             ans = max(area, ans);
    //         }
    //     }
    //     return ans;
    // }

        int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int l = 0;
        int r = n-1;
        while(l < r){
            maxArea = max(((r - l) * min(height[r], height[l])),maxArea);
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
            
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Call the function and print the result
    int result = sol.maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}
