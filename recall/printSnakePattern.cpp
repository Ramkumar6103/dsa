#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSnakePattern(vector<vector<int>>& nums) {
        if (nums.empty()) return;
        int n = nums.size();
        int m = nums[0].size();
        for(int j=0;j<n;j++){
            if(j % 2 == 0){
                for(int i=0;i<m;i++){
                    cout<<nums[j][i]<<" ";
                }
            }
            else{
                for(int i=m-1;i>=0;i--){
                    cout<<nums[j][i]<<" ";
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     cout<<nums[0][i]<<" ";
        // }
        // for(int i=m-1;i>=0;i--){
        //     cout<<nums[1][i]<<" ";
        // }
        // for(int i=0;i<m;i++){
        //     cout<<nums[2][i]<<" ";
        // }
    }
};

int main() {
    Solution obj;
    // int n, m;

    // cout << "Enter number of rows and columns: ";
    // cin >> n >> m;

    // vector<vector<int>> nums(n, vector<int>(m));

    // cout << "Enter matrix elements:\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> nums[i][j];
    //     }
    // }

    // 🔹 Hardcoded 2D array
    vector<vector<int>> nums = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "\nSnake Pattern:\n";
    obj.printSnakePattern(nums);

    return 0;
}
