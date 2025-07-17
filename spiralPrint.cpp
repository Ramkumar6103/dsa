#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowStart = 0;
        int rowEnd = matrix.size();
        int colStart = 0;
        int colEnd = matrix[0].size();
        while(rowStart < rowEnd && colStart < colEnd){
            // Left to Right
            for(int i=colStart;i<colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            // Top to Down
            for(int i=rowStart;i<rowEnd;i++){
                ans.push_back(matrix[i][colEnd-1]);
            }
            colEnd--;
            // Right to left
            if(rowStart < rowEnd){
                for(int i=colEnd-1;i>=colStart;i--){
                    ans.push_back(matrix[rowEnd-1][i]);
                }
                rowEnd--;
            }
            // Bottom to Up
            if(colStart < colEnd){
                for(int i=rowEnd-1;i>=rowStart;i--){
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> ans = sol.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}